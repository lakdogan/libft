/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 20:31:20 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/25 22:43:10 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/garbage_collector.h"

/**
 * @brief Simple hash function for pointers
 *
 * @param ptr Pointer to hash
 * @param table_size Size of the hash table
 * @return size_t Hash value (bucket index)
 */
size_t	hash_function(void *ptr, size_t table_size)
{
	return ((size_t)ptr % table_size);
}

/**
 * @brief Creates a new hash table
 *
 * Allocates and initializes a new hash table
 * with the specified number of buckets.
 *
 * @param size Number of buckets in the hash table
 * @return t_hash_table* Pointer to the new hash table,
 * or NULL if creation fails
 */
t_hash_table	*hash_create(size_t size)
{
	t_hash_table	*table;
	size_t			i;

	table = malloc(sizeof(t_hash_table));
	if (!table)
		return (NULL);
	table->size = size;
	table->buckets = malloc(sizeof(t_hash_entry *) * size);
	if (!table->buckets)
	{
		free(table);
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		table->buckets[i] = NULL;
		i++;
	}
	return (table);
}

/**
 * @brief Inserts a pointer and its size into the hash table
 *
 * Adds a pointer to the hash table for O(1) lookups later.
 *
 * @param table Hash table to insert into
 * @param ptr Pointer to insert
 * @param size Size of the allocation
 * @return int 1 on success, 0 on failure
 */
int	hash_insert(t_hash_table *table, void *ptr, size_t size)
{
	size_t			index;
	t_hash_entry	*entry;
	t_hash_entry	*current;

	if (!table || !ptr)
		return (0);
	index = hash_function(ptr, table->size);
	entry = malloc(sizeof(t_hash_entry));
	if (!entry)
		return (0);
	entry->key = ptr;
	entry->size = size;
	entry->next = NULL;
	if (!table->buckets[index])
		table->buckets[index] = entry;
	else
	{
		current = table->buckets[index];
		while (current->next)
			current = current->next;
		current->next = entry;
	}
	return (1);
}
