/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getrad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:48:03 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:03:13 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/**
 * @brief Converts degrees to radians.
 *
 * Multiplies the input degree by M_PI and divides by 180.
 *
 * @param degree Angle in degrees.
 * @return Angle in radians.
 */
float	ft_getrad(float degree)
{
	float	radians;

	radians = degree * M_PI / 180;
	return (radians);
}
