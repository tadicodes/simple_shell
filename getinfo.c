#include "shell.h"

/**
<<<<<<< HEAD
 * clear_info - initialize the info_t struct
 * @info: structure address
=======
 * cl_info - initializes info_t struct
 * @info: struct address
>>>>>>> ad36e473b27100ceabff0b76c8bcbf20afad3c3b
 */
void cl_info(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}

/**
<<<<<<< HEAD
 * set_info - initialize the info_t struct
 * @info: structure address
 * @av: the argument vector
=======
 * s_info - initializes info_t struct
 * @av: argument vector
 * @info: struct address
>>>>>>> ad36e473b27100ceabff0b76c8bcbf20afad3c3b
 */
void s_info(info_t *info, char **av)
{
	int i = 0;

	info->fname = av[0];
	if (info->arg)
	{
		info->argv = stritow(info->arg, " \t");
		if (!info->argv)
		{
			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdupe(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (i = 0; info->argv && info->argv[i]; i++)
			;
		info->argc = i;

		replaces_alias(info);
		replaces_vars(info);
	}
}

/**
<<<<<<< HEAD
 * free_info - free info_t struct fields
 * @info: structure address
 * @all: true for freeing all fields
=======
 * f_info - frees info_t struct fields
 * @all: true if freeing all fields
 * @info: struct address
>>>>>>> ad36e473b27100ceabff0b76c8bcbf20afad3c3b
 */
void f_info(info_t *info, int all)
{
	pfree(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (all)
	{
		if (!info->cmd_buf)
			free(info->arg);
		if (info->env)
			fr_list(&(info->env));
		if (info->history)
			fr_list(&(info->history));
		if (info->alias)
			free_list(&(info->alias));
		pfree(info->environ);
			info->environ = NULL;
		befree((void **)info->cmd_buf);
		if (info->readfd > 2)
			close(info->readfd);
		_putchar(BUF_FLUSH);
	}
}
