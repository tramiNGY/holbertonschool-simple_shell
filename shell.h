#ifndef SHELL_H
#define SHELL_H

/**
 * struct list_T - singly linked list
 * @str: string
 * @len: length
 * @next: point to the next node
 */

typedef struct list_T
{
	char *str;
	unsigned int len;
	struct list_T *next;
} list_t;
void set_path_var(char *path_var, list_t **head);
list_t *add_node_end(list_t **head, const char *str);
void free_list(list_t *head);
void process_command(char *command, list_t *head, char **env);
char **_strtok(char *command);
char *get_full_path(char *command, list_t *head);
#endif
