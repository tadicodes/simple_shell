#include "shell.h"

/**
 * _meexit - exit shell
 * @info: structure with potential arguments
 * Return: exit with given exit status
 * (0) if info.argv[0] != "exit"
 */
int _meexit(info_t *info)
{
	int exitcheck;

	if (info->argv[1]) /* If there is an exit argument */
	{
		exitcheck = _erratoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
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
 * @info: structure with potential arguments
 * Return: 0
 */
int _mecd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
<<<<<<< HEAD
		_puts("TODO: >>getcwd failure emsg here<<\n");
=======
		_putss("TODO: >>getcwd failure msg here<<\n");
>>>>>>> ad36e473b27100ceabff0b76c8bcbf20afad3c3b
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir_ret = /* TODO: what should this be? */
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcomp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_putss(s);
			_putchar('\n');
			return (1);
		}
<<<<<<< HEAD
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
=======
		_putss(_genv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret =
			chdir((dir = _genv(info, "OLDPWD=")) ? dir : "/");
>>>>>>> ad36e473b27100ceabff0b76c8bcbf20afad3c3b
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
<<<<<<< HEAD
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
=======
		_setenvi(info, "OLDPWD", _genv(info, "PWD="));
		_setenvi(info, "PWD", getcwd(buffer, 1024));
>>>>>>> ad36e473b27100ceabff0b76c8bcbf20afad3c3b
	}
	return (0);
}

/**
 * _mehelp - change the current directory
 * @info: structure with potential arguments
 * Return: Always 0
 */
int _mehelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); /* temp att_unused workaround */
	return (0);
}
