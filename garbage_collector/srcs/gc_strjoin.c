/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:40:58 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/28 23:29:58 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/garbage_collector.h"

/**
 * @brief Joins two strings, managed by the garbage collector
 *
 * @param gc Pointer to the garbage collector
 * @param s1 First string
 * @param s2 Second string
 * @return char* Pointer to the joined string, or NULL if allocation fails
 */
char	*gc_strjoin(t_gc *gc, const char *s1, const char *s2)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	if (str)
		gc_register(gc, str, ft_strlen(str) + NULL_TERMINATOR_SIZE);
	return (str);
}
