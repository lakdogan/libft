/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 21:59:19 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:15:04 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "./../ft_printf/ft_printf.h"
# include "./../get_next_line/get_next_line.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_itoa(int number);
float				ft_magnitude(float *a);
float				ft_getrad(float degree);
int					ft_atoi(const char *str);
size_t				ft_strlen(const char *s);
float				ft_getdeg(float radians);
char				*ft_strdup(const char *s1);
void				ft_putnbr_fd(int n, int fd);
void				*ft_bzero(void *s, size_t n);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
float				ft_getdif(float no1, float no2);
float				ft_isometric_x(float x, float y);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
float				ft_dot_product(float *a, float *b);
char				**ft_split(char const *s, char del);
void				*ft_calloc(size_t count, size_t size);
void				*ft_memset(void *b, int c, size_t len);
float				ft_vector_angle_rad(float *a, float *b);
float				ft_vector_angle_deg(float *a, float *b);
float				ft_tiltang(float height, float distance);
float				ft_isometric_y(float x, float y, float z);
void				ft_putchar_fd(char c, int file_descriptor);
void				*ft_memchr(const void *s, int c, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_unit_vector(float *a, float *unit_vector);
char				*ft_strtrim(char const *s1, char const *set);
void				*ft_memcpy(void *dst, const void *src, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
float				ft_newxy(float orig_x, float orig_z, float angle_rad);
float				ft_newxz(float orig_x, float orig_y, float angle_rad);
float				ft_newyx(float orig_y, float orig_z, float angle_rad);
float				ft_newyz(float orig_x, float orig_y, float angle_rad);
float				ft_newzx(float orig_y, float orig_z, float angle_rad);
float				ft_newzy(float orig_x, float orig_z, float angle_rad);

void				ft_normalized_cross_product(float *a, float *b,
						float *cross_product);
char				*ft_substr(char const *s, unsigned int start, size_t len);
void				ft_striteri(char *str, void (*func)(unsigned int, char *));
void				ft_compute_cross_product(float *a, float *b,
						float *product);
void				ft_normalize(float *raw_cross_product, float magnitude,
						float *cross_product);
char				*ft_strmapi(char const *str, char (*func)(unsigned int,
							char));
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
t_list				*ft_lstmap(t_list *list, void *(*f)(void *),
						void (*del)(void *));
#endif