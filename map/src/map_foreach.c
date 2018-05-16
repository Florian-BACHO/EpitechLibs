/*
** EPITECH PROJECT, 2018
** linked list
** File description:
** foreach
*/

#include "map.h"

void map_foreach(map_t *map, foreach_fct_t fct, ...)
{
	va_list ap;

	while (map) {
		va_start(ap, fct);
		if (!fct(map->data, ap)) {
			va_end(ap);
			break;
		}
		va_end(ap);
		map = map->next;
	}
}
