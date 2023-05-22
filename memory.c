#include "shell.h"

/**
 * befree - this frees a pointer and NULLs the address
 * @ptr: the address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */
int befree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
