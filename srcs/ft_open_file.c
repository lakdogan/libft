/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:42:48 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:38:38 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/**
 * @brief Opens a file in read-only mode.
 *
 * Attempts to open the file specified by filename. If the file cannot be
 * opened, an error message is printed using perror and -1 is returned.
 * On success, a confirmation message is printed and the
 *  file descriptor is returned.
 *
 * @param filename The name of the file to open.
 * @return The file descriptor on success, or -1 on failure.
 */
int	open_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file!");
		return (-1);
	}
	ft_printf("File opened successfully!\n");
	return (fd);
}
