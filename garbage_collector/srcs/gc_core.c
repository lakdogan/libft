/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 22:48:50 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/25 22:40:21 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/garbage_collector.h"

/**
 * @brief Creates a new garbage collector instance
 *
 * Allocates memory for the garbage collector structure and initializes
 * its tracking arrays with the default initial capacity.
 *
 * @return t_gc* New garbage collector, or NULL if allocation fails
 */
t_gc	*gc_create(void)
{
	t_gc	*gc;

	gc = malloc(sizeof(t_gc));
	if (!gc)
		return (NULL);
	gc->pointers = malloc(sizeof(void *) * GC_INITIAL_CAPACITY);
	gc->sizes = malloc(sizeof(size_t) * GC_INITIAL_CAPACITY);
	gc->hash_table = hash_create(GC_INITIAL_CAPACITY * 2);
	if (!gc->pointers || !gc->sizes || !gc->hash_table)
	{
		free(gc->pointers);
		free(gc->sizes);
		if (gc->hash_table)
			hash_destroy(gc->hash_table);
		free(gc);
		return (NULL);
	}
	gc->count = 0;
	gc->capacity = GC_INITIAL_CAPACITY;
	return (gc);
}

/**
 * @brief Frees all memory blocks managed by the garbage collector
 *
 * Traverses all memory blocks tracked by the garbage collector and
 * frees each one. Resets the count to zero.
 *
 * @param gc Pointer to the garbage collector
 */
void	gc_collect(t_gc *gc)
{
	size_t	i;

	if (!gc)
		return ;
	i = 0;
	while (i < gc->count)
	{
		free(gc->pointers[i]);
		i++;
	}
	gc->count = 0;
}

/**
 * @brief Frees all memory and destroys the garbage collector
 *
 * Performs a complete cleanup by first freeing all managed blocks,
 * then freeing the tracking arrays and the GC structure itself.
 *
 * @param gc Pointer to the pointer to the garbage collector
 * @see gc_collect()
 */
void	gc_cleanup(t_gc **gc)
{
	if (!gc || !*gc)
		return ;
	gc_collect(*gc);
	free((*gc)->pointers);
	free((*gc)->sizes);
	hash_destroy((*gc)->hash_table);
	free(*gc);
	*gc = NULL;
}
