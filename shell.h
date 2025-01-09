#ifndef SHELL_H
#define SHELL_H

typedef struct list_T
{
	char *str;
	unsigned int len;
	struct list_T *next;
} list_t;

#endif
