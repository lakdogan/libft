/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:06:04 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/25 22:40:30 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/garbage_collector.h"

/**
 * @brief Calculates the new capacity for the garbage collector
 *
 * @param current_capacity The current capacity
 * @return size_t The new capacity
 */
static size_t	calculate_new_capacity(size_t current_capacity)
{
	size_t	new_capacity;

	new_capacity = current_capacity * GC_GROWTH_FACTOR;
	if (new_capacity < 16)
		new_capacity = 16;
	return (new_capacity);
}

/**
 * @brief Allocates new arrays for the garbage collector
 *
 * @param new_capacity The new capacity
 * @param new_pointers Pointer to store the new pointers array
 * @param new_sizes Pointer to store the new sizes array
 * @return int 1 on success, 0 on failure
 */
static int	allocate_new_arrays(size_t new_capacity, void ***new_pointers,
		size_t **new_sizes)
{
	*new_pointers = malloc(sizeof(void *) * new_capacity);
	if (!(*new_pointers))
		return (0);
	*new_sizes = malloc(sizeof(size_t) * new_capacity);
	if (!(*new_sizes))
	{
		free(*new_pointers);
		*new_pointers = NULL;
		return (0);
	}
	return (1);
}

/**
 * @brief Copies data from old arrays to new arrays
 *
 * @param gc The garbage collector
 * @param new_pointers The new pointers array
 * @param new_sizes The new sizes array
 */
static void	copy_arrays(t_gc *gc, void **new_pointers, size_t *new_sizes)
{
	size_t	i;

	i = 0;
	while (i < gc->count)
	{
		new_pointers[i] = gc->pointers[i];
		new_sizes[i] = gc->sizes[i];
		i++;
	}
}

/**
 * @brief Updates the garbage collector with new arrays
 *
 * @param gc The garbage collector
 * @param new_pointers The new pointers array
 * @param new_sizes The new sizes array
 * @param new_capacity The new capacity
 */
static void	update_gc(t_gc *gc, void **new_pointers, size_t *new_sizes,
		size_t new_capacity)
{
	free(gc->pointers);
	free(gc->sizes);
	gc->pointers = new_pointers;
	gc->sizes = new_sizes;
	gc->capacity = new_capacity;
}

/**
 * @brief Expands the capacity of the garbage collector
 *
 * @param gc Pointer to the garbage collector
 * @return int 1 on success, 0 on failure
 */
int	gc_expand(t_gc *gc)
{
	void	**new_pointers;
	size_t	*new_sizes;
	size_t	new_capacity;

	if (!gc)
		return (0);
	new_capacity = calculate_new_capacity(gc->capacity);
	if (!allocate_new_arrays(new_capacity, &new_pointers, &new_sizes))
		return (0);
	copy_arrays(gc, new_pointers, new_sizes);
	update_gc(gc, new_pointers, new_sizes, new_capacity);
	return (1);
}
