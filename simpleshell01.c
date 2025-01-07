#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
/**
 * readline - read prompt
 * Return: buffer or null
 */
char *readline(void)
{
	char *buffer;
	size_t size;

	size = 32;
	buffer = malloc(sizeof(char) * size);
	if (buffer == NULL)
		return (NULL);
	printf("#cisfun$ ");
	getline(&buffer, &size, stdin);
	buffer[strcspn(buffer, "\n")] = 0;
	return (buffer);
}
/**
 * main - execute command or print error message
 * @argc: number of arguments
 * @argv: list of argument
 * Return: 0 if success
 */
int main(int argc, char **argv)
{
	int one, status;
	char *command;
	pid_t child_pid;
	(void) argc;
	one = 1;
	while (one)
	{
		command = readline();
		argv[0] = command;
		argv[1] = NULL;
		child_pid = fork();
		if (child_pid == 0)
		{
		if (execve(argv[0], argv, NULL) == -1)
		{
			printf("./shell: No such file or directory\n");
			free(command);
		}
		else
			waitpid(child_pid, &status, 0);
		}
	}
	return (0);
}
