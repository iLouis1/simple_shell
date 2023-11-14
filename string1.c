#include "shell.h"

/**
 * _strcpy - Will copy a string
 * @dest: Destination
 * @src: The source
 *
 * Return: pointer to destination
 */

char *_strcpy(char *dest, char *src)
{
	int x = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[x])
	{
		dest[x] = src[x];
		x++;
	}
	dest[x] = 0;
	return (dest);
}

/**
 * _strdup - This will duplicate strings
 * @str: The string to be duplicated
 *
 * Return: Pointer to the duplicated string
 */

char *_strdup(const char *str)
{
	char *ret;
	int length = 0;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 *_puts - Will print the input string
 *@str: This is the string to be printed
 *
 * Return: Nothing
 */

void _puts(char *str)
{
	int x = 0;

	if (!str)
		return;
	while (str[x] != '\0')
	{
		_putchar(str[x]);
		x++;
	}
}

/**
 * _putchar - This will write the character c to stdout
 * @c: Character to be printed
 *
 * Return: On success 1.
 * return -1 on error, and errno is set appropriately.
 */

int _putchar(char c)
{
	static int x;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(1, buf, x);
		x = 0;
	}
	if (c != BUF_FLUSH)
		buf[x++] = c;
	return (1);
}
