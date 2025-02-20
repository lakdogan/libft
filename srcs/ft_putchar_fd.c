/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:08:44 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:26:56 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/**
 * @brief Writes a character to a file descriptor.
 *
 * Sends the character c to the file descriptor fd.
 *
 * @param c The character to write.
 * @param fd The file descriptor where the character is written.
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
