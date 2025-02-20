/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:44:32 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:54:12 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/**
 * @brief Prints a single character.
 *
 * Writes character c to stdout.
 * Updates the printed count.
 * Returns the updated printed count.
 *
 * @param c The character to print.
 * @param printed Pointer to the current printed count.
 * @return Updated printed count, or -1 on error.
 */
int	ft_print_char(const char c, int *printed)
{
	int	count;

	count = 0;
	if (*printed == -1)
		return (-1);
	count = write(1, &c, 1);
	if (count == -1)
		*printed = -1;
	else
		*printed += count;
	return (*printed);
}
