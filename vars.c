#include "shell.h"

/**
 * is_chain - Tests if current char in buffer is a chain delimeter
 * @info: Parameter struct
 * @buf: char buffer
 * @p: Address of current position in buf
 *
 * Return: 1 if chain delimeter, 0 otherwise
 */

int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t j = *p;
	char current_char = buf[j];
	char next_char = buf[j + 1];

	if ((current_char == '|' && next_char == '|') ||
	(current_char == '&' && next_char == '&'))
{
	buf[j] = '\0';
	j++;
	info->cmd_buf_type = (current_char == '|') ? CMD_OR : CMD_AND;
	}
		else if (current_char == ';')
	{
		buf[j] = '\0';
		info->cmd_buf_type = CMD_CHAIN;
	}
		else
	{
	return (0);
}

	*p = j;
	return (1);
}

/**
 * check_chain - checks if to continue chaining based on last status
 * @info: Parameter struct
 * @buf: char buffer
 * @p: The address of current position in buf
 * @i: The starting position in buf
 * @len: buf length
 *
 * Return: Void
 */

void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if ((info->cmd_buf_type == CMD_AND && info->status) ||
			(info->cmd_buf_type == CMD_OR && !info->status))
	{
		buf[i] = '\0';
		j = len;
	}

	*p = j;
}

/**
 * replace_alias - Will replace an alias in the tokenized string
 * @info: Parameter struct
 *
 * Return: 0 otherwise, 1 if replaced
 */

int replace_alias(info_t *info)
{
	int x;
	list_t *node;
	char *p;

	for (x = 0; x < 10; x++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}

/**
 * replace_vars - Will replace vars in the tokenized string
 * @info: Parameter struct
 *
 * Return: 0 otherwise, 1 if replaced
 */

int replace_vars(info_t *info)
{
	int x = 0;
	list_t *node;

	for (x = 0; info->argv[x]; x++)
	{
		if (info->argv[x][0] != '$' || !info->argv[x][1])
			continue;

		if (!_strcmp(info->argv[x], "$?"))
		{
			replace_string(&(info->argv[x]),
				_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[x], "$$"))
		{
			replace_string(&(info->argv[x]),
				_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[x][1], '=');
		if (node)
		{
			replace_string(&(info->argv[x]),
				_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[x], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - replaces string
 * @old: address of old string
 * @new: new string
 *
 * Return: 1 if replaced, 0 otherwise
 */

int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
