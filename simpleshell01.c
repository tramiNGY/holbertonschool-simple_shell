#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
/**
 * main - execute the commands from the prompt
 * Return: 0
 */
int main(void)
{
	int status;
	char *buffer;
	char *argv[2];
	pid_t child_pid;
	size_t size;

	size = 32;
	buffer = malloc(sizeof(char) * size);
	if (buffer == NULL)
		return (-1);
	argv[0] = buffer;
	argv[1] = NULL;
	printf("#cisfun$ ");
	getline(&buffer, &size, stdin);
	child_pid = fork();
	if (child_pid == 0)
	{
		if (argv[0] == NULL)
		{
			printf("buffer is NULL\n");
			free(buffer);
			return (-1);
		}
		else
			execve(argv[0], argv, NULL);
	}
	else
		wait(&status);
	free(buffer);
	return (0);
}
