/*
** EPITECH PROJECT, 2018
** circular buffer
** File description:
** create
*/

#include "circular_buffer.h"

circular_buffer_t *cbuffer_create(size_t len)
{
	circular_buffer_t *out = calloc(1, sizeof(circular_buffer_t));

	if (!out)
		return (NULL);
	out->len = len;
	out->buffer = calloc(len, sizeof(void *));
	if (!out->buffer) {
		free(out);
		return (NULL);
	}
	return (out);
}
