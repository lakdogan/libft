/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 20:31:52 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/25 22:42:46 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/garbage_collector.h"

/**
 * @brief Looks up a pointer in the hash table
 *
 * Searches for a pointer in the hash table
 * with O(1) average time complexity.
 *
 * @param table Hash table to search in
 * @param ptr Pointer to look up
 * @return t_hash_entry* Pointer to the entry if found, NULL otherwise
 */
t_hash_entry	*hash_lookup(t_hash_table *table, void *ptr)
{
	size_t			index;
	t_hash_entry	*entry;

	if (!table || !ptr)
		return (NULL);
	index = hash_function(ptr, table->size);
	entry = table->buckets[index];
	while (entry)
	{
		if (entry->key == ptr)
			return (entry);
		entry = entry->next;
	}
	return (NULL);
}

/**
 * @brief Removes a pointer from the hash table
 *
 * Finds and removes a pointer entry from the hash table.
 *
 * @param table Hash table to remove from
 * @param ptr Pointer to remove
 * @return int 1 if found and removed, 0 otherwise
 */
int	hash_remove(t_hash_table *table, void *ptr)
{
	size_t			index;
	t_hash_entry	*entry;
	t_hash_entry	*prev;

	if (!table || !ptr)
		return (0);
	index = hash_function(ptr, table->size);
	entry = table->buckets[index];
	prev = NULL;
	while (entry)
	{
		if (entry->key == ptr)
		{
			if (prev)
				prev->next = entry->next;
			else
				table->buckets[index] = entry->next;
			free(entry);
			return (1);
		}
		prev = entry;
		entry = entry->next;
	}
	return (0);
}

/**
 * @brief Destroys a hash table and frees all memory
 *
 * Cleans up all memory associated with the hash table structure.
 *
 * @param table Hash table to destroy
 */
void	hash_destroy(t_hash_table *table)
{
	size_t			i;
	t_hash_entry	*entry;
	t_hash_entry	*next;

	if (!table)
		return ;
	i = 0;
	while (i < table->size)
	{
		entry = table->buckets[i];
		while (entry)
		{
			next = entry->next;
			free(entry);
			entry = next;
		}
		i++;
	}
	free(table->buckets);
	free(table);
}
