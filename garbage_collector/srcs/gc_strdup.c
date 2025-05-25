/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 22:48:59 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/25 22:42:01 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/garbage_collector.h"

/**
 * @brief Duplicates a string and registers it with the garbage collector
 *
 * @param gc Pointer to the garbage collector
 * @param str String to duplicate
 * @return char* Pointer to the new string, or NULL if allocation fails
 */
char	*gc_strdup(t_gc *gc, const char *str)
{
	size_t	len;
	char	*new_str;

	if (!str)
		return (NULL);
	if (!gc)
		return (ft_strdup(str));
	if (gc->count >= gc->capacity)
	{
		if (!gc_expand(gc))
			return (NULL);
	}
	if (!str)
		return (NULL);
	len = ft_strlen(str) + 1;
	new_str = gc_malloc(gc, len);
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, str, len);
	return (new_str);
}
