/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:18:25 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/25 22:41:28 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/garbage_collector.h"

/**
 * @brief Copies memory with garbage collector tracking
 *
 * Allocates memory of the specified size using the garbage collector,
 * then copies data from the source pointer to the new memory.
 *
 * @param gc Pointer to the garbage collector
 * @param src Source memory area
 * @param size Size in bytes to copy
 * @return void* Pointer to the new memory, or NULL if allocation fails
 */
void	*gc_memcpy(t_gc *gc, const void *src, size_t size)
{
	void	*dest;

	if (!src || !size)
		return (NULL);
	dest = gc_malloc(gc, size);
	if (!dest)
		return (NULL);
	ft_memcpy(dest, src, size);
	return (dest);
}
