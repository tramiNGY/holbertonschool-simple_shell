#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "shell.h"

/**
 * add_node_end - add a new node to the end of the list
 * @head: double pointer to the start of the list
 * @str: string to add
 * Return: the new node
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *newnode;
	list_t *tempnode;
	unsigned int length = 0;

	while (str[length] != '\0')
		length++;
	newnode = malloc(sizeof(list_t));
	if (newnode == NULL)
		return (NULL);
	newnode->str = strdup(str);
	if (newnode->str == NULL)
	{
		free(newnode);
		return (NULL);
	}
	newnode->len = length;
	newnode->next = NULL;
	if (*head == NULL)
		*head = newnode;
	else
	{
		tempnode = *head;
		while (tempnode->next != NULL)
			tempnode = tempnode->next;
		tempnode->next = newnode;
	}
	return (newnode);
}

/**
 * get_full_path - search for an executable in directories listed in PATH
 * @command: the command to search for
 * @head: list of directories
 * Return: path to the executable or NULL if not found
 */

char *get_full_path(char *command, list_t *head)
{
	char *fullpath;
	struct stat buffer;
	list_t *temp = head;

	if (command[0] == '/')
	{
		if (stat(command, &buffer) == 0)
			return (command);
	}

	while (temp != NULL)
	{
		fullpath = malloc(strlen(temp->str) + strlen(command) + 2);
		if (!fullpath)
		{
			perror("malloc");
			exit(1);
		}
		sprintf(fullpath, "%s/%s", temp->str, command);

		if (stat(fullpath, &buffer) == 0)
		{
			return (fullpath);
		}
		free(fullpath);
		temp = temp->next;
	}

	return (NULL);
}

/**
 * readline - read a line from stdin
 * Return: buffer or NULL
 */

char *readline(void)
{
	char *buffer = NULL;
	size_t size = 0;

	if (getline(&buffer, &size, stdin) == -1)
	{
		free(buffer);
		return (NULL);
	}
	buffer[strcspn(buffer, "\n")] = 0;
	return (buffer);
}

/**
 * _strtok - splits command in arguments
 * @command: string to be split with space delimiter
 * Return: pointer to an array of pointers to arguments
 */

char **_strtok(char *command)
{
	int i;
	char *token;
	char **args;

	args = malloc(sizeof(char *) * 64);
	if (args == NULL)
	{
		perror("malloc");
		exit(1);
	}

	token = strtok(command, " ");
	i = 0;
	while (token != NULL)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
	return (args);
}

/**
 * main - execute command or print error message
 * @argc: number of arguments
 * @argv: list of arguments
 * @env: environment variable
 * Return: 0 if success
 */

int main(int argc, char **argv, char **env)
{
	int i;
	char *command;
	list_t *head = NULL;
	(void)argc, (void)argv;
	for (i = 0; env[i] != NULL; i++)
	{
		if (strncmp(env[i], "PATH=", 5) == 0)
		{
			set_path_var(&env[i][5], &head);
			break;
		}
	}
	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf(":) ");
		command = readline();
		if (command == NULL)
			break;
		if (command[0] == 'e' && command[1] == 'x'
		&& command[2] == 'i' && command[3] == 't')
			break;
		if (strlen(command) == 0)
			continue;
		process_command(command, head, env);
		free(command);
	}
	free_list(head);
	return (0);
}
