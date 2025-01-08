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
 * main - execute command or print error message
 * @argc: number of arguments
 * @argv: list of arguments
 * Return: 0 if success
 */
int main(int argc, char **argv)
{
	int status, i;
	char *command, *token;
	pid_t child_pid;
	char *args[64];

	(void) argc;
	(void) argv;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");
		command = readline();
		if (command == NULL)
			break;
		i = 0;
		token = strtok(command, " ");
		while (token != NULL)
		{
			args[i] = token;
			i++;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;
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
	}
	return (0);
}
