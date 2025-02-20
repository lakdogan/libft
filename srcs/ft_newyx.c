/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newyx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:31:41 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:23:54 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/**
 * @brief Computes the new y-coordinate after rotation.
 *
 * Applies a rotation transformation to the original y and z values.
 * Uses the provided angle in radians.
 *
 * Formula:
 *   new_y = orig_y * cos(angle_rad) - orig_z * sin(angle_rad)
 *
 * @param orig_y The original y-coordinate.
 * @param orig_z The original z-coordinate.
 * @param angle_rad The rotation angle in radians.
 * @return The new y-coordinate.
 */
float	ft_newyx(float orig_y, float orig_z, float angle_rad)
{
	float	new_y;

	new_y = orig_y * cos(angle_rad) - orig_z * sin(angle_rad);
	return (new_y);
}
