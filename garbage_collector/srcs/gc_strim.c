/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_strim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:41:37 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/28 23:29:18 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/garbage_collector.h"

/**
 * @brief Trims characters from string, managed by the garbage collector
 *
 * @param gc Pointer to the garbage collector
 * @param s1 String to trim
 * @param set Characters to trim
 * @return char* Pointer to the trimmed string, or NULL if allocation fails
 */
char	*gc_strtrim(t_gc *gc, const char *s1, const char *set)
{
	char	*str;

	str = ft_strtrim(s1, set);
	if (str)
		gc_register(gc, str, ft_strlen(str) + NULL_TERMINATOR_SIZE);
	return (str);
}
