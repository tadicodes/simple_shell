#include "shell.h"

/**
 **_strcopy - copy string
 *@dest: destination for string
 *@src: source string
 *@n: amount of chars to copy
 *Return: concatenated string
 */
char *_strcopy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strcon - concatenate two strings
 *@dest: first string
 *@src: second string
 *@n: amount of bytes to use
 *Return: concatenated string
 */
char *_strcon(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 **_strchar - locate char in string
 *@s: string to be parsed
 *@c: character to look for
 *Return: (s) pointer to memory area s
 */
char *_strchar(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');
	return (NULL);
}
