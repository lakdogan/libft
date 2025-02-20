/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newyz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:34:06 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:24:15 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/**
 * @brief Computes the new y-coordinate after rotation.
 *
 * Applies a rotation transformation to the original x and y values,
 * using the provided angle in radians.
 *
 * Formula:
 *   new_y = orig_x * sin(angle_rad) + orig_y * cos(angle_rad)
 *
 * @param orig_x The original x-coordinate.
 * @param orig_y The original y-coordinate.
 * @param angle_rad The rotation angle in radians.
 * @return The transformed y-coordinate.
 */
float	ft_newyz(float orig_x, float orig_y, float angle_rad)
{
	float	new_y;

	new_y = orig_x * sin(angle_rad) + orig_y * cos(angle_rad);
	return (new_y);
}
