#include "shell.h"

/**
 * _meenv - put out the current envi
 * @info: Structure with potential args
 * Return: 0
 */
int _meenv(info_t *info)
{
	print_list_str(info->env);

	return (0);
}

/**
 * _getenv - gets value of environ variable
 * @info: structure with potential args
 * @name: environ var name
 * Return: value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mesetenv - initialize a new environ var
 * @info: structure with potential args
 *  Return: 0
 */
int _mesetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _meunsetenv - remove environment var
 * @info: structure with potential args
 * Return: 0
 */
int _meunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * populate_env_list - populates the env linked list
 * @info: structure with potential args
 * Return: 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;

	return (0);
}
