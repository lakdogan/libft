/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:42:25 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/25 22:41:56 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/garbage_collector.h"

/**
 * @brief Splits string into array of strings, managed by the garbage collector
 *
 * @param gc Pointer to the garbage collector
 * @param s String to split
 * @param c Delimiter character
 * @return char** Array of strings, or NULL if allocation fails
 * @note This function registers both the array and each individual string
 */
char	**gc_split(t_gc *gc, const char *s, char c)
{
	char	**strs;
	int		count;
	int		i;

	strs = ft_split(s, c);
	if (strs)
	{
		count = 0;
		while (strs[count])
			count++;
		gc_register(gc, strs, (count + 1) * sizeof(char *));
		i = 0;
		while (strs[i])
		{
			gc_register(gc, strs[i], ft_strlen(strs[i]) + 1);
			i++;
		}
	}
	return (strs);
}
