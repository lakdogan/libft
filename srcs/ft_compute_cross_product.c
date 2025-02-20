/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compute_cross_product.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 04:00:57 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:01:28 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Computes the cross product of two 3D vectors.
 *
 * Calculates the cross product of vectors a and b,
 * and stores the result in the product array.
 *
 * @param a Input vector (3 elements).
 * @param b Input vector (3 elements).
 * @param product Array where the cross product is stored.
 */
void	ft_compute_cross_product(float *a, float *b, float *product)
{
	product[0] = a[1] * b[2] - a[2] * b[1];
	product[1] = a[2] * b[0] - a[0] * b[2];
	product[2] = a[0] * b[1] - a[1] * b[0];
}
