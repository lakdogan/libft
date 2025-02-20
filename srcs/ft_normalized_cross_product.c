/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalized_cross_product.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:13:43 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/19 23:14:37 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/*
 * Computes the cross product of two 3D vectors and normalizes the result.
 *
 * The cross product of two vectors results in:
 *   - A vector perpendicular to both input vectors.
 *   - A magnitude proportional to the sine of the angle between them.
 *   - A direction determined by the right-hand rule.
 *
 * This function:
 *   1. Computes the raw cross product using `ft_compute_cross_product`.
 *   2. Calculates the magnitude of the cross product using `ft_magnitude`.
 *   3. If the magnitude is zero (vectors are parallel),
 *	it sets the result to (0,0,0).
 *   4. Otherwise,
 *	it normalizes the cross product using `ft_normalize` to produce
 *  a unit vector.
 *
 * Formula:
 *   A × B = (A_y * B_z - A_z * B_y,
 *            A_z * B_x - A_x * B_z,
 *            A_x * B_y - A_y * B_x)
 *
 * Parameters:
 *   a: A pointer to the first 3D vector (array of 3 floats).
 *   b: A pointer to the second 3D vector (array of 3 floats).
 *
 *   cross_product: A pointer to a pre-allocated array where the
 *  final unit vector will be stored.
 *
 * Returns:
 *   Nothing (void). The normalized cross product is stored in 'cross_product'.
 *
 * Notes:
 *   - If vectors 'a' and 'b' are parallel, the cross product is (0,0,0).
 *   - If normalization is not needed, use `ft_compute_cross_product` instead.
 */
void	ft_normalized_cross_product(float *a, float *b, float *cross_product)
{
	float	raw_cross_product_vector[3];
	float	magnitude_raw_cross_product;

	ft_compute_cross_product(a, b, raw_cross_product_vector);
	magnitude_raw_cross_product = ft_magnitude(raw_cross_product_vector);
	if (magnitude_raw_cross_product == 0.000000)
	{
		cross_product[0] = 0;
		cross_product[1] = 0;
		cross_product[2] = 0;
		return ;
	}
	ft_normalize(raw_cross_product_vector, magnitude_raw_cross_product,
		cross_product);
}
