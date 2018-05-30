/*
** EPITECH PROJECT, 2018
** map
** File description:
** destroy
*/

#include "linked_list.h"

static void remove_node(linked_list_t **linked_list, linked_list_t *node,
			free_fct_t free_data)
{
	linked_list_t *prev = node->prev;
	linked_list_t *to_set = (node == *linked_list) ? node->next :
		*linked_list;

	if (prev)
		prev->next = node->next;
	if (node->next)
		node->next->prev = prev;
	if (free_data)
		free_data(node->data);
	free(node);
	*linked_list = to_set;
}

void linked_list_destroy(linked_list_t **linked_list, free_fct_t free_data)
{
	linked_list_t *next;

	while (*linked_list != NULL) {
		next = (*linked_list)->next;
		if (free_data)
			free_data((*linked_list)->data);
		free(*linked_list);
		*linked_list = next;
	}
}

bool linked_list_remove_if(linked_list_t **linked_list, condition_t cond,
				free_fct_t free_data, ...)
{
	va_list ap;
	linked_list_t *node;
	bool out = false;

	do {
		va_start(ap, free_data);
		node = pll_find_node_if(*linked_list, cond, ap);
		va_end(ap);
		if (node) {
			remove_node(linked_list, node, free_data);
			out = true;
		}
	} while (node);
	return (out);
}
