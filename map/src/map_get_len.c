/*
** EPITECH PROJECT, 2018
** map
** File description:
** get len
*/

#include "map.h"

size_t map_get_len(const map_t *map)
{
	size_t out = 0;

	while (map != NULL) {
		out++;
		map = map->next;
	}
	return (out);
}
