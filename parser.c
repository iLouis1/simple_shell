#include "shell.h"

/**
 * is_cmd - Will determine if a file is an executable command
 * @info: Info structure
 * @path: The file path
 *
 * Return: 0 otherwise, 1 if true
 */

int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if
		(st.st_mode & S_IFREG)
		return (1);

	return (0);
}


/**
 * dup_chars - Will duplicate characters
 * @pathstr: This is the PATH string
 * @start: The starting index
 * @stop: The stopping index
 *
 * Return: The new buffer pointer
 */

char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int x = 0, k = 0;

	for (k = 0, x = start; x < stop; x++)
		if (pathstr[x] != ':')
			buf[k++] = pathstr[x];
	buf[k] = 0;
	return (buf);
}

/**
 * find_path - Will find this cmd in the PATH string
 * @info: Info structure
 * @pathstr: This is the PATH string
 * @cmd: The cmd to find
 *
 * Return: full path of cmd if found or NULL
 */

char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int x = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[x] || pathstr[x] == ':')
		{
			path = dup_chars(pathstr, curr_pos, x);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[x])
				break;
			curr_pos = x;
		}
		x++;
	}
	return (NULL);
}
