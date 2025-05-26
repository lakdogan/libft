/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:08:26 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/27 00:12:49 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/garbage_collector.h"

/**
 * @brief Allocates memory and registers it with the garbage collector
 *
 * @param gc Pointer to the garbage collector
 * @param size Size in bytes to allocate
 * @return void* Pointer to allocated memory, or NULL if allocation fails
 */
// In gc_malloc.c
void	*gc_malloc(t_gc *gc, size_t size)
{
	void	*ptr;
	size_t	actual_size;

	if (size > 0)
		actual_size = size;
	else
		actual_size = 1;
	ptr = malloc(actual_size);
	if (ptr && gc)
	{
		if (gc->count >= gc->capacity)
		{
			if (!gc_expand(gc))
			{
				ft_putstr_fd("GC error: Failed to expand capacity\n",
					STDERR_FILENO);
				free(ptr);
				return (NULL);
			}
		}
		gc_register(gc, ptr, actual_size);
	}
	else if (!ptr)
		ft_putstr_fd("GC error: Failed to allocate memory\n", STDERR_FILENO);
	return (ptr);
}
