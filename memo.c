#include "shell.h"

/**
 * bfree - free a pointer and NULL address
 * @ptr: address of pointer to free
 * Return: 1 freed, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;

		return (1);
	}

	return (0);
}
