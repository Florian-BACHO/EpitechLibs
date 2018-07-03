/*
** EPITECH PROJECT, 2018
** irc
** File description:
** map
*/

#ifndef MAP_H_
#define MAP_H_

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

typedef struct map {
	char *key;
	void *data;
	struct map *prev;
	struct map *next;
} map_t;

typedef bool (*condition_t)(void *, va_list);
typedef void (*free_fct_t)(void *);
/*
** The foreach_fct_t must return false if the loop have to be broken
*/
typedef bool (*foreach_fct_t)(void *, va_list);

/*
** Public
*/
void map_destroy(map_t **map, free_fct_t free_data);
void map_remove(map_t **map, const char *key, free_fct_t free_data);
void map_remove_if(map_t **map, condition_t cond, free_fct_t free_data, ...);
void *map_get(map_t *map, const char *key);
void *map_get_if(map_t *map, condition_t cond, ...);
char *map_get_key(map_t *map, void *data);
bool map_set(map_t **map, const char *key, void *value);
size_t map_get_len(const map_t *map);

/*
** Private (pmap)
*/

map_t *pmap_find_node(map_t *map, const char *key);
map_t *pmap_find_node_if(map_t *map, condition_t cond, va_list ap);

#endif
