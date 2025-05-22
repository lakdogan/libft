/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:35:15 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/22 18:01:51 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/**
 * @brief Compares two strings lexicographically
 *
 * Compares the two strings s1 and s2 character by character until a difference
 * is found or the end of either string is reached. Handles NULL pointers safely
 * by treating them as special cases with defined behavior.
 *
 * @param s1 First string to compare
 * @param s2 Second string to compare
 * @return int Negative value if s1 < s2, positive value if s1 > s2,
 *	zero if equal
 *             Returns 0 if both strings are NULL
 *             Returns -1 if only s1 is NULL
 *             Returns 1 if only s2 is NULL
 */
int	ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (-1);
	if (!s2)
		return (1);
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
