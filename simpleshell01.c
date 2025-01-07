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
 * exec_ve - exec command
 * @argv: list of argument
 * Return: 0 if success
 */
int exec_ve(char **argv)
{
	execve(argv[0], argv, NULL);
	return (0);
}
/**
 * main - execute command or print error message
 * @argc: number of arguments
 * @argv: list of argument
 * Return: 0 if success
 */
int main(int argc, char **argv)
{
	int status;
	char *command;
	(void) argc;
	status = 1;
	while (status)
	{
		command = readline();
		argv[0] = command;
		argv[1] = NULL;
		if (execve(argv[0], argv, NULL) == -1)
		{
			printf("./shell: No such file or directory\n");
			free(command);
		}
		else
			exec_ve(argv);

	}
	free(command);
	return (0);
}
