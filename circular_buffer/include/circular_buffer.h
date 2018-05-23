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
#include <string.h>
#include <stdarg.h>

typedef struct circular_buffer {

	size_t len;
	size_t data_size;
	void *buffer;
	size_t read;
	size_t write;
} circular_buffer_t;

typedef bool (*condition_t)(void *, va_list);

/*
** Public
*/
circular_buffer_t *cbuffer_create(size_t len, size_t data_size);
void cbuffer_reset(circular_buffer_t *buffer);
void cbuffer_destroy(circular_buffer_t *buffer);
bool cbuffer_is_empty(const circular_buffer_t *buffer);
bool cbuffer_is_full(const circular_buffer_t *buffer);
size_t cbuffer_count_elements(const circular_buffer_t *buffer);

/*
** Use like write system call
*/
size_t cbuffer_write(circular_buffer_t *buffer, void *data, size_t len);

/*
** Use like read system call
*/
size_t cbuffer_read(circular_buffer_t *buffer, void *data, size_t len);

/*
** Read / Write while stop condition return false
** Stop if cannot read or write anymore
*/
size_t cbuffer_write_until(circular_buffer_t *buffer, void *data,
				condition_t stop_cond, ...);
size_t cbuffer_read_until(circular_buffer_t *buffer, void *data,
				condition_t stop_cond, ...);

/*
** Private (pcb == private circular_buffer)
*/
size_t pcb_get_next_idx(size_t idx, size_t len);

#endif
