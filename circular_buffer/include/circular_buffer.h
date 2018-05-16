/*
** EPITECH PROJECT, 2018
** circular buffer
** File description:
** header
*/

#ifndef CIRCULAR_BUFFER_H_
#define CIRCULAR_BUFFER_H_

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct circular_buffer {

	size_t len;
	void **buffer;
	size_t read;
	size_t write;
} circular_buffer_t;

/*
** Public
*/
circular_buffer_t *cbuffer_create(size_t len);
void cbuffer_reset(circular_buffer_t *buffer);
void cbuffer_destroy(circular_buffer_t *buffer);
bool cbuffer_is_empty(const circular_buffer_t *buffer);
bool cbuffer_is_full(const circular_buffer_t *buffer);
void cbuffer_write(circular_buffer_t *buffer, void *data);
void *cbuffer_read(circular_buffer_t *buffer);

/*
** Private (pcb == private circular_buffer)
*/
size_t pcb_get_next_idx(size_t idx, size_t len);

#endif
