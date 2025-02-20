/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:36:21 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:03:31 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/**
 * @brief Checks if a character is alphanumeric.
 *
 * Returns non-zero if the character is either a letter
 * or a digit, using ft_isalpha and ft_isdigit.
 *
 * @param c The character to check.
 * @return Non-zero if c is alphanumeric, zero otherwise.
 */
int	ft_isalnum(int c)
{
	return ((ft_isalpha(c)) || (ft_isdigit(c)));
}
