/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:40:25 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/25 22:42:24 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/garbage_collector.h"

/**
 * @brief Extracts a substring managed by the garbage collector
 *
 * @param gc Pointer to the garbage collector
 * @param s Source string
 * @param start Starting index
 * @param len Length of substring
 * @return char* Pointer to the substring, or NULL if allocation fails
 */
char	*gc_substr(t_gc *gc, const char *s, unsigned int start, size_t len)
{
	char	*str;

	str = ft_substr(s, start, len);
	if (str)
		gc_register(gc, str, ft_strlen(str) + NULL_TERMINATOR);
	return (str);
}
