/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:47:50 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:21:12 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/**
 * @brief Scans a memory block for a specific character.
 *
 * Searches the first n bytes of the memory area pointed to
 * by s for the first occurrence of the character c.
 *
 * @param s Pointer to the memory area to search.
 * @param c Character to find (converted to unsigned char).
 * @param n Number of bytes to inspect.
 * @return Pointer to the first occurrence of c,
 *         or NULL if c is not found within the first n bytes.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	unsigned char		uc;

	ptr = (const unsigned char *)s;
	uc = (unsigned char)c;
	while (n--)
		if (*ptr++ == uc)
			return ((void *)--ptr);
	return (NULL);
}
