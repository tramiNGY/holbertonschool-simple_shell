#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
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
	(void) argc;

	argv[0] = readline();
	argv[1] = NULL;
	if (execve(argv[0], argv, NULL) == -1)
	{
		printf("./shell: No such file or directory");
		exit(0);
		return (-1);
	}
	else
		execve(argv[0], argv, NULL);
	return (0);
}
