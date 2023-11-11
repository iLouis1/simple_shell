#include "shell.h"

/**
 * bfree - Will free a pointer, NULLs the address
 * @ptr: The address of the pointer to free
 *
 * Return: 0 if otherwise, 1 if freed.
 */

int bfree(void **ptr)
{
	if (ptr == NULL || *ptr == NULL)
	{
		return (0);
	}

	free(*ptr);
	*ptr = NULL;
	return (1);
}
