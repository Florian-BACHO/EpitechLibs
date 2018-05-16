/*
** EPITECH PROJECT, 2018
** circular_buffer
** File description:
** is empty or full
*/

#include "circular_buffer.h"

inline bool cbuffer_is_empty(const circular_buffer_t *buffer)
{
	return (buffer->read == buffer->write);
}

inline bool cbuffer_is_full(const circular_buffer_t *buffer)
{
	return (pcb_get_next_idx(buffer->write, buffer->len) == buffer->read);
}
