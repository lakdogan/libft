/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_strjoin_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:44:15 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/25 22:42:11 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/garbage_collector.h"

/**
 * @brief Joins three strings, managed by the garbage collector
 *
 * @param gc Pointer to the garbage collector
 * @param s1 First string
 * @param s2 Second string
 * @param s3 Third string
 * @return char* Pointer to the joined string, or NULL if allocation fails
 */
char	*gc_strjoin_3(t_gc *gc, const char *s1, const char *s2, const char *s3)
{
	char	*temp;
	char	*result;

	temp = ft_strjoin_3(s1, s2, s3);
	if (temp)
	{
		result = gc_strdup(gc, temp);
		free(temp);
		return (result);
	}
	return (NULL);
}
