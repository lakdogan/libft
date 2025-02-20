/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tiltang.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:36:58 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:34:54 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/**
 * @brief Computes the tilt angle in degrees.
 *
 * Calculates the angle of tilt using the arctangent of 
 * (height / distance) and converts the result from radians to degrees.
 *
 * @param height The height component.
 * @param distance The distance component.
 * @return The tilt angle in degrees.
 */
float	ft_tiltang(float height, float distance)
{
	float	tilt_angle;

	tilt_angle = atan(height / distance) * (180 / M_PI);
	return (tilt_angle);
}
