/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 20:48:49 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/20 20:49:51 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/**
 * @brief Safely joins two strings, handling NULL for the first string.
 *
 * This function joins two strings using `ft_strjoin`, but ensures that
 * if the first string `s1` is NULL, it will be treated as an empty string
 * instead of causing undefined behavior or a crash.
 *
 * @param s1 The first string to join. Can be NULL.
 * @param s2 The second string to join. Must not be NULL.
 * @return A newly allocated string containing the concatenation of `s1` and `s2`.
 *         Returns NULL if memory allocation fails.
 *
 * @note The returned string must be freed by the caller.
 */
char	*ft_safe_strjoin(char *s1, char *s2)
{
	char	*result;

	if (s1)
		result = ft_strjoin(s1, s2);
	else
		result = ft_strjoin("", s2);
	return (result);
}
