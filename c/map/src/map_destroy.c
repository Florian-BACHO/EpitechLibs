/*
** EPITECH PROJECT, 2018
** map
** File description:
** destroy
*/

#include "map.h"

static void remove_node(map_t **map, map_t *node, free_fct_t free_data)
{
	map_t *prev = node->prev;
	map_t *to_set = (node == *map) ? node->next : *map;

	if (prev)
		prev->next = node->next;
	if (node->next)
		node->next->prev = prev;
	free(node->key);
	if (free_data)
		free_data(node->data);
	free(node);
	*map = to_set;
}

void map_destroy(map_t **map, free_fct_t free_data)
{
	map_t *next;

	while (*map != NULL) {
		next = (*map)->next;
		free((*map)->key);
		if (free_data)
			free_data((*map)->data);
		free(*map);
		*map = next;
	}
}

void map_remove(map_t **map, const char *key, free_fct_t free_data)
{
	map_t *node = pmap_find_node(*map, key);

	if (node)
		remove_node(map, node, free_data);
}

void map_remove_if(map_t **map, condition_t cond, free_fct_t free_data, ...)
{
	va_list ap;
	map_t *node;

	va_start(ap, free_data);
	node = pmap_find_node_if(*map, cond, ap);
	if (node)
		remove_node(map, node, free_data);
	va_end(ap);
}
