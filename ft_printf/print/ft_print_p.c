/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:08:27 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:55:56 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/**
 * @brief Recursively prints an unsigned number in hexadecimal.
 *
 * Recursively divides the number by 16 and prints
 * the remainder in lowercase hexadecimal format.
 *
 * @param nb The number to print.
 * @param printed Pointer to the printed count.
 */
static void	ft_recursive_p(unsigned long long nb, int *printed)
{
	if (nb >= 16)
		ft_recursive_p(nb / 16, printed);
	nb = (nb % 16);
	ft_print_char(HEXALOWER[nb], printed);
}

/**
 * @brief Prints a pointer in hexadecimal format.
 *
 * Converts the pointer to an unsigned long long,
 * prints the prefix "0x", and then prints the
 * hexadecimal representation of the pointer.
 *
 * Supports multiple file descriptors and updates
 * the printed character count.
 *
 * @param ptr The pointer to print.
 * @param printed Pointer to the printed count.
 * @return Updated printed count.
 */
int	ft_print_p(void *ptr, int *printed)
{
	unsigned long long	nb;

	nb = (unsigned long long)ptr;
	ft_print_char('0', printed);
	ft_print_char('x', printed);
	ft_recursive_p(nb, printed);
	return (*printed);
}
