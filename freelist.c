#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "shell.h"

/**
 * free_list - free the memory allocated to a list
 * @head: pointer to the head of a list
 */

void free_list(list_t *head)
{
	list_t *temp;
	list_t *next;

	temp = head;
	while (temp != NULL)
	{
		next = temp->next;
		free(temp->str);
		free(temp);
		temp = next;
	}
}
