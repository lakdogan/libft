/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 21:30:29 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:02:53 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/**
 * @brief Calculates the difference between two numbers.
 *
 * Subtracts no2 from no1 and returns the result.
 *
 * @param no1 The first number.
 * @param no2 The second number.
 * @return The difference (no1 - no2) as a float.
 */
float	ft_getdif(float no1, float no2)
{
	float	res;

	res = no1 - no2;
	return (res);
}
