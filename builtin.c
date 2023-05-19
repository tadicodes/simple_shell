#include "shell.h"

/**
 * _mexit - exit shell
 * @info: contains potential arguments
 * Return: (0) if info.argv[0] != "exit"
 */
int _mexit(info_t *info)
{
	int exitcheck;

	if (info->argv[1])
	{
		exitcheck = _erratoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			prints_error(info, "Illegal number: ");
			_meputs(info->argv[1]);
			_meputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mecd - change current directory
 * @info: contains potential arguments
 * Return: Always 0
 */
int _mecd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure msg here<<\n");
	if (!info->argv[1])
	{
		dir = _genv(info, "HOME=");
		if (!dir)
			chdir_ret =
				chdir((dir = _genv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_genv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_genv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret =
			chdir((dir = _genv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		prints_error(info, "can't cd to ");
		_meputs(info->argv[1]), _meputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _genv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _chcdir - changes current directory
 * @info: contains potential arguments
 * Return: 0
 */
int _chcdir(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("Help call works.\n");
	if (0)
		_puts(*arg_array);
	return (0);
}
