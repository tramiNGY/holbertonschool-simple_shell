#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "shell.h"

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
 * _getenv - replica of getenv function which get an environment variable
 * @name: name of the environment variable to get
 * @env: environment variable
 * Return: pointer to the environment variable
 */
char *_getenv(const char *name, char **env)
{
	int i, j;
	int status;

	for (i = 0; env[i] != NULL; i++)
	{
		status = 1;
		for (j = 0; env[i][j] != '='; j++)
		{
			if (name[j] != env[i][j])
			{
				status = 0;
				break;
			}
		}
		if (status)
		{
			return (&env[i][j + 1]);
		}
	}
	return (NULL);
}

/**
 * get_full_path - get absolute path of command
 * @command: command alone without full path
 * @env: environment variable
 * Return: returns absolute path to command
*/

char *get_full_path(char *command, char **env)
{
	char *path = _getenv("PATH", env);
	char *dir = strtok(path, ":");
	char *full_path = NULL;
	struct stat buffer;

	if (command[0] == '/')
	{
		full_path = strdup(command);
		return (full_path);
	}
	while (dir != NULL)
	{
		full_path = malloc(strlen(dir) + strlen(command) + 2);
		if (full_path == NULL)
		{
			perror("malloc");
			return (NULL);
		}
		sprintf(full_path, "%s/%s", dir, command);
		if (stat(full_path, &buffer) == 0)
		{
			return (full_path);
		}
		free(full_path);
		full_path = NULL;
		dir = strtok(NULL, ":");
	}
	return (NULL);
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
	int status, i;
	char *command, *token, *args[64];
	pid_t child_pid;
	(void) argc, (void) argv;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf(":) ");
		command = readline();
		if (command == NULL)
			break;
		if (strlen(command) == 0)
			continue;
		i = 0;
		token = strtok(command, " ");
		while (token != NULL)
		{
			args[i] = token;
			i++;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;
		if (args[0][0] != '/')
			args[0] = get_full_path(args[0], env);
		child_pid = fork();
		if (child_pid == 0)
		{
			if (execve(args[0], args, NULL) == -1)
			{
				perror("./shell");
				free(command);
				exit(1);
			}
		}
		else if (child_pid < 0)
			perror("fork");
		else
			waitpid(child_pid, &status, 0);
		free(command);
	} return (0);
}
