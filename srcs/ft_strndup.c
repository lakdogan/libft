/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 05:38:09 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/08 18:38:10 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

/**
 * @brief Duplicates up to n characters from the given string.
 *
 * This function allocates a new null-terminated string containing at most `n`
 * characters from `s`. If `s` is shorter than `n`, the full string is copied.
 *
 * @param s The input string to duplicate.
 * @param n The maximum number of characters to duplicate.
 * @return A pointer to the newly allocated string,
	or NULL on allocation failure.
 */
char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (len < n && s[len])
		len++;
	dup = (char *)malloc(len + 1);
	if (!dup)
		return (NULL);
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[len] = '\0';
	return (dup);
}
