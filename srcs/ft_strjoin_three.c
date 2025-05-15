/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 21:30:37 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/15 21:40:57 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/**
 * @brief Concatenates three strings
 * into a new allocated string.
 *
 * This function creates a new string
 * consisting of s1 followed by s2 and s3.
 * It allocates memory for the result and
 * frees all intermediate strings used.
 *
 * Example:
 *     ft_strjoin_3("PATH", "=", "/usr/bin");
 *     → returns "PATH=/usr/bin"
 *
 * @param s1 The first string.
 * @param s2 The second string.
 * @param s3 The third string.
 * @return A newly allocated string, or NULL on error.
 */
char	*ft_strjoin_3(const char *s1, const char *s2, const char *s3)
{
	char	*tmp;
	char	*res;

	if (!s1 || !s2 || !s3)
		return (NULL);
	tmp = ft_strjoin(s1, s2);
	if (!tmp)
		return (NULL);
	res = ft_strjoin(tmp, s3);
	free(tmp);
	return (res);
}
