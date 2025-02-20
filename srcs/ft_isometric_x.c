/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isometric_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 23:17:44 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:04:56 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/**
 * @brief Computes the isometric x-coordinate.
 *
 * Calculates the isometric projection on the x-axis.
 * Uses the formula:
 *   screen_x = (x - y) * cos(30°)
 * where 30° is converted to radians.
 *
 * @param x The original x-coordinate.
 * @param y The original y-coordinate.
 * @return The computed isometric x-coordinate.
 */
float	ft_isometric_x(float x, float y)
{
	float	screen_x;

	screen_x = (x - y) * cos(30 * M_PI / 180);
	return (screen_x);
}
