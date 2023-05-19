#include "shell.h"

/**
 * _meputs - prints a string
 * @str: string to be printed
 * Return: nothing
 */
void _meputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_meputchar(str[i]);
		i++;
	}
}

/**
 * _meputchar - writes char c to stderr
 * @c: char to print
 * Return: success 1, error -1
 */
int _meputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _meputfd - write char c to given fd
 * @c: char to print
 * @fd: filedescriptor to write to
 * Return: success 1, error -1
 */
int _meputfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _meputsfd - prints input string
 * @str: string to print
 * @fd: filedescriptor to write to
 * Return: number of chars
 */
int _meputsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _meputfd(*str++, fd);
	}
	return (i);
}
