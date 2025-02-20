/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dot_product.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 02:03:05 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:01:56 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/**
 * @brief Computes the dot product of two 3D vectors.
 *
 * Calculates the sum of the products of the corresponding
 * elements of vectors a and b.
 *
 * @param a Input vector (3 elements).
 * @param b Input vector (3 elements).
 * @return The dot product as a float.
 */
float	ft_dot_product(float *a, float *b)
{
	float	dot_product;

	dot_product = a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
	return (dot_product);
}
