/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 19:34:54 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:34:34 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/**
 * @brief Extracts a substring from a given string.
 *
 * Allocates and returns a substring from the string s.
 * The substring begins at index 'start' and is at most 'len' characters long.
 * If 'start' is greater than the length of s, an empty string is returned.
 * If the remaining string is shorter than len, the substring will contain
 * only the available characters.
 *
 * @param s The source string.
 * @param start The starting index of the substring.
 * @param len The maximum number of characters in the substring.
 * @return A newly allocated substring, or NULL if memory allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;

	slen = ft_strlen(s);
	if (start >= slen || len == 0)
	{
		sub = malloc(1);
		if (!sub)
			return (NULL);
		*sub = '\0';
		return (sub);
	}
	slen = slen - start;
	if (slen < len)
		len = slen;
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}
