/*
** EPITECH PROJECT, 2018
** circular_buffer
** File description:
** get next index
*/

#include "circular_buffer.h"

inline size_t pcb_get_next_idx(size_t idx, size_t len)
{
	return ((idx + 1) % len);
}
