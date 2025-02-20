/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:45:30 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/19 23:14:34 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/*
 * Normalizes a 3D vector, converting it to a unit vector.
 *
 * Formula:
 *   Normalized Vector (Û) = Vector / |Vector|
 *   - Û_x = Vector_x / |Vector|
 *   - Û_y = Vector_y / |Vector|
 *   - Û_z = Vector_z / |Vector|
 *
 * A normalized vector:
 *   - Has a magnitude of 1.
 *   - Points in the same direction as the original vector.
 *   - Is useful in physics, computer graphics, and linear algebra.
 *
 * Parameters:
 *   raw_cross_product: A pointer to the original 3D vector
 *  (array of 3 floats).
 *   magnitude: The magnitude (length) of the original vector.
 *   cross_product: A pointer to a pre-allocated array where the
 * resulting unit vector will be stored.
 *
 * Returns:
 *   Nothing (void). The normalized vector is stored in 'cross_product'.
 *
 * Notes:
 *   - The function assumes 'magnitude' is nonzero. If normalization
 * is required only for nonzero vectors,
 *     it should be checked before calling this function.
 */
void	ft_normalize(float *raw_cross_product, float magnitude,
		float *cross_product)
{
	cross_product[0] = raw_cross_product[0] / magnitude;
	cross_product[1] = raw_cross_product[1] / magnitude;
	cross_product[2] = raw_cross_product[2] / magnitude;
}
