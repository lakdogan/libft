/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:07:42 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:31:43 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/**
 * @brief Calculates the length of a string.
 *
 * Iterates through the string until the null-terminator is reached.
 *
 * @param s The string to measure.
 * @return The length of the string.
 */
size_t	ft_strlen(const char *s)
{
	size_t	length_of_str;

	length_of_str = 0;
	while (*s++)
		length_of_str++;
	return (length_of_str);
}
