/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_str_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 20:55:04 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/27 00:12:12 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/garbage_collector.h"

/**
 * @brief Allocates a NULL-terminated string array
 *
 * @param gc Pointer to the garbage collector
 * @param size Number of strings (NULL terminator is added automatically)
 * @return char** Allocated string array or NULL on failure
 */
char	**gc_str_array_create(t_gc *gc, size_t size)
{
	char	**array;

	array = gc_calloc(gc, size + 1, sizeof(char *));
	return (array);
}

/**
 * @brief Duplicates a NULL-terminated string array
 *
 * @param gc Pointer to the garbage collector
 * @param src Source string array to duplicate
 * @return char** Duplicated string array or NULL on failure
 */
char	**gc_str_array_dup(t_gc *gc, char **src)
{
	char	**array;
	size_t	i;
	size_t	size;

	if (!src)
		return (NULL);
	size = 0;
	while (src[size])
		size++;
	array = gc_str_array_create(gc, size);
	if (!array)
		return (NULL);
	i = 0;
	while (i < size)
	{
		array[i] = gc_strdup(gc, src[i]);
		if (!array[i])
			return (NULL);
		i++;
	}
	return (array);
}

/**
 * @brief Splits a string and tracks all allocations with the GC
 *
 * @param gc Pointer to the garbage collector
 * @param s String to split
 * @param c Delimiter character
 * @return char** Array of split strings or NULL on failure
 */
char	**gc_split(t_gc *gc, char const *s, char c)
{
	char	**result;
	size_t	i;
	size_t	count;

	result = ft_split(s, c);
	if (!result)
		return (NULL);
	count = 0;
	while (result[count])
		count++;
	gc_register(gc, result, sizeof(char *) * (count + 1));
	i = 0;
	while (i < count)
	{
		gc_register(gc, result[i], ft_strlen(result[i]) + 1);
		i++;
	}
	return (result);
}
