/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_int_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 21:02:28 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/27 00:11:41 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/garbage_collector.h"

/**
 * @brief Allocates a 2D integer matrix
 *
 * @param gc Pointer to the garbage collector
 * @param rows Number of rows
 * @param cols Number of columns
 * @return int** Allocated matrix or NULL on failure
 */
int	**gc_int_matrix_create(t_gc *gc, size_t rows, size_t cols)
{
	int		**matrix;
	size_t	i;

	matrix = (int **)gc_calloc(gc, rows + 1, sizeof(int *));
	if (!matrix)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		matrix[i] = gc_int_array_create(gc, cols);
		if (!matrix[i])
			return (NULL);
		i++;
	}
	return (matrix);
}
