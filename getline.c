#include "shell.h"

/**
<<<<<<< HEAD
 * input_buf - buffer chained command
 * @info: parameter structure
 * @buf: address for buffer
 * @len: address for len var
 * Return: bytes
=======
 * inp_buf - buffers chained commands
 * @info: for the parameter struct
 * @buf: for the address of buffer
 * @len: for the address of len var
 *
 * Return: for the bytes read
>>>>>>> ad36e473b27100ceabff0b76c8bcbf20afad3c3b
 */
ssize_t inp_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*len) /* if nothing left, fill */
	{
		/*bfree((void **)info->cmd_buf);*/
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		r = getline(buf, &len_p, stdin);
#else
		r = _getline(info, buf, &len_p);
#endif
		if (r > 0)
		{
			if ((*buf)[r - 1] == '\n')
			{
				(*buf)[r - 1] = '\0';
				r--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_hist_list(info, *buf, info->histcount++);
			/* if (_strchr(*buf, ';')) is this a command chain? */
			{
				*len = r;
				info->cmd_buf = buf;
			}
		}
	}

	return (r);
}

/**
<<<<<<< HEAD
 * get_input - gets line minus newline
 * @info: parameter structure
 * Return: bytes
=======
 * get_inp - gets a line minus the newline
 * @info: for parameter struct
 *
 * Return: for bytes read
>>>>>>> ad36e473b27100ceabff0b76c8bcbf20afad3c3b
 */
ssize_t get_inp(info_t *info)
{
	static char *buf; /* the ';' command chain buffer */
	static size_t i, j, len;
	ssize_t r = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	r = inp_buf(info, &buf, &len);
	if (r == -1) /* EOF */
		return (-1);
	if (len)
	{
		j = i;
		p = buf + i; /* get pointer for return */

		check_chain(info, buf, &j, i, len);
		while (j < len) /* iterate to semicolon or end */
		{
			if (is_chain(info, buf, &j))
				break;
			j++;
		}

		i = j + 1; /* increment past nulled ';'' */
		if (i >= len) /* reached end of buffer? */
		{
			i = len = 0; /* reset position and length */
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p; /* pass back pointer to current command position */
		return (_strlen(p));
	}

	*buf_p = buf;
	return (r);
}

/**
<<<<<<< HEAD
 * read_buf - reads abuffer
 * @info: parameter structure
 * @buf: buffer
 * @i: size
 * Return: r
=======
 * r_buf - reads a buffer
 * @info: for parameter struct
 * @buf: for buffer
 * @i: for size
 *
 * Return: for r
>>>>>>> ad36e473b27100ceabff0b76c8bcbf20afad3c3b
 */
ssize_t r_buf(info_t *info, char *buf, size_t *i)
{
	ssize_t r = 0;

	if (*i)
		return (0);
	r = read(info->readfd, buf, READ_BUF_SIZE);
	if (r >= 0)
		*i = r;
	return (r);
}

/**
<<<<<<< HEAD
 * _getline - gets next line of input
 * @info: parameter structure
 * @ptr: address of pointer to buffer
 * @length: size of buffer
=======
 * _gline - gets the next line of input from STDIN
 * @info:is the parameter struct
 * @ptr: is the address of pointer to buffer, preallocated or NULL
 * @length: is the size of preallocated ptr buffer if not NULL
 *
>>>>>>> ad36e473b27100ceabff0b76c8bcbf20afad3c3b
 * Return: s
 */
int _gline(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t i, len;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		s = *length;
	if (i == len)
		i = len = 0;

	r = r_buf(info, buf, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = _strchar(buf + i, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(p, s, s ? s + k : k + 1);
	if (!new_p) /* MALLOC FAILURE! */
		return (p ? free(p), -1 : -1);

	if (s)
		_strcon(new_p, buf + i, k - i);
	else
		_strcopy(new_p, buf + i, k - i + 1);

	s += k - i;
	i = k;
	p = new_p;

	if (length)
		*length = s;
	*ptr = p;

	return (s);
}
<<<<<<< HEAD

/**
 * sigintHandler - blocks ctrl-C
 * @sig_num: signal number
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
=======
>>>>>>> ad36e473b27100ceabff0b76c8bcbf20afad3c3b
