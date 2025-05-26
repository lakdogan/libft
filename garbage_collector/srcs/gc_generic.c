/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_generic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 22:38:24 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/27 00:11:28 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/garbage_collector.h"

/**
 * @brief Allocates a data structure of any type
 *
 * Wrapper around gc_calloc that allocates a single structure and
 * initializes it to zero.
 *
 * @param gc Pointer to the garbage collector
 * @param size Size of the structure to allocate in bytes
 * @return void* Pointer to the allocated structure or NULL on failure
 */
void	*gc_alloc_struct(t_gc *gc, size_t size)
{
	return (gc_calloc(gc, 1, size));
}

/**
 * @brief Creates a copy of a data structure
 *
 * Performs a shallow copy of a data structure. Note that pointers within
 * the structure will still point to the same data as the original.
 *
 * @param gc Pointer to the garbage collector
 * @param src Pointer to the source structure
 * @param size Size of the structure in bytes
 * @return void* Copy of the structure or NULL on failure
 */
void	*gc_duplicate_struct(t_gc *gc, const void *src, size_t size)
{
	void	*new_struct;

	if (!src)
		return (NULL);
	new_struct = gc_malloc(gc, size);
	if (!new_struct)
		return (NULL);
	ft_memcpy(new_struct, src, size);
	return (new_struct);
}

/**
 * @brief Allocates an array of structures
 *
 * Creates an array of structures of a given size. All memory is
 * initialized to zero.
 *
 * @param gc Pointer to the garbage collector
 * @param count Number of structures to allocate
 * @param struct_size Size of each structure in bytes
 * @return void* Pointer to the array or NULL on failure
 */
void	*gc_alloc_struct_array(t_gc *gc, size_t count, size_t struct_size)
{
	return (gc_calloc(gc, count, struct_size));
}
