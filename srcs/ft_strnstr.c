/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:33:10 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:36:54 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/**
 * @brief Locates a substring in a string with a length limit.
 *
 *
 * Searches for the first occurrence of the 
 * substring needle in the string haystack,
 * examining at most len characters. If needle is an empty string,
 * haystack is returned.
 * The search stops if the length limit is reached.
 *
 * @param haystack The string to search in.
 * @param needle The substring to locate.
 * @param len Maximum number of characters to search.
 * @return A pointer to the beginning of the located substring,
	or NULL if not found.
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*large;
	char	*small;
	size_t	length;

	large = (char *)haystack;
	small = (char *)needle;
	if (!*small)
		return (large);
	length = ft_strlen(small);
	while (*large && (large - (char *)haystack + length) <= len)
	{
		if (ft_strncmp(large, small, length) == 0)
			return (large);
		large++;
	}
	return (NULL);
}
