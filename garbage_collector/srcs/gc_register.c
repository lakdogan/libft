/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_register.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:07:48 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/25 22:41:52 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/garbage_collector.h"

/**
 * @brief Registers a pointer with the garbage collector
 *
 * Adds a pointer to the garbage collector's tracking arrays and hash table.
 * Automatically expands capacity if needed.
 *
 * @param gc Pointer to the garbage collector
 * @param ptr Pointer to register
 * @param size Size of the allocation in bytes
 */
void	gc_register(t_gc *gc, void *ptr, size_t size)
{
	if (!ptr || !gc)
		return ;
	if (gc->count >= gc->capacity)
	{
		if (!gc_expand(gc))
			return ;
	}
	gc->pointers[gc->count] = ptr;
	gc->sizes[gc->count] = size;
	hash_insert(gc->hash_table, ptr, size);
	gc->count++;
}
