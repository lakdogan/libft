/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:15:02 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:31:23 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/**
 * @brief Copies a string with a size limit.
 *
 * Copies up to dstsize - 1 characters from src to dst,
 * null-terminating the result if dstsize is not 0.
 * Returns the total length of src.
 *
 * @param dst The destination buffer.
 * @param src The source string.
 * @param dstsize The size of the destination buffer.
 * @return The total length of the source string.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const char	*src_ptr;
	char		*dst_ptr;
	size_t		src_len;

	src_ptr = src;
	dst_ptr = dst;
	while (*src_ptr)
		src_ptr++;
	src_len = src_ptr - src;
	if (!dstsize)
		return (src_len);
	while (dstsize-- > 1 && *src)
		*dst_ptr++ = *src++;
	*dst_ptr = '\0';
	return (src_len);
}
