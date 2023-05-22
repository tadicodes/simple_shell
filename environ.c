#include "shell.h"

/**
 * _menv - prints environment
 * @info: contains potential arguments
 * Return: 0
 */
int _menv(info_t *info)
{
	pr_list_str(info->env);
	return (0);
}

/**
 * _genv - gets value of env variable
 * @info: contains potential arguments
 * @name: env variable name
 * Return: value
 */
char *_genv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = start_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _msenv - initialize or modify env variable
 * @info: contains potential arguments
 *  Return: 0
 */
int _msenv(info_t *info)
{
	if (info->argc != 3)
	{
		_meputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenvi(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _munsenv - remove variable
 * @info: contains potential arguments
 * Return: 0
 */
int _munsenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_meputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenvi(info, info->argv[i]);
	return (0);
}

/**
 * pop_env_list - populate env ist
 * @info: contains potential arguments
 * Return: 0
 */
int pop_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		plus_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
