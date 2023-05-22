#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 * struct liststr - singly linked lists
 * @num: number field
 * @str: string
 * @next: points to next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 * struct passinfo - has pseudo-arguements to pass into function,
 * letting uniform prototype for function pointer struct
 * @arg: string from getline with arguements
 * @argv: array of strings from arg
 * @path: string path for current command
 * @argc: argument count
 * @line_count: error count
 * @err_num: error code for exit()s
 * @linecount_flag: if on, count this line
 * @fname: filename
 * @env: linked list local copy for environ
 * @environ: modified copy of environ
 * @history: history node
 * @alias: alias node
 * @env_changed: on when environ changed
 * @status: return status of last command
 * @cmd_buf: address of pointer
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @readfd: fd to read line input
 * @histcount: history number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer for cmd ; chain buffer, memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}

/**
 * struct builtin - has builtin string and related function
 * @type: command flag
 * @func: function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


/* toem_shellloop.c */
int hhsh(info_t *, char **);
int finds_builtin(info_t *);
void finds_cmd(info_t *);
void forks_cmd(info_t *);

/* toem_parser.c */
int its_cmd(info_t *, char *);
char *dupe_chars(char *, int, int);
char *finds_path(info_t *, char *, char *);

/* toem_errors.c */
void _meputs(char *);
int _meputchar(char);
int _meputfd(char c, int fd);
int _meputsfd(char *str, int fd);

/* toem_string.c */
int _strleng(char *);
int _strcomp(char *, char *);
char *start_with(const char *, const char *);
char *_stricat(char *, char *);

/* toem_string1.c */
char *_stricpy(char *, char *);
char *_strdupe(const char *);
void _putss(char *);
int _putchar(char);

/* toem_exits.c */
char *_strcopy(char *, char *, int);
char *_strcon(char *, char *, int);
char *_strchar(char *, char);

/* toem_tokenizer.c */
char **stritow(char *, char *);
char **stritow2(char *, char);

/* toem_realloc.c */
char *_memeset(char *, char, unsigned int);
void pfree(char **);
void *_reallocc(void *, unsigned int, unsigned int);

/* toem_memory.c */
int befree(void **);

/* toem_atoi.c */
int inter(info_t *);
int is_delimeter(char, char *);
int _isalpha(int);
int _atoi(char *);

/* toem_errors1.c */
int _erratoi(char *);
void prints_error(info_t *, char *);
int prints_d(int, int);
char *convert_num(long int, int, int);
void no_comments(char *);

/* toem_builtin.c */
int _mexit(info_t *);
int _mecd(info_t *);
int _chcdir(info_t *);

/* toem_builtin1.c */
int _mehistory(info_t *);
int _mealias(info_t *);

/*toem_getline.c */
ssize_t get_inp(info_t *);
int _gline(info_t *, char **, size_t *);

/* toem_getinfo.c */
void c_info(info_t *);
void s_info(info_t *, char **);
void f_info(info_t *, int);

/* toem_environ.c */
char *_genv(info_t *, const char *);
int _menv(info_t *);
int _msenv(info_t *);
int _munsenv(info_t *);
int pop_env_list(info_t *);

/* toem_getenv.c */
char **get_envi(info_t *);
int _unsetenvi(info_t *, char *);
int _setenvi(info_t *, char *, char *);

/* toem_history.c */
char *get_hist_file(info_t *info);
int write_hist(info_t *info);
int read_hist(info_t *info);
int build_hist_list(info_t *info, char *buf, int linecount);
int renumber_hist(info_t *info);

/* toem_lists.c */
list_t *plus_node(list_t **, const char *, int);
list_t *plus_node_end(list_t **, const char *, int);
size_t pr_list_str(const list_t *);
int del_node_at_index(list_t **, unsigned int);
void fr_list(list_t **);

/* toem_lists1.c */
size_t list_leng(const list_t *);
char **list_to_string(list_t *);
size_t prints_list(const list_t *);
list_t *node_start_with(list_t *, char *, char);
ssize_t g_node_index(list_t *, list_t *);

/* toem_vars.c */
int its_chain(info_t *, char *, size_t *);
void checks_chain(info_t *, char *, size_t *, size_t, size_t);
int replaces_alias(info_t *);
int replaces_vars(info_t *);
int replaces_string(char **, char *);

#endif
