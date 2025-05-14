/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 05:35:59 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/09 02:15:20 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

/**
 * @brief Checks if a character is a standard ASCII whitespace character.
 *
 * Whitespace characters include: space, horizontal tab, newline,
 * carriage return, vertical tab, and form feed.
 *
 * @param c The character to check (as an int).
 * @return 1 if the character is a whitespace, 0 otherwise.
 */
int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v'
		|| c == '\f');
}
