/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:28:14 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:36:03 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Converts a lowercase letter to uppercase.
 *
 * Checks if c is between 'a' and 'z'.
 * If true, converts c to uppercase.
 *
 * Otherwise, returns c unchanged.
 *
 * @param c The character to convert.
 * @return The uppercase character if conversion applies,
 *         or c otherwise.
 */
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
