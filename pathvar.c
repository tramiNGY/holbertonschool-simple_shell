#include "shell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

/**
 * set_path_var - tokenize a list
 * @path_var: list of directories
 * @head: pointer to the head of the linked list of  directories
 */

void set_path_var(char *path_var, list_t **head)
{
	char *copy, *token;

	if (path_var)
	{
		copy = strdup(path_var);
		token = strtok(copy, ":");
		while (token != NULL)
		{
			add_node_end(head, token);
			token = strtok(NULL, ":");
		}
		free(copy);
	}
}
