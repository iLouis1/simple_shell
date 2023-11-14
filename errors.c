#include "shell.h"

/**
 *_eputs - This prints an input string
 * @str: String to be printed
 *
 * Return: Nothing
 */

void _eputs(char *str)
{
	int x = 0;

	if (!str)
		return;
	while (str[x] != '\0')
	{
		_eputchar(str[x]);
		x++;
	}
}

/**
 * _eputchar - Will write the character c to stderr
 * @c: The character to be printed
 *
 * Return: 1 on success.
 * On error, return -1, and errno is set appropriately.
 */

int _eputchar(char c)
{
	static int x;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(2, buf, x);
		x = 0;
	}
	if (c != BUF_FLUSH)
		buf[x++] = c;
	return (1);
}

/**
 * _putfd - Will write the character c to given fd
 * @c: The character to be printed
 * @fd: The file descriptor to write to
 *
 * Return: 1 on success.
 * On error, return -1, and errno is set appropriately.
 */

int _putfd(char c, int fd)
{
	static int x;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(fd, buf, x);
		x = 0;
	}
	if (c != BUF_FLUSH)
		buf[x++] = c;
	return (1);
}

/**
 *_putsfd - This prints an input string
 * @str: String to be printed
 * @fd: File descriptor to write to
 *
 * Return: Number of characters put
 */

int _putsfd(char *str, int fd)
{
	int x = 0;

	if (!str)
		return (0);
	while (*str)
	{
		x += _putfd(*str++, fd);
	}
	return (x);
}
