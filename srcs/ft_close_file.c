/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:43:55 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:00:49 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/**
 * @brief Closes a file descriptor.
 *
 * Tries to close the given file descriptor.
 * If closing fails, prints an error message with perror.
 * On success, prints a confirmation message.
 *
 * @param fd The file descriptor to close.
 * @return 0 on success, 1 on error.
 */
int	ft_close_file(int fd)
{
	if (close(fd) < 0)
	{
		perror("Error closing file!");
		return (1);
	}
	ft_printf("File closed successfully!\n");
	return (0);
}
