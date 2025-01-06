#include <stddef.h>
#include <stdio.h>
#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

char *str_tok(char *prompt)
{
	char *token, *last_token;

	token = strtok(prompt, "/");
	while (token != NULL)
	{
		last_token = token;
		token = strtok(NULL, "/");
	}

	return (last_token);
}
int compare(char *prompt)
{
	char *temp;
	int i, length, match;
	DIR *dir = opendir("/bin/");
	struct dirent *entry;

	temp = str_tok(prompt);

	while (temp[length] != '\0')
		length++;

	if (dir == NULL) {
		printf ("error");
	}
	while ((entry = readdir(dir)) != NULL)
	{
		i = 0;
		match = 1;

		while (temp[i] == entry->d_name[i])
			i++;
		if (i == length + 1)
			match = 0;

		entry->d_name;
	}
	closedir(dir);
	return (match);
}

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
		if (compare(argv[0]) == 0)
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
