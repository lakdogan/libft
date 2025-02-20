/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 14:36:08 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 17:37:23 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define HEXALOWER "0123456789abcdef"
# define HEXAUPPER "0123456789ABCDEF"

# include "./../inc/libft.h"
# include <stdarg.h>
# include <stddef.h>

int	ft_print_char(const char c, int *check);
int	ft_print_hex(unsigned int nb, char c_format, int *check);
int	ft_print_id(int nb, int *check);
int	ft_print_p(void *ptr, int *check);
int	ft_print_str(const char *s, int *check);
int	ft_print_uint(unsigned int nb, int *check);
int	ft_formatcheck(va_list ap, const char *format, int *check);
int	ft_printf(const char *format, ...);

#endif