/*
** EPITECH PROJECT, 2018
** linked_list
** File description:
** set
*/

#include <stdio.h>
#include "linked_list.h"

static linked_list_t *get_last_elem(linked_list_t *linked_list)
{
	if (linked_list == NULL)
		return (NULL);
	while (linked_list->next)
		linked_list = linked_list->next;
	return (linked_list);
}

bool linked_list_add(linked_list_t **linked_list, void *value)
{
	linked_list_t *node = malloc(sizeof(linked_list_t));

	if (!node)
		return (false);
	node->next = NULL;
	node->prev = get_last_elem(*linked_list);
	if (node->prev)
		node->prev->next = node;
	if (!*linked_list)
		*linked_list = node;
	node->data = value;
	return (true);
}
