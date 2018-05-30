/*
** EPITECH PROJECT, 2018
** map
** File description:
** find node
*/

#include "map.h"

map_t *pmap_find_node(map_t *map, const char *key)
{
	while (map) {
		if (!strcmp(map->key, key))
			return (map);
		map = map->next;
	}
	return (NULL);
}

map_t *pmap_find_node_if(map_t *map, condition_t cond, va_list ap)
{
	va_list ap_cpy;

	while (map) {
		va_copy(ap_cpy, ap);
		if (cond(map->data, ap_cpy)) {
			va_end(ap_cpy);
			return (map);
		}
		map = map->next;
		va_end(ap_cpy);
	}
	return (NULL);
}
