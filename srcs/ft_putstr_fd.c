/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:10:13 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:28:06 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/**
 * @brief Writes a string to a file descriptor.
 *
 * Iterates through the string s and writes each character
 * to the file descriptor fd.
 *
 * @param s The string to write.
 * @param fd The file descriptor where the string is written.
 */
void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		ft_putchar_fd(*s++, fd);
}
