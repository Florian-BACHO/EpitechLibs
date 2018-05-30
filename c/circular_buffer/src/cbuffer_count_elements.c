/*
** EPITECH PROJECT, 2018
** circular_buffer
** File description:
** count elements
*/

#include "circular_buffer.h"

inline size_t cbuffer_count_elements(const circular_buffer_t *buffer)
{
	return ((buffer->write - buffer->read) / buffer->data_size);
}
