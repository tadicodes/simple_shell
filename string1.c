#include "shell.h"

/**
 * _strcpy - copy string
 * @dest: destination
 * @src: the sourc
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;

	return (dest);
}

/**
 * _strdup - dupe a string
 * @str: the string to dupe
 * Return: pointer to the dupe string
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;

	return (ret);
}

/**
 * _puts - printz an input string
 * @str: string to prin
 * Return: non
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)

		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _putchar - writes the char c to stdout
 * @c: le char to print
 * Return: success 1 on error, -1 and errno is set
 */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;

	return (1);
}
