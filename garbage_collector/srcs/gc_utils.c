/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 22:49:17 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/25 22:42:31 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/garbage_collector.h"

/**
 * @brief Checks if a pointer is managed by the garbage collector
 *
 * Uses the hash table to efficiently determine if a pointer is tracked
 * by the garbage collector with O(1) average time complexity.
 *
 * @param gc Pointer to the garbage collector
 * @param ptr Pointer to check
 * @return int 1 if valid, 0 if not
 */
int	is_valid_block(t_gc *gc, void *ptr)
{
	if (!ptr || !gc || !gc->hash_table)
		return (0);
	return (hash_lookup(gc->hash_table, ptr) != NULL);
}

/**
 * @brief Gets the size of a memory block
 *
 * Retrieves the size of an allocation from the hash table with O(1)
 * average time complexity.
 *
 * @param gc Pointer to the garbage collector
 * @param ptr Pointer to the memory block
 * @return size_t Size of the block, or 0 if not found
 */
size_t	get_block_size(t_gc *gc, void *ptr)
{
	t_hash_entry	*entry;

	if (!ptr || !gc || !gc->hash_table)
		return (0);
	entry = hash_lookup(gc->hash_table, ptr);
	if (!entry)
		return (0);
	return (entry->size);
}

/**
 * @brief Gets the total memory managed by the garbage collector
 *
 * Calculates the sum of all allocation sizes by iterating through
 * the hash table entries. This provides an accurate measurement of
 * memory usage with O(n) complexity where n is the number of allocations.
 *
 * @param gc Pointer to the garbage collector
 * @return size_t Total allocated memory in bytes
 */
size_t	gc_get_total_memory(t_gc *gc)
{
	size_t			total;
	size_t			i;
	t_hash_entry	*entry;

	total = 0;
	i = 0;
	if (!gc || !gc->hash_table)
		return (0);
	while (i < gc->hash_table->size)
	{
		entry = gc->hash_table->buckets[i];
		while (entry)
		{
			total += entry->size;
			entry = entry->next;
		}
		i++;
	}
	return (total);
}
