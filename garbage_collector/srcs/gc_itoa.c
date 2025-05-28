/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:43:41 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/28 23:29:34 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/garbage_collector.h"

/**
 * @brief Converts integer to string, managed by the garbage collector
 *
 * @param gc Pointer to the garbage collector
 * @param n Integer to convert
 * @return char* String representation, or NULL if allocation fails
 */
char	*gc_itoa(t_gc *gc, int n)
{
	char	*str;

	str = ft_itoa(n);
	if (str)
		gc_register(gc, str, ft_strlen(str) + NULL_TERMINATOR_SIZE);
	return (str);
}
