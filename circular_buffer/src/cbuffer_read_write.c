/*
** EPITECH PROJECT, 2018
** circular buffer
** File description:
** circular buffer
*/

#include "circular_buffer.h"

void cbuffer_write(circular_buffer_t *buffer, void *data)
{
	buffer->buffer[buffer->write] = data;
	do {
		buffer->write = pcb_get_next_idx(buffer->write, buffer->len);
	} while (buffer->write == buffer->read);
}

void *cbuffer_read(circular_buffer_t *buffer)
{
	void *out = buffer->buffer[buffer->read];

	if (cbuffer_is_empty(buffer))
		return (NULL);
	buffer->read = pcb_get_next_idx(buffer->read, buffer->len);
	return (out);
}
