#include "shell.h"

/**
 * _strlen - Will return the length of a string
 * @s: This is the string whose length to check
 *
 * Return: The integer length of string
 */

int _strlen(char *s)
{
	int x = 0;

	if (!s)
		return (0);

	while (*s++)
		x++;
	return (x);
}

/**
 * _strcmp - Will perform lexicogarphic comparison of two strangs.
 * @s1: First strang
 * @s2: Second strang
 *
 * Return: Negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - checks if needle starts with haystack
 * @haystack: The string to search
 * @needle: Substring to find
 *
 * Return: The address of next char of haystack or NULL
 */

char *starts_with(const char *haystack, const char *needle)
{
	while (*needle != '\0')
	{
		if (*needle++ != *haystack++)
			return (NULL);
	}
	return ((char *)haystack);
}

/**
 * _strcat - This concatenates two strings
 * @dest: Buffer destination
 * @src: The buffer source
 *
 * Return: This is pointer to destination buffer
 */

char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;

	while
		((*dest++ = *src++));

	return (ret);
}
