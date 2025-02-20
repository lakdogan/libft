/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:09:41 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:27:41 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/**
 * @brief Writes an integer to a file descriptor.
 *
 * Handles negative values and the smallest 32-bit integer.
 * Converts the integer into characters and writes them to fd.
 *
 * @param n The integer to write.
 * @param fd The file descriptor.
 */
void	ft_putnbr_fd(int n, int fd)
{
	int		div;
	char	c;

	div = 1;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	while (n / div > 9)
		div = div * 10;
	while (div > 0)
	{
		c = (n / div) + '0';
		n = n - ((n / div) * div);
		ft_putchar_fd(c, fd);
		div = div / 10;
	}
}
