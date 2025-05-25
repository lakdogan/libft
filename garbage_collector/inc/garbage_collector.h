/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:49:25 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/25 22:53:25 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_COLLECTOR_H
# define GARBAGE_COLLECTOR_H

/**
 * @file garbage_collector.h
 * @brief Memory management system that automatically tracks 
 * and frees allocations
 *
 * This garbage collector provides automated memory management for C programs,
 * tracking allocated memory and allowing batch cleanup operations. It helps
 * prevent memory leaks by maintaining an internal registry of all allocations.
 *
 * Features:
 * - Memory tracking through malloc/calloc/realloc wrappers
 * - Automatic expansion of internal tracking arrays
 * - Selective or batch memory cleanup
 * - Memory leak prevention
 * - Allocation status inspection utilities
 *
 * Example usage:
 * @code
 * // Create a garbage collector
 * t_gc *gc = gc_create();
 * if (!gc)
 *     return (1);
 *
 * // Allocate memory that will be automatically tracked
 * char *str = gc_strdup(gc, "Hello World");
 * int *numbers = gc_malloc(gc, 5 * sizeof(int));
 *
 * // Use the memory as normal
 * numbers[0] = 42;
 * numbers[1] = 100;
 * printf("%s, %d\n", str, numbers[0]);
 *
 * // Selectively free if needed before end of program
 * gc_free(gc, str);
 *
 * // Allocate more memory
 * char **array = gc_calloc(gc, 10, sizeof(char *));
 * array[0] = gc_strdup(gc, "First item");
 *
 * // Resize memory
 * numbers = gc_realloc(gc, numbers, 10 * sizeof(int));
 *
 * // When done, clean up everything with one call
 * gc_cleanup(&gc);
 * // gc is now NULL, and all memory has been freed
 * @endcode
 *
 * @author lakdogan
 */

# include "../../inc/libft.h"
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// Constants
# define GC_INITIAL_CAPACITY 32
# define GC_GROWTH_FACTOR 2
# define GC_NOT_FOUND SIZE_MAX
# define NULL_TERMINATOR 1

/**
 * @brief Hash table entry structure
 *
 * Represents a single entry in the hash table, storing a pointer,
 * its size, and a link to the next entry in case of hash collisions.
 *
 * *key: Pointer being tracked
 * size: Size of the allocation
 * *next: Next entry in the collision chain
 */
typedef struct s_hash_entry
{
	void				*key;
	size_t				size;
	struct s_hash_entry	*next;
}						t_hash_entry;

/**
 * @brief Hash table structure
 *
 * A simple hash table implementation for O(1) pointer lookups.
 *
 * size: Number of buckets in the table
 * **buckets: Array of bucket heads
 */
typedef struct s_hash_table
{
	size_t				size;
	t_hash_entry		**buckets;
}						t_hash_table;

/**
 * @brief Array information structure
 *
 * Contains information needed for array reallocation.
 *
 * old_count: Count of elements in original array
 * new_count: Count of elements in resized array
 * elem_size: Size of each element in bytes
 */
typedef struct s_array_info
{
	size_t				old_count;
	size_t				new_count;
	size_t				elem_size;
}						t_array_info;

/**
 * @brief Main garbage collector structure
 *
 * Tracks allocated memory pointers, their sizes, and maintains a hash table
 * for O(1) lookup performance.
 *
 * **pointers: Array of tracked pointers
 * *sizes: Array of allocation sizes
 * count: Number of tracked allocations
 * capacity: Capacity of tracking arrays
 * *hash_table: Hash table for fast lookup
 */
typedef struct s_gc
{
	void				**pointers;
	size_t				*sizes;
	size_t				count;
	size_t				capacity;
	t_hash_table		*hash_table;
}						t_gc;

// 1. Core-functions
t_gc					*gc_create(void);
void					gc_collect(t_gc *gc);
void					gc_cleanup(t_gc **gc);
int						gc_expand(t_gc *gc);

// 2. Memorymanagment-functions
void					*gc_malloc(t_gc *gc, size_t size);
void					*gc_calloc(t_gc *gc, size_t nmemb, size_t size);
void					*gc_realloc(t_gc *gc, void *ptr, size_t size);
void					gc_register(t_gc *gc, void *ptr, size_t size);
void					gc_free(t_gc *gc, void *ptr);
void					*gc_memcpy(t_gc *gc, const void *src, size_t size);
t_array_info			create_array_info(size_t old_count, size_t new_count,
							size_t elem_size);
void					*gc_realloc_array(t_gc *gc, void *ptr,
							t_array_info info);

// 3. String-functions
char					*gc_strdup(t_gc *gc, const char *s);
char					*gc_substr(t_gc *gc, const char *s, unsigned int start,
							size_t len);
char					*gc_strjoin(t_gc *gc, const char *s1, const char *s2);
char					*gc_strjoin_3(t_gc *gc, const char *s1, const char *s2,
							const char *s3);
char					*gc_strtrim(t_gc *gc, const char *s1, const char *set);
char					**gc_split(t_gc *gc, const char *s, char c);
char					*gc_itoa(t_gc *gc, int n);

// 4. List-functions
t_list					*gc_lstnew(t_gc *gc, void *content);
t_list					*gc_lstmap(t_gc *gc, t_list *lst, void *(*f)(void *),
							void (*del)(void *));
void					gc_lstadd_back(t_gc *gc, t_list **lst, void *content);

// 5. Helper-functions
int						is_valid_block(t_gc *gc, void *ptr);
size_t					get_block_size(t_gc *gc, void *ptr);

// 6. Utility-functions
size_t					gc_get_total_memory(t_gc *gc);

// 7. Hash table functions
t_hash_table			*hash_create(size_t size);
int						hash_insert(t_hash_table *table, void *ptr,
							size_t size);
t_hash_entry			*hash_lookup(t_hash_table *table, void *ptr);
int						hash_remove(t_hash_table *table, void *ptr);
void					hash_destroy(t_hash_table *table);
size_t					hash_function(void *ptr, size_t table_size);

#endif
