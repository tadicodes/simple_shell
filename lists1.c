#include "shell.h"

/**
 * list_leng - determines the length of linked list
 * @h: the pointer to first node
 *
 * Return: the size of list
 */
size_t list_leng(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * list_to_string - returns an array of strings of the list->str
 * @head: he pointer to first node
 *
 * Return: an array of strings
 */
char **list_to_string(list_t *head)
{
	list_t *node = head;
	size_t i = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcopy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


/**
 * prints_list - prints all elements of a list_t linked list
 * @h: the pointer to first node
 *
 * Return: the size of list
 */
size_t prints_list(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * node_start_with - returns node whose string starts with prefix
 * @node: a pointer to list head
 * @prefix: a string to match
 * @c: the next character after prefix to match
 *
 * Return: to match node or null
 */
list_t *node_start_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * g_node_index - gets the index of a node
 * @head: the pointer to list head
 * @node: the pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t g_node_index(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}
