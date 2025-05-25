/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 22:49:08 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/25 22:41:46 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/garbage_collector.h"

/**
 * @brief Helper function to copy memory between buffers
 *
 * Copies memory from source to destination, choosing the smaller of
 * old_size and size as the number of bytes to copy.
 *
 * @param new_ptr Destination buffer
 * @param ptr Source buffer
 * @param old_size Size of the source buffer
 * @param size Size of the destination buffer
 */
static void	call_memcpy(void *new_ptr, void *ptr, size_t old_size, size_t size)
{
	if (old_size < size)
		ft_memcpy(new_ptr, ptr, old_size);
	else
		ft_memcpy(new_ptr, ptr, size);
}

/**
 * @brief Resizes a memory block managed by the garbage collector
 *
 * Allocates a new block of the requested size, copies data from the old
 * block, registers the new block, and frees the old one.
 *
 * @param gc Pointer to the garbage collector
 * @param ptr Pointer to the memory block to resize
 * @param size New size in bytes
 * @return void* Pointer to the resized memory block, or NULL if resizing fails
 * @see gc_malloc(), gc_free()
 */
void	*gc_realloc(t_gc *gc, void *ptr, size_t size)
{
	void	*new_ptr;
	size_t	old_size;

	old_size = 0;
	if (!gc)
		return (NULL);
	if (!ptr)
		return (gc_malloc(gc, size));
	if (size == 0)
	{
		gc_free(gc, ptr);
		return (NULL);
	}
	if (!is_valid_block(gc, ptr))
		return (NULL);
	old_size = get_block_size(gc, ptr);
	new_ptr = ft_calloc(1, size);
	if (!new_ptr)
		return (NULL);
	if (old_size > 0)
		call_memcpy(new_ptr, ptr, old_size, size);
	gc_register(gc, new_ptr, size);
	gc_free(gc, ptr);
	return (new_ptr);
}
