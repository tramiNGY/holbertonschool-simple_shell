#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "shell.h"

/**
 * process_command - handle the command put into the terminal with childprocess
 * @command: string entered by the user
 * @head: pointer to the head of a list
 * @env: environment variable
 */

void process_command(char *command, list_t *head, char **env)
{
	char **args = NULL;
	char *exe_path;
	pid_t child_pid;
	int status;

	if (strlen(command) == 0)
		return;
	args = _strtok(command);
	exe_path = get_full_path(args[0], head);
	if (exe_path != NULL)
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			if (execve(exe_path, args, env) == -1)
			{
				perror("./shell");
				free(command);
				free(args);
				exit(1);
			}
		}
		else if (child_pid < 0)
		{
			perror("fork");
		}
		else
		{
			waitpid(child_pid, &status, 0);
		}
	}
	else
	{
		perror("Command not found");
	}

	free(args);
}
