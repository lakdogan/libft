/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:49:25 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/28 21:45:39 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_COLLECTOR_H
# define GARBAGE_COLLECTOR_H

/**
 * @file garbage_collector.h
 * @brief Memory management system that automatically tracks
 * and frees allocations
 *
 * This garbage collector provides automated
 * memory management for C programs,
 * tracking allocated memory and allowing
 * batch cleanup operations. It helps
 * prevent memory leaks by maintaining an
 * internal registry of all allocations.
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
 * @section Memory Management Functions
 *
 * The garbage collector provides direct replacements for standard memory
 * management functions with automatic tracking:
 *
 * @code
 * // Allocate memory
 * void *ptr = gc_malloc(gc, 1024);
 *
 * // Allocate zeroed memory
 * int *array = gc_calloc(gc, 10, sizeof(int));
 *
 * // Resize existing memory
 * ptr = gc_realloc(gc, ptr, 2048);
 *
 * // Free memory early (optional)
 * gc_free(gc, array);
 *
 * // Register externally allocated memory
 * void *external = malloc(100);
 * gc_register(gc, external, 100);
 *
 * // Create a copy of existing memory
 * void *src_data = get_data();
 * void *copy = gc_memcpy(gc, src_data, data_size);
 * @endcode
 *
 * @section String Management Functions
 *
 * The garbage collector provides string handling
 * functions that track allocations:
 *
 * @code
 * // Duplicate a string
 * char *str = gc_strdup(gc, "Hello World");
 *
 * // Extract part of a string
 * char *sub = gc_substr(gc, "Hello World", 6, 5);  // "World"
 *
 * // Combine strings
 * char *joined = gc_strjoin(gc, "Hello", " World");
 * char *three = gc_strjoin_3(gc, "Hello", " ", "World");
 *
 * // Trim characters
 * char *trimmed = gc_strtrim(gc, " Hello World ", " ");
 *
 * // Split a string
 * char **words = gc_split(gc, "Hello World Program", ' ');
 * // words[0] = "Hello", words[1] = "World", words[2] = "Program",
 * 		words[3] = NULL
 *
 * // Convert integer to string
 * char *num_str = gc_itoa(gc, 42);
 * @endcode
 *
 * @section Array Management Functions
 *
 * The garbage collector provides specialized functions for handling various
 * types of arrays - from simple 1D arrays to complex 3D arrays. All memory
 * allocations are tracked by the garbage collector for automatic cleanup.
 *
 * 1D Array Functions:
 * - gc_int_array_create: Create a 1D integer array
 * - gc_int_array_dup: Duplicate a 1D integer array
 * - gc_str_array_create: Create a NULL-terminated string array
 * - gc_str_array_dup: Duplicate a NULL-terminated string array
 *
 * 2D Array Functions:
 * - gc_int_matrix_create: Create a 2D integer matrix
 *
 * 3D Array Functions:
 * - gc_int_3d_create: Create a 3D integer array
 * - gc_str_3d_create: Create a 3D string array
 *
 * Example usage:
 * @code
 * // 1D integer array
 * int *numbers = gc_int_array_create(gc, 10);
 * for (int i = 0; i < 10; i++)
 *     numbers[i] = i * 2;
 *
 * // Copy an existing integer array
 * int original[5] = {10, 20, 30, 40, 50};
 * int *copy = gc_int_array_dup(gc, original, 5);
 *
 * // 1D string array (NULL-terminated)
 * char **args = gc_str_array_create(gc, 3); // Allocates space for 3 strings
 *	+ NULL
 * args[0] = gc_strdup(gc, "program");
 * args[1] = gc_strdup(gc, "--verbose");
 * args[2] = gc_strdup(gc, "file.txt");
 * // args[3] is already NULL (from calloc)
 *
 * // Copy an existing string array
 * char **args_copy = gc_str_array_dup(gc, args);
 *
 * // 2D integer matrix
 * int **matrix = gc_int_matrix_create(gc, 3, 4); // 3 rows, 4 columns
 * matrix[0][0] = 1;   // Top-left element
 * matrix[2][3] = 100; // Bottom-right element
 *
 * * // 2D integer matrix
 * int **matrix = gc_int_matrix_create(gc, 3, 4); // 3 rows, 4 columns
 * matrix[0][0] = 1;   // Top-left element
 * matrix[2][3] = 100; // Bottom-right element
 *
 * // 2D string matrix
 * char ***str_matrix = gc_str_matrix_create(gc, 3, 4); // 3 rows, 4 columns
 * str_matrix[0][0] = gc_strdup(gc, "Hello");
 * str_matrix[0][1] = gc_strdup(gc, "World");
 * str_matrix[1][0] = gc_strdup(gc, "This");
 * str_matrix[1][1] = gc_strdup(gc, "is");
 * str_matrix[1][2] = gc_strdup(gc, "a");
 * str_matrix[1][3] = gc_strdup(gc, "test");
 *
 * // Copy the string matrix
 * char ***str_matrix_copy = gc_str_matrix_dup(gc, str_matrix);
 *
 * // 3D integer array
 * int ***cube = gc_int_3d_create(gc, 2, 3, 4);
 * // First dimension has 2 elements
 * // Second dimension has 3 elements
 * // Third dimension has 4 elements
 * cube[0][0][0] = 42; // First element
 * cube[1][2][3] = 99; // Last element
 *
 * // 3D string array
 * char ***str_cube = gc_str_3d_create(gc, 2, 2, 2);
 * str_cube[0][0][0] = gc_strdup(gc, "Hello");
 * str_cube[0][0][1] = gc_strdup(gc, "World");
 * str_cube[1][1][0] = gc_strdup(gc, "Goodbye");
 * str_cube[1][1][1] = gc_strdup(gc, "Now");
 * @endcode
 *
 * @section Linked List Functions
 *
 * The garbage collector provides functions for working with linked lists
 * where both the list nodes and their contents are automatically tracked:
 *
 * @code
 * // Create a new list node
 * t_list *node = gc_lstnew(gc, data_pointer);
 *
 * // Build a list by adding nodes to the back
 * t_list *list = NULL;
 * gc_lstadd_back(gc, &list, "first");
 * gc_lstadd_back(gc, &list, "second");
 * gc_lstadd_back(gc, &list, "third");
 * // list -> "first" -> "second" -> "third" -> NULL
 *
 * // Build a list by adding nodes to the front
 * t_list *stack = NULL;
 * gc_lstadd_front(gc, &stack, "third");
 * gc_lstadd_front(gc, &stack, "second");
 * gc_lstadd_front(gc, &stack, "first");
 * // stack -> "first" -> "second" -> "third" -> NULL
 *
 * // Create a full copy of a list
 * t_list *list_copy = gc_lstdup(gc, list);
 *
 * // Create a list from an array
 * char *items[] = {"apple", "banana", "cherry", NULL};
 * t_list *fruit_list = gc_lst_from_array(gc, (void **)items);
 *
 * // Create a sublist (like substring but for lists)
 * t_list *sublist = gc_lstsub(gc, fruit_list, 1, 2); // Start at index 1,
 * take 2 items
 * // sublist -> "banana" -> "cherry" -> NULL
 *
 * // Transform list contents with a mapping function
 * t_list *uppercase_list = gc_lstmap(gc, list, to_uppercase, free_string);
 * @endcode
 *
 * @section Utility Functions
 *
 * The garbage collector provides utility functions for examining
 * and managing memory:
 *
 * @code
 * // Check if a pointer is valid (tracked by the GC)
 * if (is_valid_block(gc, ptr)) {
 *     // Do something with ptr
 * }
 *
 * // Get the size of an allocated block
 * size_t size = get_block_size(gc, ptr);
 *
 * // Get total memory usage tracked by the GC
 * size_t total = gc_get_total_memory(gc);
 * printf("Current memory usage: %zu bytes\n", total);
 * @endcode
 *
 * @section Generic Structure Functions
 *
 * The garbage collector provides generic functions for working with any
 * custom data structures, handling memory allocation and duplication
 * in a type-agnostic way:
 *
 * @code
 * // Define a custom structure
 * typedef struct s_person
 * {
 *     char *name;
 *     int age;
 *     float height;
 * } t_person;
 *
 * // Allocate a single structure (zeroed)
 * t_person *person = gc_alloc_struct(gc, sizeof(t_person));
 * person->name = gc_strdup(gc, "John Doe");
 * person->age = 30;
 * person->height = 1.85;
 *
 * // Create a shallow copy of a structure
 * t_person *copy = gc_duplicate_struct(gc, person, sizeof(t_person));
 * // Note: shallow copy means pointers within are not duplicated
 * // To fully duplicate, also copy any internal pointers:
 * copy->name = gc_strdup(gc, person->name);
 *
 * // Allocate an array of structures
 * t_person *people = gc_alloc_struct_array(gc, 10, sizeof(t_person));
 * people[0].name = gc_strdup(gc, "Alice");
 * people[1].name = gc_strdup(gc, "Bob");
 *
 * // Works with any structure type
 * typedef struct s_point { double x, y, z; } t_point;
 * t_point *points = gc_alloc_struct_array(gc, 100, sizeof(t_point));
 *
 * // All memory is automatically tracked and freed
 * gc_cleanup(&gc);
 *
 *
 * // Binary tree example
 * // Define a binary tree node
 * typedef struct s_btree_node
 * {
 *     int value;
 *     struct s_btree_node *left;
 *     struct s_btree_node *right;
 * } t_btree_node;
 *
 * // Create a root node
 * t_btree_node *root = gc_alloc_struct(gc, sizeof(t_btree_node));
 * root->value = 10;
 *
 * // Add child nodes
 * root->left = gc_alloc_struct(gc, sizeof(t_btree_node));
 * root->left->value = 5;
 * root->left->left = NULL;
 * root->left->right = NULL;
 *
 * root->right = gc_alloc_struct(gc, sizeof(t_btree_node));
 * root->right->value = 15;
 * root->right->left = NULL;
 * root->right->right = NULL;
 *
 * // Create a copy of a subtree
 * t_btree_node *subtree = gc_duplicate_struct
 * 								(gc, root->left, sizeof(t_btree_node));
 *
 * // Create an array of tree nodes (e.g., for level-order storage)
 * t_btree_node *nodes = gc_alloc_struct_array(gc, 7, sizeof(t_btree_node));
 *
 * // All memory automatically freed by garbage collector
 * gc_cleanup(&gc);
 *
 * @endcode
 *
 *
 * All allocations will be automatically freed when gc_cleanup is called.
 *
 * @author lakdogan
 */

# include "../../inc/libft.h"
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// Constants
# define GC_INITIAL_CAPACITY 1000
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
char					**gc_str_array_dup(t_gc *gc, char **src);
char					**gc_str_array_create(t_gc *gc, size_t size);
char					***gc_str_matrix_create(t_gc *gc, size_t rows,
							size_t cols);
char					***gc_str_matrix_dup(t_gc *gc, char ***src);
char					*gc_safe_strjoin(t_gc *gc, const char *s1,
							const char *s2);
// 4. Integer array functions

int						*gc_int_array_create(t_gc *gc, size_t size);
int						*gc_int_array_dup(t_gc *gc, const int *src,
							size_t size);

// 5. Integer matrix functions

int						**gc_int_matrix_create(t_gc *gc, size_t rows,
							size_t cols);

// 6. 3D array functions

int						***gc_int_3d_create(t_gc *gc, size_t dim1, size_t dim2,
							size_t dim3);
char					***gc_str_3d_create(t_gc *gc, size_t dim1, size_t dim2,
							size_t str_count);

// 7. List-functions

t_list					*gc_lstnew(t_gc *gc, void *content);
t_list					*gc_lstmap(t_gc *gc, t_list *lst, void *(*f)(t_gc *,
								void *), void (*del)(void *));
void					gc_lstadd_back(t_gc *gc, t_list **lst, void *content);
void					gc_lstadd_front(t_gc *gc, t_list **lst, void *content);
t_list					*gc_lstdup(t_gc *gc, t_list *lst);
t_list					*gc_lst_from_array(t_gc *gc, void **array);
t_list					*gc_lstsub(t_gc *gc, t_list *lst, size_t start,
							size_t len);

// 8. Helper-functions

int						is_valid_block(t_gc *gc, void *ptr);
size_t					get_block_size(t_gc *gc, void *ptr);

// 9. Utility-functions

size_t					gc_get_total_memory(t_gc *gc);

// 10. Hash table functions

t_hash_table			*hash_create(size_t size);
int						hash_insert(t_hash_table *table, void *ptr,
							size_t size);
t_hash_entry			*hash_lookup(t_hash_table *table, void *ptr);
int						hash_remove(t_hash_table *table, void *ptr);
void					hash_destroy(t_hash_table *table);
size_t					hash_function(void *ptr, size_t table_size);

// 11. Generic structure functions

void					*gc_alloc_struct(t_gc *gc, size_t size);
void					*gc_duplicate_struct(t_gc *gc, const void *src,
							size_t size);
void					*gc_alloc_struct_array(t_gc *gc, size_t count,
							size_t struct_size);

#endif
