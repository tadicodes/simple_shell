#include "shell.h"

/**
 * _strlen - returns the leng of string
 * @s: the string with length to check
 * Return: int length of string
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)

		return (0);

	while (*s++)
		i++;

	return (i);
}

/**
 * _strcmp - doess lexicogarphic comparison of two strangs.
 * @s1: the first strang
 * @s2: second string
 * Return: minus if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - check if needle starts with haystack
 * @haystack: the string to search
 * @needle: substring to find
 * Return: addy of next char of haystack
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - concatenates 2 strings
 * @dest: destination buffer
 * @src: the src buffer
 * Return: pointer to dest buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;

	return (ret);
}
