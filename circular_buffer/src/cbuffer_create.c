/*
** EPITECH PROJECT, 2018
** circular buffer
** File description:
** create
*/

#include "circular_buffer.h"

circular_buffer_t *cbuffer_create(size_t len, size_t data_size)
{
	circular_buffer_t *out = calloc(1, sizeof(circular_buffer_t));

	if (!out)
		return (NULL);
	out->len = len + 1;
	out->data_size = data_size;
	out->buffer = calloc(out->len, data_size);
	if (!out->buffer) {
		free(out);
		return (NULL);
	}
	return (out);
}
