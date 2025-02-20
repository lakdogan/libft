/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newxz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:50:03 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:23:32 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/**
 * @brief Calculates the new x-coordinate after rotation.
 *
 * Applies a rotation transformation on the original x and y coordinates,
 * using the provided angle in radians.
 *
 * Formula: new_x = orig_x * cos(angle_rad) - orig_y * sin(angle_rad)
 *
 * @param orig_x The original x-coordinate.
 * @param orig_y The original y-coordinate.
 * @param angle_rad The rotation angle in radians.
 * @return The transformed x-coordinate.
 */
float	ft_newxz(float orig_x, float orig_y, float angle_rad)
{
	float	new_x;

	new_x = orig_x * cos(angle_rad) - orig_y * sin(angle_rad);
	return (new_x);
}
