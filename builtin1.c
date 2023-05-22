#include "shell.h"

/**
 * _mehistory - displays history list
 * @info: contains potential arguments
 *  Return: 0
 */
int _mehistory(info_t *info)
{
	prints_list(info->history);
	return (0);
}

/**
 * us_alias - set alias to string
 * @info: parameter struct
 * @str: string alias
 * Return: 0 success, 1 error
 */
int us_alias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchar(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = del_node_at_index(&(info->alias),
		g_node_index(info->alias, node_start_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * s_alias - set alias to string
 * @info: parameter struct
 * @str: string alias
 * Return: 0 success, 1 error
 */
int s_alias(info_t *info, char *str)
{
	char *p;

	p = _strchar(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (us_alias(info, str));
	us_alias(info, str);
	return (plus_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * p_alias - prints alias string
 * @node: alias node
 * Return: 0 success, 1 error
 */
int p_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchar(node->str, '=');
		for (a = node->str; a <= p; a++)
		_putchar(*a);
		_putchar('\'');
		_putss(p + 1);
		_putss("'\n");
		return (0);
	}
	return (1);
}

/**
 * _malias - mimics alias builtin
 * @info: contains potential arguments
 *  Return: 0
 */
int _malias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			p_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchar(info->argv[i], '=');
		if (p)
			s_alias(info, info->argv[i]);
		else
			p_alias(node_start_with(info->alias, info->argv[i], '='));
	}
	return (0);
}
