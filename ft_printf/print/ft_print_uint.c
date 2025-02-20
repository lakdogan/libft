/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:24:49 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:57:00 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/**
 * @brief Prints an unsigned integer.
 *
 * Recursively prints the digits of nb.
 * Converts each digit to its character form.
 * Updates the printed count.
 *
 * @param nb The unsigned integer to print.
 * @param printed Pointer to the printed count.
 * @return The updated printed count.
 */
int	ft_print_uint(unsigned int nb, int *printed)
{
	char		c;
	long long	number;

	number = nb;
	if (10 <= number)
		ft_print_uint(number / 10, printed);
	c = ((unsigned int)(number % 10)) + '0';
	ft_print_char(c, printed);
	return (*printed);
}
