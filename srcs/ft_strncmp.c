/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:35:24 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:32:37 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/**
 * @brief Compares two strings up to n characters.
 *
 * Iterates over s1 and s2 comparing each character.
 * Stops when a difference is found, when the end of either string is reached,
 * or when n characters have been compared.
 *
 * @param s1 The first string.
 * @param s2 The second string.
 * @param n Maximum number of characters to compare.
 * @return The difference between the first differing characters,
 *         or 0 if the strings are equal up to n characters.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	c1;
	unsigned char	c2;
	size_t			len;

	len = n;
	while (len--)
	{
		c1 = (unsigned char)*s1++;
		c2 = (unsigned char)*s2++;
		if (c1 != c2)
			return (c1 - c2);
		if (!c1)
			break ;
	}
	return (0);
}
