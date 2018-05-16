/*
** EPITECH PROJECT, 2018
** circular buffer
** File description:
** destroy
*/

#include "circular_buffer.h"

void cbuffer_destroy(circular_buffer_t *buffer)
{
	free(buffer->buffer);
	free(buffer);
}
