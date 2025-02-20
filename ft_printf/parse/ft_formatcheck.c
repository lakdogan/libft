/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatcheck.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:29:56 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:57:42 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/**
 * @brief Checks and processes a format specifier.
 *
 * Determines which format specifier is present
 * and calls the corresponding print function:
 *   - 'c': prints a character.
 *   - 's': prints a string.
 *   - 'p': prints a pointer.
 *   - 'i' or 'd': prints an integer.
 *   - 'u': prints an unsigned integer.
 *   - 'x' or 'X': prints a hexadecimal number.
 *   - '%': prints a literal '%'.
 *
 * Returns -1 if an unknown specifier is encountered.
 *
 * @param ap The variable argument list.
 * @param format Pointer to the format specifier.
 * @param printed Pointer to the printed character count.
 * @return The result of the corresponding print function,
 *         or -1 on error.
 */
int	ft_formatcheck(va_list ap, const char *format, int *printed)
{
	if (*format == 'c')
		return (ft_print_char(va_arg(ap, int), printed));
	else if (*format == 's')
		return (ft_print_str(va_arg(ap, char *), printed));
	else if (*format == 'p')
		return (ft_print_p(va_arg(ap, void *), printed));
	else if (*format == 'i' || *format == 'd')
		return (ft_print_id(va_arg(ap, int), printed));
	else if (*format == 'u')
		return (ft_print_uint(va_arg(ap, unsigned int), printed));
	else if (*format == 'x' || *format == 'X')
		return (ft_print_hex(va_arg(ap, unsigned int), *format, printed));
	else if (*format == '%')
		return (ft_print_char('%', printed));
	else
		return (-1);
}
