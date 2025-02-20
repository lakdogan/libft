/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:08:54 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:33:30 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/**
 * @brief Finds the last occurrence of a character in a string.
 *
 * Searches the string s for the last occurrence of the character c.
 * If c is found, returns a pointer to it; if not, returns NULL.
 * If c is '\0', returns a pointer to the terminating null byte.
 *
 * @param s The string to search.
 * @param c The character to locate (converted to unsigned char).
 * @return A pointer to the last occurrence of c, or NULL if not found.
 */
char	*ft_strrchr(const char *s, int c)
{
	const char		*last_occurrence;
	unsigned char	uc;

	last_occurrence = NULL;
	uc = (unsigned char)c;
	while (*s)
	{
		if (*s == uc)
			last_occurrence = s;
		s++;
	}
	if (!uc)
		return ((char *)s);
	return ((char *)last_occurrence);
}
