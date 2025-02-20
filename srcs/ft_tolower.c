/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:39:48 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:35:22 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Converts an uppercase letter to lowercase.
 *
 * If c is an uppercase letter, this function 
 * converts it to its lowercase equivalent.
 * If c is not an uppercase letter, it is returned unchanged.
 *
 * @param c The character to convert.
 * @return The lowercase equivalent if c is uppercase, or c otherwise.
 */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
