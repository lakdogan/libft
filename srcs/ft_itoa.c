/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:08:09 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:37:52 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/**
 * @brief Calculates the length needed for
 *  the string representation of an integer.
 *
 * Determines the number of characters required to represent the integer n
 * as a string. The length includes space for a minus sign if n is negative.
 *
 * @param n The integer to evaluate.
 * @return The length required (number of characters).
 */
static int	ft_itoa_len(int n)
{
	int			length;
	long long	absolute_value;

	length = 1;
	absolute_value = n;
	if (absolute_value < 0)
	{
		length++;
		absolute_value *= -1;
	}
	while (absolute_value > 9)
	{
		length++;
		absolute_value /= 10;
	}
	return (length);
}

/**
 * @brief Converts an integer to a null-terminated string.
 *
 * Allocates memory for and returns a string that represents the integer n.
 * Handles negative numbers and zero. Memory allocation is performed
 * dynamically; the caller must free the allocated memory.
 *
 * @param n The integer to convert.
 * @return Pointer to the resulting string, or NULL if allocation fails.
 */
char	*ft_itoa(int n)
{
	char		*string_result;
	int			length_of_number;
	long long	absolute_value;

	absolute_value = n;
	length_of_number = ft_itoa_len(n);
	string_result = malloc(length_of_number + 1);
	if (!string_result)
		return (NULL);
	string_result[length_of_number] = '\0';
	if (absolute_value < 0)
	{
		*string_result = '-';
		absolute_value *= -1;
	}
	if (!absolute_value)
		*string_result = '0';
	while (absolute_value > 0)
	{
		string_result[--length_of_number] = (absolute_value % 10) + '0';
		absolute_value /= 10;
	}
	return (string_result);
}
