#include "main.h"

/**
 * is_alias_to_set - Checks if the argument is an alias to set
 * @arg: The argument to check
 * Return: 1 if it is an alias to set, 0 otherwise
 */
int is_alias_to_set(char *arg)
{
	int i;

	for (i = 0; arg[i] != '\0'; i++)
	{
		if (arg[i] == '=' && i != 0)
			return (1);
	}
	return (0);
}

/**
 * free_alias_list - Frees an alias_list list.
 * @head: Pointer to the first element of the list
 * Return: void
 */
void free_alias_list(alias_list *head)
{
	alias_list *prev;

	while (head != NULL)
	{
		prev = head;
		head = head->next;
		free(prev->name);
		free(prev->value);
		free(prev);
	}
}

/**
 * is_found - Checks whether an alias exists in alias_list list or not
 * @head: Pointer to the first element of the list
 * @name: The name of the alias to check
 * Return: 1 if alias is found, 0 if it is not found
 */
int is_found(alias_list *head, char *name)
{
	alias_list *tmp = head;

	while (tmp != NULL)
	{
		if (_strcmp(tmp->name, name) == 0)
		{
			return (1);
		}
		tmp = tmp->next;
	}
	print_error("alias: %s not found\n", name);
	return (0);
}
