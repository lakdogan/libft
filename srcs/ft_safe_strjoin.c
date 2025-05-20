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

char	*ft_safe_strjoin(char *s1, char *s2)
{
	char	*result;

	if (s1)
		result = ft_strjoin(s1, s2);
	else
		result = ft_strjoin("", s2);
	return (result);
}
