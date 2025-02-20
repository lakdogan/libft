/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_id.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:00:40 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:55:10 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/**
 * @brief Prints an integer.
 *
 * If the number is negative, prints a '-' sign,
 * then prints the absolute value recursively.
 * Updates the printed character count.
 *
 * @param nb The integer to print.
 * @param printed Pointer to the printed count.
 * @return Updated printed count.
 */
int	ft_print_id(int nb, int *printed)
{
	char		c;
	long long	number;

	number = nb;
	if (number < 0)
	{
		ft_print_char('-', printed);
		number = -(number);
	}
	if (number >= 10)
		ft_print_id(number / 10, printed);
	c = (number % 10) + '0';
	ft_print_char(c, printed);
	return (*printed);
}
