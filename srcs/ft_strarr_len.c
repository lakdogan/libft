/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 11:22:28 by lakdogan          #+#    #+#             */
/*   Updated: 2025/06/08 11:25:39 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/**
 * @brief Counts the number of elements in a NULL-terminated string array.
 *
 * Iterates through the array until it reaches the NULL terminator,
 * counting each string element along the way.
 *
 * @param arr The NULL-terminated string array to count.
 * @return The number of elements in the array (excluding the NULL terminator),
 *         or 0 if arr is NULL.
 */
size_t	ft_strarr_len(char **arr)
{
	size_t	i;

	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}
