#include "shell.h"

/**
 **_memset - This fills memory with constant byte
 *@s: Pointer to the memory area
 *@b: Byte to fill *s with
 *@n: Amount of bytes to be filled
 *Return: (s) a pointer to the memory area s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int x;

	for (x = 0; x < n; x++)
		s[x] = b;
	return (s);
}

/**
 * ffree - This frees a string of strings
 * @pp: A string of strings
 */

void ffree(char **pp)
{
	if (!pp)
	{
		return;
	}

	char **temp = pp;

	while
		(*pp)
	{
		free(*pp++);
	}

	free(temp);
}

/**
 * _realloc - This reallocates a block of memory
 * @ptr: Pointer to previous malloc'ated block
 * @old_size: The byte size of previous block
 * @new_size: This is the byte size of new block
 *
 * Return: Pointer to da ol'block nameen.
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
