/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newzx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:38:53 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:24:56 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/**
 * @brief Computes the new z-coordinate after rotation.
 *
 * Applies a rotation transformation on the original y and z values,
 * using the provided angle in radians.
 *
 * Formula: new_z = orig_y * sin(angle_rad) + orig_z * cos(angle_rad)
 *
 * @param orig_y The original y-coordinate.
 * @param orig_z The original z-coordinate.
 * @param angle_rad The rotation angle in radians.
 * @return The transformed z-coordinate.
 */
float	ft_newzx(float orig_y, float orig_z, float angle_rad)
{
	float	new_z;

	new_z = orig_y * sin(angle_rad) + orig_z * cos(angle_rad);
	return (new_z);
}
