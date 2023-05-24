#include "shell.h"

/**
 * _mehistory - displays the history list
 * @info: structure with potential arguments
 *  Return: 0
 */
int _mehistory(info_t *info)
{
	prints_list(info->history);
	return (0);
}

/**
 * unset_alias - set alias to string
 * @info: the parameter struct
 * @str: string alias
 * Return: 0 success, 1 error
 */
int unset_alias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
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
 * set_alias - set alias to string
 * @info: the parameter struct
 * @str: string alias
 * Return: 0 success, 1 error
 */
int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
<<<<<<< HEAD
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
=======
		return (us_alias(info, str));
	us_alias(info, str);
	return (plus_node_end(&(info->alias), str, 0) == NULL);
>>>>>>> ad36e473b27100ceabff0b76c8bcbf20afad3c3b
}

/**
 * print_alias - print alias string
 * @node: the alias node
 * Return: 0 success, 1 error
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
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
 * _mealias - mimics alias builtin (man alias)
 * @info: structure with potential arguments
 *  Return: 0
 */
int _mealias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
<<<<<<< HEAD
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
=======
			p_alias(node_start_with(info->alias, info->argv[i], '='));
>>>>>>> ad36e473b27100ceabff0b76c8bcbf20afad3c3b
	}

	return (0);
}
