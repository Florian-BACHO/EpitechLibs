/*
** EPITECH PROJECT, 2018
** circular buffer
** File description:
** reset
*/

#include "circular_buffer.h"

void cbuffer_reset(circular_buffer_t *buffer)
{
	buffer->read = 0;
	buffer->write = 0;
}
