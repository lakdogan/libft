/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newxy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:33:38 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:23:10 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/**
 * @brief Calculates the new x-coordinate after rotation.
 *
 * Applies a rotation transformation to the original x and z coordinates,
 * using the provided angle in radians.
 *
 * Formula: new_x = orig_x * cos(angle_rad) + orig_z * sin(angle_rad)
 *
 * @param orig_x The original x-coordinate.
 * @param orig_z The original z-coordinate.
 * @param angle_rad The rotation angle in radians.
 * @return The transformed x-coordinate.
 */
float	ft_newxy(float orig_x, float orig_z, float angle_rad)
{
	float	new_x;

	new_x = orig_x * cos(angle_rad) + orig_z * sin(angle_rad);
	return (new_x);
}
