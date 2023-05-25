#include "shell.h"

/**
 * interactive - true if shell is in interactive mode
 * @info: struct address
 * Return: 1 if interactive, 0 if not
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * its_delim - see if char is a delimeter
 * @c: char to check
 * @delim: delimeter string
 * Return: 1 if true, 0 if not
 */
int its_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _itsalpha - sees if char is alphabetic
 * @c: char to input
 * Return: 1 if char is alphabetic, 0 if not
 */
int _itsalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - convert the string to int
 * @s: string to convert
 * Return: 0 for no numbers in string, otherwise converted number
 */
int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
