#include "shell.h"

/**
 * _myenv - This will print the current environment
 * @info: The structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: 0 always
 */

int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - This gets the value of an environ variable
 * @info: The structure containing potential arguments.
 * @name: The env var name
 *
 * Return: The value
 */

char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - This initializes a new environment variable,
 *             or modifies an existing one
 * @info: The structure containing potential arguments.
 *
 *  Return: Always 0
 */

int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - This will remove an environment variable
 * @info: The structure containing potential arguments.
 *
 *  Return: 0 Always
 */

int _myunsetenv(info_t *info)
{
	int x;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (x = 1; x <= info->argc; x++)
		_unsetenv(info, info->argv[x]);

	return (0);
}

/**
 * populate_env_list - Will populate env linked list
 * @info: The structure containing potential arguments.
 *
 * Return: Always 0
 */

int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t x;

	for (x = 0; environ[x]; x++)
		add_node_end(&node, environ[x], 0);
	info->env = node;
	return (0);
}
