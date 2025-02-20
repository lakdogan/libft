/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 21:19:14 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 17:59:20 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/**
 * @brief Setzt n Bytes im Speicher auf Null.
 *
 * Diese Funktion nutzt ft_memset, um die ersten n Bytes des
 * Speicherbereichs, auf den s zeigt, mit '\0' zu belegen.
 *
 * @param s Zeiger auf den Speicherbereich.
 * @param n Anzahl der Bytes, die auf Null gesetzt werden.
 * @return Zeiger auf den Speicherbereich s.
 */
void	*ft_bzero(void *s, size_t n)
{
	return (ft_memset(s, '\0', n));
}
