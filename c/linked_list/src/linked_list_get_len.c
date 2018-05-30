/*
** EPITECH PROJECT, 2018
** linked list
** File description:
** get len
*/

#include "linked_list.h"

size_t linked_list_get_len(const linked_list_t *linked_list)
{
	size_t out = 0;

	while (linked_list != NULL) {
		out++;
		linked_list = linked_list->next;
	}
	return (out);
}
