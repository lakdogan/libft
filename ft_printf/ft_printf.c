/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 14:23:36 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:52:25 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Custom printf function.
 *
 * Processes the format string and handles
 * various format specifiers:
 *   - %c: character
 *   - %s: string
 *   - %p: pointer
 *   - %i, %d: integer
 *   - %u: unsigned integer
 *   - %x, %X: hexadecimal
 *   - %%: literal '%'
 *
 * Uses a variable argument list (va_list) to
 * manage the additional arguments.
 *
 * @param format The format string.
 * @return The total number of characters printed,
 *         or -1 on error.
 */
int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		printed;

	printed = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (ft_formatcheck(ap, format, &printed) == -1)
				return (-1);
		}
		else if (ft_print_char(*format, &printed) == -1)
			return (-1);
		format++;
	}
	va_end(ap);
	return (printed);
}
