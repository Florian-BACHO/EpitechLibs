/*
** EPITECH PROJECT, 2018
** linked_list
** File description:
** get
*/

#include "linked_list.h"

void *linked_list_get_if(linked_list_t *linked_list, condition_t cond, ...)
{
	va_list ap;
	linked_list_t *node;

	va_start(ap, cond);
	node = pll_find_node_if(linked_list, cond, ap);
	va_end(ap);
	return (node != NULL ? node->data : NULL);
}
