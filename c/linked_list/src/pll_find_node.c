/*
** EPITECH PROJECT, 2018
** linked_list
** File description:
** find node
*/

#include "linked_list.h"

linked_list_t *pll_find_node_if(linked_list_t *linked_list, condition_t cond,
				va_list ap)
{
	va_list ap_cpy;

	while (linked_list) {
		va_copy(ap_cpy, ap);
		if (cond(linked_list->data, ap_cpy)) {
			va_end(ap_cpy);
			return (linked_list);
		}
		linked_list = linked_list->next;
		va_end(ap_cpy);
	}
	return (NULL);
}
