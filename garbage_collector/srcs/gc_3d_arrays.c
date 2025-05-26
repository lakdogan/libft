/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_3d_arrays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 21:05:33 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/27 00:14:14 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/garbage_collector.h"

/**
 * @brief Allocates a 3D integer array
 *
 * @param gc Pointer to the garbage collector
 * @param dim1 First dimension size
 * @param dim2 Second dimension size
 * @param dim3 Third dimension size
 * @return int*** Allocated 3D array or NULL on failure
 */
int	***gc_int_3d_create(t_gc *gc, size_t dim1, size_t dim2, size_t dim3)
{
	int		***array;
	size_t	i;
	size_t	j;

	array = (int ***)gc_calloc(gc, dim1 + 1, sizeof(int **));
	if (!array)
		return (NULL);
	i = 0;
	while (i < dim1)
	{
		array[i] = (int **)gc_calloc(gc, dim2 + 1, sizeof(int *));
		if (!array[i])
			return (NULL);
		j = 0;
		while (j < dim2)
		{
			array[i][j] = (int *)gc_calloc(gc, dim3, sizeof(int));
			if (!array[i][j])
				return (NULL);
			j++;
		}
		i++;
	}
	return (array);
}

/**
 * @brief Allocates a 3D string array (char***)
 *
 * Creates a three-dimensional array of strings where:
 * - array is a char*** (pointer to array of array of strings)
 * - array[i] is a char** (pointer to array of strings)
 * - array[i][j] is a char* array (array of string pointers)
 * - Each array[i][j][k] can be assigned a string
 *
 * Each dimension is NULL-terminated for easier traversal.
 *
 * @param gc Pointer to the garbage collector
 * @param dim1 First dimension size
 * @param dim2 Second dimension size
 * @param str_count Number of string pointers in each innermost array
 * @return char*** Allocated 3D string array or NULL on failure
 *
 * @example
 * // Create a 2x2 array with 3 strings at each position
 * char ***cube = gc_str_3d_create(gc, 2, 2, 3);
 * // Assign strings
 * cube[0][0][0] = gc_strdup(gc, "Hello");
 * cube[0][0][1] = gc_strdup(gc, "World");
 * cube[1][1][2] = gc_strdup(gc, "Example");
 */
char	***gc_str_3d_create(t_gc *gc, size_t dim1, size_t dim2,
		size_t str_count)
{
	char	***array;
	size_t	i;
	size_t	j;

	array = (char ***)gc_calloc(gc, dim1 + 1, sizeof(char **));
	if (!array)
		return (NULL);
	i = 0;
	while (i < dim1)
	{
		array[i] = (char **)gc_calloc(gc, dim2 + 1, sizeof(char *));
		if (!array[i])
			return (NULL);
		j = 0;
		while (j < dim2)
		{
			array[i][j] = gc_calloc(gc, str_count + 1, sizeof(char *));
			if (!array[i][j])
				return (NULL);
			j++;
		}
		i++;
	}
	return (array);
}
