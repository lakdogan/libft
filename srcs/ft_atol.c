/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:20:39 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/15 20:39:46 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/**
 * @brief Converts a string to a long integer.
 *
 * This function parses the given string `str` and converts it to a
 * `long` value. It skips leading whitespace, handles optional '+' or '-',
 * and processes numeric characters until a non-digit is encountered.
 *
 * @param str The input string to convert.
 * @return The converted `long` value. Returns 0 if no digits are found.
 *
 * @note This function does not handle overflow or underflow. The behavior
 *       is undefined if the result exceeds the range of `long`.
 */
long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
