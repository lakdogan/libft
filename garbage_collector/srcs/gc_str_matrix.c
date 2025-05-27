/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_str_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:58:42 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/27 17:59:34 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/garbage_collector.h"

/**
 * @brief Allocates a 2D string matrix
 *
 * Creates a matrix of strings where each row has a specified number of columns.
 * Each element of the matrix can be assigned a string.
 * The matrix is NULL-terminated for easier traversal.
 *
 * @param gc Pointer to the garbage collector
 * @param rows Number of rows
 * @param cols Number of columns in each row
 * @return char*** Allocated 2D string matrix or NULL on failure
 *
 * @example
 * // Create a 3x4 string matrix
 * char ***matrix = gc_str_matrix_create(gc, 3, 4);
 * // Assign strings
 * matrix[0][0] = gc_strdup(gc, "Hello");
 * matrix[1][2] = gc_strdup(gc, "World");
 */
char	***gc_str_matrix_create(t_gc *gc, size_t rows, size_t cols)
{
	char	***matrix;
	size_t	i;

	matrix = (char ***)gc_calloc(gc, rows + 1, sizeof(char **));
	if (!matrix)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		matrix[i] = gc_str_array_create(gc, cols);
		if (!matrix[i])
			return (NULL);
		i++;
	}
	return (matrix);
}

/**
 * @brief Duplicates a 2D string matrix
 *
 * Creates a deep copy of a 2D string matrix, including all strings.
 * The source matrix must be NULL-terminated.
 *
 * @param gc Pointer to the garbage collector
 * @param src Source matrix to duplicate
 * @return char*** Duplicated matrix or NULL on failure
 */
char	***gc_str_matrix_dup(t_gc *gc, char ***src)
{
	char	***matrix;
	size_t	i;
	size_t	rows;

	if (!src)
		return (NULL);
	rows = 0;
	while (src[rows])
		rows++;
	matrix = gc_str_matrix_create(gc, rows, 0);
	if (!matrix)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		matrix[i] = gc_str_array_dup(gc, src[i]);
		if (!matrix[i])
			return (NULL);
		i++;
	}
	return (matrix);
}
