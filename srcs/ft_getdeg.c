/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdeg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:04:42 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:02:16 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/**
 * @brief Converts radians to degrees.
 *
 * Divides the input angle (in radians)
 * by M_PI and multiplies by 180.
 *
 * @param radians Angle in radians.
 * @return Angle in degrees.
 */
float	ft_getdeg(float radians)
{
	float	degree;

	degree = radians / M_PI * 180;
	return (degree);
}
