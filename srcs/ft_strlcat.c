/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:45:34 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:37:19 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/**
 * @brief Concatenates src to dst with size limitation.
 *
 * Appends src to the end of dst, ensuring that the 
 * total length does not exceed
 * dstsize. It writes at most dstsize - strlen(dst) - 1 bytes 
 * and null-terminates dst.
 * The function returns the total length of the string it tried to create,
 * which is the initial length of dst plus the length of src.
 *
 * @param dst The destination buffer.
 * @param src The source string.
 * @param dstsize The total size of the destination buffer.
 * @return The length of the string it tried to create.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*dest_ptr;
	const char	*src_ptr;
	size_t		dest_len;

	dest_ptr = dst;
	while (*dest_ptr && (size_t)(dest_ptr - dst) < dstsize)
		dest_ptr++;
	dest_len = dest_ptr - dst;
	if (dest_len == dstsize)
		return (dstsize + ft_strlen(src));
	src_ptr = src;
	while (*src_ptr && (dest_len + (src_ptr - src) + 1) < dstsize)
		*dest_ptr++ = *src_ptr++;
	if (dest_len + (src_ptr - src) < dstsize)
		*dest_ptr = '\0';
	return (dest_len + ft_strlen(src));
}
