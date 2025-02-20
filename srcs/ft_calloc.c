/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:24:42 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:00:01 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/**
 * @brief Allocates and zeroes memory.
 *
 * Allocates memory for an array of 'count'
 * elements of 'size' bytes each.
 *
 * Initializes all allocated bytes to zero.
 *
 * Checks for overflow of total allocation size.
 *
 * @param count Number of elements.
 * @param size Size of each element.
 * @return Pointer to the allocated memory,
 *         or NULL on failure.
 */
void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*ptr;
	char	*byte_ptr;

	if (count && size > SIZE_MAX / count)
		return (NULL);
	total_size = count * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	byte_ptr = (char *)ptr;
	while (total_size--)
		*byte_ptr++ = 0;
	return (ptr);
}
