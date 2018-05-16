/*
** EPITECH PROJECT, 2018
** linked list
** File description:
** foreach
*/

#include "linked_list.h"

void linked_list_foreach(linked_list_t *linked_list, foreach_fct_t fct, ...)
{
	va_list ap;

	while (linked_list) {
		va_start(ap, fct);
		if (!fct(linked_list->data, ap)) {
			va_end(ap);
			break;
		}
		va_end(ap);
		linked_list = linked_list->next;
	}
}
