/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_angle_rad.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:49:47 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/19 23:15:28 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/*
 * Computes the angle (in radians) between two 3D vectors.
 *
 * The angle between two vectors is determined using the dot product formula:
 *
 * Formula:
 *   cos(θ) = (A ⋅ B) / (|A| |B|)
 *
 * Steps:
 *   1. Compute the magnitudes of both vectors using `ft_magnitude`.
 *   2. Compute the dot product of the vectors using `ft_dot_product`.
 *   3. Use the inverse cosine function (acosf) to get the angle in degrees.
 *   4. Convert the degree result into radians using `ft_getrad`.
 *
 * Parameters:
 *   a: A pointer to the first 3D vector (array of 3 floats).
 *   b: A pointer to the second 3D vector (array of 3 floats).
 *
 * Returns:
 *   The angle (in radians) between the two vectors as a float.
 *
 * Notes:
 *   - If either vector has a magnitude of 0, this will cause division by zero.
 *   - Ensure that the input vectors are valid (i.e., not zero vectors).
 *   - The function assumes `acosf` input is in the
 *     range [-1,1] to avoid NaN issues.
 */
float	ft_vector_angle_rad(float *a, float *b)
{
	float	dot;
	float	angle_rad;
	float	magnitude_a;
	float	magnitude_b;

	magnitude_a = ft_magnitude(a);
	magnitude_b = ft_magnitude(b);
	dot = ft_dot_product(a, b);
	angle_rad = acosf(dot / (magnitude_a * magnitude_b));
	return (angle_rad);
}
