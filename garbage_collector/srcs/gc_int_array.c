/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_int_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 21:01:41 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/27 00:11:35 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/garbage_collector.h"

/**
 * @brief Allocates an integer array
 *
 * @param gc Pointer to the garbage collector
 * @param size Number of integers
 * @return int* Allocated integer array or NULL on failure
 */
int	*gc_int_array_create(t_gc *gc, size_t size)
{
	return ((int *)gc_calloc(gc, size, sizeof(int)));
}

/**
 * @brief Duplicates an integer array
 *
 * @param gc Pointer to the garbage collector
 * @param src Source integer array
 * @param size Size of the array
 * @return int* Duplicated integer array or NULL on failure
 */
int	*gc_int_array_dup(t_gc *gc, const int *src, size_t size)
{
	int	*array;

	if (!src)
		return (NULL);
	array = gc_int_array_create(gc, size);
	if (!array)
		return (NULL);
	ft_memcpy(array, src, size * sizeof(int));
	return (array);
}
