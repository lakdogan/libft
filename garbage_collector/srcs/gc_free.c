/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:59:16 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/25 22:40:39 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/garbage_collector.h"

/**
 * @brief Validates the garbage collector and pointer parameters
 *
 * @param gc Pointer to the garbage collector
 * @param ptr Pointer to the memory block
 * @return int 1 if valid, 0 if invalid
 */
static int	validate_gc_params(t_gc *gc, void *ptr)
{
	if (!gc || !ptr)
		return (0);
	if (!gc->pointers || !gc->sizes)
		return (0);
	if (gc->count > gc->capacity)
	{
		ft_putstr_fd("Error: Corrupted gc structure\n", STDERR_FILENO);
		return (0);
	}
	return (1);
}

/**
 * @brief Finds the index of a pointer in the garbage collector's array
 *
 * @param gc Pointer to the garbage collector
 * @param ptr Pointer to find
 * @return size_t Index of the pointer, or SIZE_MAX if not found
 */
static size_t	find_pointer_index(t_gc *gc, void *ptr)
{
	size_t	i;

	i = 0;
	while (i < gc->count)
	{
		if (gc->pointers[i] == ptr)
			return (i);
		i++;
	}
	return (GC_NOT_FOUND);
}

/**
 * @brief Releases a pointer and shifts arrays to fill the gap
 *
 * @param gc Pointer to the garbage collector
 * @param index Index of the pointer to free
 */
static void	release_and_shift(t_gc *gc, size_t index)
{
	size_t	j;
	void	*saved_ptr;

	saved_ptr = gc->pointers[index];
	if (saved_ptr != NULL)
	{
		gc->pointers[index] = NULL;
		free(saved_ptr);
	}
	j = index;
	while (j < gc->count - 1)
	{
		gc->pointers[j] = gc->pointers[j + 1];
		gc->sizes[j] = gc->sizes[j + 1];
		j++;
	}
}

/**
 * @brief Updates the garbage collector state after freeing
 *
 * @param gc Pointer to the garbage collector
 */
static void	update_gc_state(t_gc *gc)
{
	if (gc->count > 0)
	{
		gc->pointers[gc->count - 1] = NULL;
		gc->sizes[gc->count - 1] = 0;
		gc->count--;
	}
}

/**
 * @brief Safely frees a memory block managed by the garbage collector
 *
 * @param gc Pointer to the garbage collector
 * @param ptr Pointer to the memory block to free
 */
void	gc_free(t_gc *gc, void *ptr)
{
	size_t	index;
	void	*saved_ptr;

	if (!validate_gc_params(gc, ptr))
		return ;
	index = find_pointer_index(gc, ptr);
	if (index == GC_NOT_FOUND)
		return ;
	saved_ptr = gc->pointers[index];
	if (saved_ptr != NULL)
	{
		gc->pointers[index] = NULL;
		free(saved_ptr);
	}
	hash_remove(gc->hash_table, ptr);
	release_and_shift(gc, index);
	update_gc_state(gc);
}
