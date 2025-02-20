/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_magnitude.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 02:12:38 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:20:50 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/**
 * @brief Computes the magnitude of a 3D vector.
 *
 * Calculates the square root of the sum of the squares
 * of the three elements of vector a.
 *
 * @param a Input vector (3 elements).
 * @return The magnitude (length) of the vector.
 */
float	ft_magnitude(float *a)
{
	float	magnitude;

	magnitude = sqrtf(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
	return (magnitude);
}
