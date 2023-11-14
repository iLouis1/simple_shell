#include "shell.h"

/**
 * get_environ - Will return the string array copy of our environ
 * @info: Struct containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: 0 Always
 */

char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * _unsetenv - This will emove an environment variable
 * @info: Struct containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: 0 otherwise, 1 on delete
 * @var: String env var property
 */

int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t x = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), x);
			x = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		x++;
	}
	return (info->env_changed);
}

/**
 * _setenv - This will Initialize a new environment variable,
 *             or modify any existing
 * @info: Struct containing potential arguments. Used to maintain
 *        constant function prototype.
 * @var: String env var property
 * @value: String env var value
 *  Return: 0 Always
 */

int _setenv(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
			_strcpy(buf, var);
			_strcat(buf, "=");
			_strcat(buf, value);
			node = info->env;
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
		add_node_end(&(info->env), buf, 0);
		free(buf);
		info->env_changed = 1;
	return (0);
}
