/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:11:13 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:30:11 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/**
 * @brief Applies a function to each character of a string.
 *
 * Iterates over the string s and applies the function f to each
 * character, passing the current index and a pointer to the character.
 *
 * @param s The string to iterate over.
 * @param f The function to apply to each character.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	char	*o_str;

	o_str = s;
	while (*s)
	{
		f((unsigned int)(s - o_str), s);
		s++;
	}
}
