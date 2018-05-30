/*
** EPITECH PROJECT, 2018
** map
** File description:
** set
*/

#include <stdio.h>
#include "map.h"

static map_t *get_last_elem(map_t *map)
{
	if (map == NULL)
		return (NULL);
	while (map->next)
		map = map->next;
	return (map);
}

static map_t *map_add_node(map_t **map, const char *key)
{
	map_t *node = malloc(sizeof(map_t));

	if (!node)
		return (NULL);
	node->key = strdup(key);
	if (!node->key)
		return (NULL);
	node->next = NULL;
	node->prev = get_last_elem(*map);
	if (node->prev)
		node->prev->next = node;
	if (!*map)
		*map = node;
	return (node);
}

bool map_set(map_t **map, const char *key, void *value)
{
	map_t *node = map_get(*map, key);

	if (!node) {
		node = map_add_node(map, key);
		if (!node)
			return (false);
	}
	node->data = value;
	return (true);
}
