/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:08:59 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/25 22:40:14 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/garbage_collector.h"

/**
 * @brief Allocates zeroed memory and registers it with the garbage collector
 *
 * @param gc Pointer to the garbage collector
 * @param nmemb Number of elements to allocate
 * @param size Size of each element in bytes
 * @return void* Pointer to allocated memory, or NULL if allocation fails
 */
void	*gc_calloc(t_gc *gc, size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_size;

	total_size = nmemb * size;
	if (nmemb > 0 && size > SIZE_MAX / nmemb)
	{
		ft_putstr_fd("GC error: Size overflow in calloc\n", STDERR_FILENO);
		return (NULL);
	}
	if (gc->count >= gc->capacity)
	{
		if (!gc_expand(gc))
		{
			return (NULL);
		}
	}
	ptr = ft_calloc(nmemb, size);
	if (ptr && gc)
		gc_register(gc, ptr, total_size);
	return (ptr);
}
