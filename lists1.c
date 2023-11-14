#include "shell.h"

/**
 * list_len - The length of linked list
 * @h: The pointer to first node
 *
 * Return: The size of list
 */

size_t list_len(const list_t *h)
{
	size_t x = 0;

	while (h)
	{
		h = h->next;
		x++;
	}
	return (x);
}

/**
 * list_to_strings - Will return an array of strings of the list->str
 * @head: The pointer to first node
 *
 * Return: The array of strings
 */

char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t x = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !x)
		return (NULL);
	strs = malloc(sizeof(char *) * (x + 1));
	if (!strs)
		return (NULL);
	for (x = 0; node; node = node->next, x++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < x; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[x] = str;
	}
	strs[x] = NULL;
	return (strs);
}


/**
 * print_list - Will print all elements of a list_t linked list
 * @h: The pointer to first node
 *
 * Return: The size of list
 */

size_t print_list(const list_t *h)
{
	size_t x = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		x++;
	}
	return (x);
}

/**
 * node_starts_with - Will return node which string starts with prefix
 * @node: The pointer to head of list
 * @prefix: The string to match
 * @c: Next character after prefix to match
 *
 * Return: null or match node
 */

list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - This wiill get the index of a node
 * @head: The pointer to head of list
 * @node: The pointer to the node
 *
 * Return: -1 or index of node
 */

ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t x = 0;

	while (head)
	{
		if (head == node)
			return (x);
		head = head->next;
		x++;
	}
	return (-1);
}
