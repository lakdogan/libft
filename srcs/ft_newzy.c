/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newzy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:41:46 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:25:22 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/**
 * @brief Computes the new z-coordinate after rotation.
 *
 * Applies a rotation transformation on the original x and z values,
 * using the provided angle in radians.
 *
 * Formula: new_z = -orig_x * sin(angle_rad) + orig_z * cos(angle_rad)
 *
 * @param orig_x The original x-coordinate.
 * @param orig_z The original z-coordinate.
 * @param angle_rad The rotation angle in radians.
 * @return The transformed z-coordinate.
 */
float	ft_newzy(float orig_x, float orig_z, float angle_rad)
{
	float	new_z;

	new_z = -orig_x * sin(angle_rad) + orig_z * cos(angle_rad);
	return (new_z);
}
