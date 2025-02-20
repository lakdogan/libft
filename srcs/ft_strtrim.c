/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 20:02:04 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:34:11 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/**
 * @brief Checks if a character is part of a given set.
 *
 * Iterates through the string 'set' and returns 1 if the character 'c'
 * is found; otherwise, returns 0.
 *
 * @param c The character to check.
 * @param set The set of characters.
 * @return 1 if c is in set, 0 otherwise.
 */
static int	in_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

/**
 * @brief Trims specified characters from the beginning and end of a string.
 *
 * Removes all characters from the start and end of s1 that are present in set.
 * Allocates and returns a new string containing the trimmed content.
 * Returns NULL if s1 or set is NULL, or if memory allocation fails.
 *
 * @param s1 The string to trim.
 * @param set The set of characters to remove.
 * @return A newly allocated trimmed string, or NULL on failure.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	char	*start_ptr;
	char	*end_ptr;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	start_ptr = (char *)s1;
	while (*start_ptr && in_set(*start_ptr, set))
		start_ptr++;
	end_ptr = (char *)s1 + ft_strlen(s1);
	while (end_ptr > start_ptr && in_set(*(end_ptr - 1), set))
		end_ptr--;
	len = end_ptr - start_ptr;
	trim = malloc(len + 1);
	if (!trim)
		return (NULL);
	ft_strlcpy(trim, start_ptr, len + 1);
	return (trim);
}
