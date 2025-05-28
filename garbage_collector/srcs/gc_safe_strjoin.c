/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_safe_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 21:43:17 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/28 21:47:35 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/garbage_collector.h"

/**
 * @brief Safely joins two strings with garbage collection
 *
 * This function joins two strings and registers the result with the
 * garbage collector. It safely handles NULL for the first string by
 * treating it as an empty string.
 *
 * @param gc Pointer to the garbage collector
 * @param s1 The first string to join (can be NULL)
 * @param s2 The second string to join (must not be NULL)
 * @return char* Pointer to the joined string, or NULL if allocation fails
 */
char	*gc_safe_strjoin(t_gc *gc, const char *s1, const char *s2)
{
	char	*result;

	if (s1)
		result = gc_strjoin(gc, s1, s2);
	else
		result = gc_strjoin(gc, "", s2);
	return (result);
}
