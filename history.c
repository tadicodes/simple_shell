#include "shell.h"

/**
 * get_hist_file - gets the history file
 * @info: parameter struct
 * Return: string containing history file
 */

char *get_hist_file(info_t *info)
{
	char *buf, *dir;

	dir = _genv(info, "HOME=");
	if (!dir)
		return (NULL);
	buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	_strcpy(buf, dir);
	_strcat(buf, "/");
	_strcat(buf, HIST_FILE);
	return (buf);
}

/**
 * write_hist - creates file or appends to file
 * @info: parameter struct
 * Return: 1 success, else -1
 */
int write_hist(info_t *info)
{
	ssize_t fd;
	char *filename = get_hist_file(info);
	list_t *node = NULL;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		_meputsfd(node->str, fd);
		_meputfd('\n', fd);
	}
	_meputfd(BUF_FLUSH, fd);
	close(fd);
	return (1);
}

/**
 * read_hist - reads history
 * @info: parameter struct
 * Return: histcount on success, else 0
 */
int read_hist(info_t *info)
{
	int i, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = get_hist_file(info);

	if (!filename)
		return (0);
	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(fd, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(fd);
	for (i = 0; i < fsize; i++)
		if (buf[i] == '\n')
		{
			buf[i] = 0;
			build_hist_list(info, buf + last, linecount++);
			last = i + 1;
		}
	if (last != i)
		build_hist_list(info, buf + last, linecount++);
	free(buf);
	info->histcount = linecount;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);
	renumber_hist(info);
	return (info->histcount);
}

/**
 * build_hist_list - add entry to history linked list
 * @info: contains potential arguments
 * @buf: buffer
 * @linecount: histcount
 * Return: Always 0
 */

int build_hist_list(info_t *info, char *buf, int linecount)
{
	list_t *node = NULL;

	if (info->history)
		node = info->history;
	add_node_end(&node, buf, linecount);

	if (!info->history)
		info->history = node;
	return (0);
}

/**
 * renumber_hist - renumbers history linked list
 * @info: contains potential arguments
 * Return: new histcount
 */
int renumber_hist(info_t *info)
{
	list_t *node = info->history;
	int i = 0;

	while (node)
	{
		node->num = i++;
		node = node->next;
	}
	return (info->histcount = i);
}
