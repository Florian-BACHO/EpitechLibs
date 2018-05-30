/*
** EPITECH PROJECT, 2018
** map
** File description:
** get
*/

#include "map.h"

void *map_get(map_t *map, const char *key)
{
	map_t *node = pmap_find_node(map, key);

	if (!node)
		return (NULL);
	return (node->data);
}

void *map_get_if(map_t *map, condition_t cond, ...)
{
	va_list ap;
	map_t *node;

	va_start(ap, cond);
	node = pmap_find_node_if(map, cond, ap);
	va_end(ap);
	return (node != NULL ? node->data : NULL);
}

char *map_get_key(map_t *map, void *data)
{
	while (map) {
		if (map->data == data)
			return (map->key);
		map = map->next;
	}
	return (NULL);
}
