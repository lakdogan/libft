/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_angle_deg.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 02:58:46 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/19 23:15:32 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/*
 * Calculates the angle between two vectors using the dot product.
 *
 * Formula: θ = cos⁻¹((A * B) / (|A| |B|))
 * - A * B is the dot product of vectors A and B
 * - |A| and |B| are the magnitudes (lengths) of the vectors A and B
 *
 * The function acosf() calculates the arc cosine of the result,
	returning the angle in radians.
 * To convert the result to degrees, multiply by (180 / M_PI).
 *  * (180 / M_PI) == / M_PI * 180
 */
float	ft_vector_angle_deg(float *a, float *b)
{
	float	dot;
	float	angle_deg;
	float	magnitude_a;
	float	magnitude_b;

	magnitude_a = ft_magnitude(a);
	magnitude_b = ft_magnitude(b);
	dot = ft_dot_product(a, b);
	angle_deg = acosf(dot / (magnitude_a * magnitude_b)) * (180 / M_PI);
	return (angle_deg);
}
