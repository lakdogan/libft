/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 19:01:41 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:29:47 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/**
 * @brief Duplicates a string.
 *
 * Allocates memory for a copy of s1 and copies its content.
 *
 * @param s1 The string to duplicate.
 * @return Pointer to the duplicated string, or NULL on failure.
 */
char	*ft_strdup(const char *s1)
{
	char	*ptr;
	char	*strt;
	size_t	len_s1;

	strt = NULL;
	len_s1 = ft_strlen(s1);
	ptr = (char *)malloc(len_s1 + 1);
	if (ptr)
	{
		strt = ptr;
		while (len_s1--)
			*ptr++ = *s1++;
		*ptr = '\0';
	}
	return (strt);
}
