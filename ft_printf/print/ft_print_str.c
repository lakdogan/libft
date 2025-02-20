/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:13:52 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:56:31 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/**
 * @brief Prints a string.
 *
 * If s is NULL, sets s to "(null)".
 * Iterates through s, printing each character.
 *
 * Updates the printed count.
 *
 * @param s The string to print.
 * @param printed Pointer to the printed count.
 * @return Updated printed count,
 *         or -1 on error.
 */
int	ft_print_str(const char *s, int *printed)
{
	if (s == NULL)
		s = "(null)";
	while (*s)
		if (ft_print_char(*s++, printed) == -1)
			return (-1);
	return (*printed);
}
