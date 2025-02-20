/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:59:40 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:38:08 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Converts a string to an integer.
 *
 * This function parses the initial portion of the string pointed to by @p str,
 * interpreting its content as an integer number. 
 * It skips any leading whitespace,
 * handles an optional '+' or '-' sign, and then converts the subsequent numeric
 * characters to an integer.
 *
 * Details:
 * - The function skips whitespace characters: 
 *  space (' '), tab ('\t'), newline ('\n'),
 *   vertical tab ('\v'), form feed ('\f'), and carriage return ('\r').
 * - It then checks for a sign: if a '-' is encountered,
 *  the resulting integer is negative.
 * - Conversion stops when a non-numeric character is encountered.
 *
 * @param str A pointer to the null-terminated string to be converted.
 * @return The converted integer value. If no valid conversion can be performed,
 *         the function returns 0.
 */
int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	return (result * sign);
}
