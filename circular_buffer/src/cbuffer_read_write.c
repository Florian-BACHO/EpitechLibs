/*
** EPITECH PROJECT, 2018
** circular buffer
** File description:
** circular buffer
*/

#include "circular_buffer.h"

size_t cbuffer_write(circular_buffer_t *buffer, void *data, size_t len)
{
	size_t out = 0u;

	while (out < len && !cbuffer_is_full(buffer)) {
		memcpy(buffer->buffer + (buffer->write * buffer->data_size),
			data + (out * buffer->data_size), buffer->data_size);
		out++;
		buffer->write = pcb_get_next_idx(buffer->write, buffer->len);
	}
	return (out);
}

size_t cbuffer_read(circular_buffer_t *buffer, void *data, size_t len)
{
	size_t out = 0u;

	while (out < len && !cbuffer_is_empty(buffer)) {
		memcpy(data + (out * buffer->data_size),
			buffer->buffer + (buffer->read * buffer->data_size),
			buffer->data_size);
		out++;
		buffer->read = pcb_get_next_idx(buffer->read, buffer->len);
	}
	return (out);
}

size_t cbuffer_write_until(circular_buffer_t *buffer, void *data,
				condition_t stop_cond, ...)
{
	size_t out = 0u;
	va_list ap;

	va_start(ap, stop_cond);
	while (!stop_cond(data + (out * buffer->data_size), ap) &&
		!cbuffer_is_full(buffer)) {
		memcpy(buffer->buffer + (buffer->write * buffer->data_size),
			data + (out * buffer->data_size), buffer->data_size);
		out++;
		buffer->write = pcb_get_next_idx(buffer->write, buffer->len);
		va_end(ap);
		va_start(ap, stop_cond);
	}
	va_end(ap);
	return (out);
}

size_t cbuffer_read_until(circular_buffer_t *buffer, void *data,
				condition_t stop_cond, ...)
{
	size_t out = 0u;
	va_list ap;

	va_start(ap, stop_cond);
	while (!stop_cond(buffer->buffer + (buffer->read * buffer->data_size),
				ap) && !cbuffer_is_empty(buffer)) {
		memcpy(data + (out * buffer->data_size),
			buffer->buffer + (buffer->read * buffer->data_size),
			buffer->data_size);
		out++;
		buffer->read = pcb_get_next_idx(buffer->read, buffer->len);
		va_end(ap);
		va_start(ap, stop_cond);
	}
	va_end(ap);
	return (out);
}
