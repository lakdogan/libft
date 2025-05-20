/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 20:40:13 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/20 20:42:19 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/**
 * @brief Frees a NULL-terminated array of strings.
 *
 * This function iterates through a dynamically allocated array of strings
 * (typically produced by a `split` function), frees each individual string,
 * and then frees the array itself.
 *
 * @param split A NULL-terminated array of dynamically allocated strings.
 *              If `split` is NULL, the function does nothing.
 *
 * @note After calling this function, the pointer `split` itself is invalid
 *       and should not be used unless re-initialized.
 */
void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
