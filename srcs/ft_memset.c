/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:36:07 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:22:42 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/**
 * @brief Fills a memory area with a constant byte.
 *
 * Sets the first len bytes of the memory area pointed to by b
 * to the value of c (converted to an unsigned char).
 *
 * @param b Pointer to the memory area.
 * @param c The value to set.
 * @param len Number of bytes to fill.
 * @return Pointer to the memory area b.
 */
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (len--)
		*p++ = (unsigned char)c;
	return (b);
}
