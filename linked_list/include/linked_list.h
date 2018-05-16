/*
** EPITECH PROJECT, 2018
** irc
** File description:
** linked_list
*/

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

typedef struct linked_list {
	void *data;
	struct linked_list *prev;
	struct linked_list *next;
} linked_list_t;

typedef bool (*condition_t)(void *, va_list);
typedef void (*free_fct_t)(void *);
/*
** The foreach_fct_t must return false if the loop have to be breaked
*/
typedef bool (*foreach_fct_t)(void *, va_list);

/*
** Public
*/
void linked_list_destroy(linked_list_t **linked_list, free_fct_t free_data);
bool linked_list_remove_if(linked_list_t **linked_list, condition_t cond,
				free_fct_t free_data, ...);
void *linked_list_get_if(linked_list_t *linked_list, condition_t cond, ...);
bool linked_list_add(linked_list_t **linked_list, void *value);
size_t linked_list_get_len(const linked_list_t *linked_list);
void linked_list_foreach(linked_list_t *linked_list, foreach_fct_t fct, ...);

/*
** Private (pll)
*/

linked_list_t *pll_find_node_if(linked_list_t *linked_list, condition_t cond,
				va_list ap);

#endif
