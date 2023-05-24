#include "shell.h"

/**
<<<<<<< HEAD
 * get_environ - return string array copy
 * @info: structure with potential arguments
 * Return: 0
=======
 * get_envi - return string array copy of environment
 * @info: To structure the containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always to 0
>>>>>>> ad36e473b27100ceabff0b76c8bcbf20afad3c3b
 */
char **get_envi(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_string(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
<<<<<<< HEAD
 * _unsetenv - remove environment variable
 * @info: structure with potential arguments
 *  Return: 1 delete, otherwise 0
 * @var: string env var property
=======
 * _unsetenvi - Remove an environment variable
 * @info: To structure containing potential arguments. It is used to maintain
 *        constant function prototype.
 *  Return: 1 on delete, 0 otherwise
 * @var: For the string env var property
>>>>>>> ad36e473b27100ceabff0b76c8bcbf20afad3c3b
 */
int _unsetenvi(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = start_with(node->str, var);
		if (p && *p == '=')
		{
			info->env_changed = del_node_at_index(&(info->env), i);
			i = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->env_changed);
}

/**
<<<<<<< HEAD
 * _setenv - Initialize a new environment variable
 * @info: structure with potential arguments
 * @var: string env var property
 * @value: string env var value
 *  Return: 0
=======
 * _setenvi - Initialize a new environment variable,
 *             or modify an existing one
 * @info: For the structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @var: For the string env var property
 * @value: For the string env var value
 *  Return: Always  to 0
>>>>>>> ad36e473b27100ceabff0b76c8bcbf20afad3c3b
 */
int _setenvi(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(_strleng(var) + _strleng(value) + 2);
	if (!buf)
		return (1);
	_strcopy(buf, var);
	_strcon(buf, "=");
	_strcon(buf, value);
	node = info->env;
	while (node)
	{
		p = start_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	plus_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}
