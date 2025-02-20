/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unit_vector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 04:32:56 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/19 23:15:37 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/*
 * Calculates the unit vector of a given 3D vector.
 *
 * Formula:
 *   Unit Vector (Â) = A / |A|
 *   - Â_x = A_x / |A|
 *   - Â_y = A_y / |A|
 *   - Â_z = A_z / |A|
 *
 * A unit vector:
 *   - Has a magnitude of 1.
 *   - Points in the same direction as the original vector.
 *   - Is useful for normalizing vectors in physics, graphics,
 *	and math applications.
 *
 * Parameters:
 *   a: A pointer to the original 3D vector (array of 3 floats).
 *
 *   unit_vector: A pointer to a pre-allocated array where the
 *   resulting unit vector will be stored.
 *
 * Returns:
 *   Nothing (void). The result is stored in 'unit_vector'.
 *
 * Notes:
 *   - Ensure 'unit_vector' is allocated before calling this function.
 *   - If 'a' is a zero vector, this function may cause division by zero
 *  (should be handled if needed).
 */
void	ft_unit_vector(float *a, float *unit_vector)
{
	float	magnitude_a;

	magnitude_a = ft_magnitude(a);
	unit_vector[0] = a[0] / magnitude_a;
	unit_vector[1] = a[1] / magnitude_a;
	unit_vector[2] = a[2] / magnitude_a;
}
