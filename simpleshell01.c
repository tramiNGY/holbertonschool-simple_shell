#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

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
 * @command: string  to be split with space delimiter
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
 * Return: 0 if success
 */
int main(int argc, char **argv)
{
	int status;
	char *command;
	extern char **environ;
	char **args;
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
		args = _strtok(command);
		child_pid = fork();
		if (child_pid == 0)
		{
			if (execve(args[0], args, environ) == -1)
			{
				perror("./shell");
				free(command);
				free(args);
				exit(1);
			}
		}
		else if (child_pid < 0)
			perror("fork");
		else
			waitpid(child_pid, &status, 0);
		free(command);
		free(args);
	}
	return (0);
}
