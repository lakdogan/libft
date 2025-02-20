/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:47:57 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:54:37 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/**
 * @brief Prints a number in hexadecimal.
 *
 * Recursively prints the hexadecimal representation
 * of nb. The case of the letters depends on c_format:
 * 'x' for lowercase, 'X' for uppercase.
 *
 * Updates the printed character count.
 *
 * @param nb The number to print.
 * @param c_format Format specifier: 'x' or 'X'.
 * @param printed Pointer to the count of printed characters.
 * @return Updated printed character count.
 */
int	ft_print_hex(unsigned int nb, char c_format, int *printed)
{
	char	c;
	int		r;

	r = 0;
	c = '0';
	if (nb >= 16)
		ft_print_hex(nb / 16, c_format, printed);
	r = nb % 16;
	if (c_format == 'x')
		c = HEXALOWER[r];
	else if (c_format == 'X')
		c = HEXAUPPER[r];
	ft_print_char(c, printed);
	return (*printed);
}
