#include "shell.h"

/**
 * _meenv - print current environment
 * @info: structure with potential arguments
 * Return: 0
 */
int _meenv(info_t *info)
{
	pr_list_str(info->env);
	return (0);
}

/**
 * _getenv - gets value of environ variable
 * @info: structure with potential arguments
 * @name: env variable name
 * Return: value
 */
char *_getenv(info_t *info, const char *name)
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
 * _mesetenv - initialize new environment variable
 * @info: structure with potential arguments
 *  Return: Always 0
 */
int _mesetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenvi(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _meunsetenv - remove environment variable
 * @info: structure with potential arguments
 * Return: Always 0
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
<<<<<<< HEAD
		_unsetenv(info, info->argv[i]);

=======
		_unsetenvi(info, info->argv[i]);
>>>>>>> ad36e473b27100ceabff0b76c8bcbf20afad3c3b
	return (0);
}

/**
 * populate_env_list - populate env linked list
 * @info: structure with potential arguments
 * Return: 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		plus_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
