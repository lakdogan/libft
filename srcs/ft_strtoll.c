/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 02:18:04 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/26 05:46:29 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../inc/push_swap.h"

/**
 * @brief Auto-detects the numerical base from a string prefix.
 *
 * If the provided base is 0,
	this function examines the string and sets the base
 * accordingly:
 * - "0x" or "0X": sets base to 16 and returns a pointer past the prefix.
 * - "0b" or "0B": sets base to 2 and returns a pointer past the prefix.
 * - Otherwise, if the string starts with '0' and is not empty afterward,
	sets base to 8.
 * - Otherwise, sets base to 10.
 *
 * @param str The input string.
 * @param base Pointer to the base value; updated if initially 0.
 * @return A pointer to the string after any base prefix.
 */
const char	*auto_detect_base_if_zero(const char *str, int *base)
{
	if (*base != 0)
		return (str);
	if (*str == '0')
	{
		if (str[1] == 'x' || str[1] == 'X')
		{
			*base = 16;
			return (str + 2);
		}
		else if (str[1] == 'b' || str[1] == 'B')
		{
			*base = 2;
			return (str + 2);
		}
		else if (str[1] != '\0')
			*base = 8;
		else
			*base = 10;
	}
	else
		*base = 10;
	return (str);
}

/**
 * @brief Parses a character as a digit in the specified base.
 *
 * Converts the given character to its numeric equivalent in the given base.
 * Returns -1 if the character is not a valid digit or if its numeric value
 * is greater than or equal to the base.
 *
 * @param c The character to parse.
 * @param base The numerical base.
 * @return The numeric value of the digit, or -1 if invalid.
 */
int	parse_digit(char c, int base)
{
	int	digit;

	if (ft_isdigit((unsigned char)c))
		digit = c - '0';
	else if (ft_isalpha((unsigned char)c))
		digit = ft_tolower((unsigned char)c) - 'a' + 10;
	else
		return (-1);
	if (digit >= base)
		return (-1);
	return (digit);
}

/**
 * @brief Checks if appending a digit would cause an overflow.
 *
 * Determines whether the current result, when multiplied by the base and added
 * to the next digit, would exceed the range of a long long. If so, returns
 * LLONG_MAX for positive numbers or LLONG_MIN for negative numbers.
 *
 * @param result The current accumulated result.
 * @param digit The digit to add.
 * @param base The numerical base.
 * @param sign The sign of the number (1 for positive, -1 for negative).
 * @return 1 if positive overflow occurs, -1 if negative overflow occurs,
	or 0 if no overflow.
 */
long long	check_overflow(long long result, int digit, int base, int sign)
{
	if (result > (LLONG_MAX - digit) / base)
	{
		if (sign == 1)
			return (LLONG_MAX);
		else
			return (LLONG_MIN);
	}
	return (0);
}

/**
 * @brief Accumulates the numerical value from a string.
 *
 * Iterates through the string,
 * converting valid digits in the specified base and
 * accumulating the result. If an invalid digit is encountered, or if adding the
 * digit would cause an overflow, the conversion stops. Optionally,
 * the end pointer
 * is updated to point where parsing stopped.
 *
 * @param str The input string containing the number.
 * @param sign The sign of the number (1 for positive, -1 for negative).
 * @param base The numerical base.
 * @param endptr Pointer to a pointer that will be set to the stopping point.
 * @return The accumulated number, or LLONG_MAX/LLONG_MIN in case of overflow.
 */
long long	convert_the_number(const char *str, int sign, int base,
		char **endptr)
{
	const char	*start;
	long long	result;
	int			digit;
	long long	overflow;

	result = 0;
	start = str;
	while (*str)
	{
		digit = parse_digit(*str, base);
		if (digit == -1)
			break ;
		overflow = check_overflow(result, digit, base, sign);
		if (overflow)
			return (overflow);
		result = result * base + digit;
		str++;
	}
	if (endptr)
	{
		*endptr = (char *)str;
		if (str == start)
			*endptr = (char *)start;
	}
	return (result);
}

/**
 * @brief Converts a string to a long long integer.
 *
 * Skips any leading whitespace and an optional '+' or '-' sign,
 * then converts the
 * subsequent numeric portion of the string to a long long integer,
 * taking into account
 * the specified base. If base is 0,
 * the function auto-detects the base from the string.
 * In case of overflow,
 * the function returns LLONG_MAX or LLONG_MIN and updates endptr
 * accordingly.
 *
 * @param str The input string.
 * @param endptr Pointer to a pointer that will be 
 * set to the character where conversion stopped.
 * @param base The numerical base for conversion, or 0 for auto-detection.
 * @return The converted long long integer.
 */
long long	ft_strtoll(const char *str, char **endptr, int base)
{
	long long	result;
	int			sign;

	result = 0;
	sign = 1;
	if (base && (base < 2 || base > 36))
	{
		if (endptr)
			*endptr = (char *)str;
		return (0);
	}
	while (ft_isspace((unsigned char)*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	str = auto_detect_base_if_zero(str, &base);
	result = convert_the_number(str, sign, base, endptr);
	return (result * sign);
}
