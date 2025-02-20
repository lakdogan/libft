/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:45:27 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:29:27 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/**
 * @brief Locates a character in a string.
 *
 * Searches for the first occurrence of the character c in the
 * string s (including the terminating null byte).
 *
 * @param s The string to search.
 * @param c The character to locate (converted to unsigned char).
 * @return A pointer to the first occurrence of c in s, or NULL if not found.
 */
char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	while (*s && *s != uc)
		s++;
	if (*s == uc || !uc)
		return ((char *)s);
	return (NULL);
}
