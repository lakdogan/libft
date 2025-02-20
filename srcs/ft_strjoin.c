/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 19:47:36 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:30:36 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/**
 * @brief Concatenates two strings.
 *
 * Allocates (with malloc) and returns a new string that is the result of
 * the concatenation of s1 and s2.
 * If memory allocation fails, returns NULL.
 *
 * @param s1 The first string.
 * @param s2 The second string.
 * @return The new concatenated string, or NULL if allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*rslt;
	char		*ptr;
	const char	*s_s1;
	const char	*s_s2;

	s_s1 = s1;
	while (*s1)
		s1++;
	s_s2 = s2;
	while (*s2)
		s2++;
	rslt = (char *)malloc((s1 - s_s1) + (s2 - s_s2) + 1);
	if (!rslt)
		return (NULL);
	ptr = rslt;
	while (*s_s1)
		*ptr++ = *s_s1++;
	while (*s_s2)
		*ptr++ = *s_s2++;
	*ptr = '\0';
	return (rslt);
}
