/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_realloc_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:24:35 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/25 22:41:36 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/garbage_collector.h"

/**
 * @brief Creates an array info structure
 *
 * Helper function to create a structure containing array information
 * for gc_realloc_array.
 *
 * @param old_count Number of elements in the old array
 * @param new_count Number of elements in the new array
 * @param elem_size Size of each element in bytes
 * @return t_array_info Structure containing the array information
 */
t_array_info	create_array_info(size_t old_count, size_t new_count,
		size_t elem_size)
{
	t_array_info	info;

	info.old_count = old_count;
	info.new_count = new_count;
	info.elem_size = elem_size;
	return (info);
}

/**
 * @brief Resizes an array and preserves its contents
 *
 * @param gc Pointer to the garbage collector
 * @param ptr Pointer to the array to resize
 * @param info Structure with array dimension information
 * @return void* Pointer to the resized array, or NULL if resizing fails
 */
void	*gc_realloc_array(t_gc *gc, void *ptr, t_array_info info)
{
	void	*new_ptr;
	size_t	copy_count;

	if (!gc)
		return (NULL);
	if (!ptr)
		return (gc_calloc(gc, info.new_count, info.elem_size));
	if (info.new_count == 0)
	{
		gc_free(gc, ptr);
		return (NULL);
	}
	if (!is_valid_block(gc, ptr))
		return (NULL);
	new_ptr = gc_calloc(gc, info.new_count, info.elem_size);
	if (!new_ptr)
		return (NULL);
	if (info.old_count < info.new_count)
		copy_count = info.old_count;
	else
		copy_count = info.new_count;
	ft_memcpy(new_ptr, ptr, copy_count * info.elem_size);
	gc_free(gc, ptr);
	return (new_ptr);
}
