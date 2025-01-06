#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
/**
 * main - execute the commands from the prompt
 * Return: 0
 */
int main(void)
{
	int status, i, length;
	char *buffer, *argv[2], *list = "/bin/ls";
	pid_t child_pid;
	size_t size;

	size = 32;
	buffer = malloc(sizeof(char) * size);
	if (buffer == NULL)
		return (-1);
	argv[0] = buffer;
	argv[1] = NULL;

	while (list[length] != '\0')
		length++;

	printf("#cisfun$ ");
	getline(&buffer, &size, stdin);
	buffer[strcspn(buffer, "\n")] = 0;
	child_pid = fork();
	if (child_pid == 0)
	{
		i = 0;
		while (argv[0][i] == list[i])
			i++;
		if (i == length + 1)
			execve(argv[0], argv, NULL);

		else
		{
			printf("./shell: No such file or directory\n");
			free(buffer);
			return (-1);
		}
	}
	else
		wait(&status);
	free(buffer);
	return (0);
}
