/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isometric_y.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 23:19:19 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:05:17 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/**
 * @brief Computes the isometric y-coordinate.
 *
 * Calculates the isometric projection on the y-axis.
 * Uses the formula:
 *   screen_y = (x + y) * sin(30°) - z
 * where 30° is converted to radians.
 *
 * @param x The original x-coordinate.
 * @param y The original y-coordinate.
 * @param z The original z-coordinate.
 * @return The computed isometric y-coordinate.
 */
float	ft_isometric_y(float x, float y, float z)
{
	float	screen_y;

	screen_y = (x + y) * sin(30 * M_PI / 180) - z;
	return (screen_y);
}
