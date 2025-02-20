/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:33:20 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:37:36 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/**
 * @brief Frees an array of strings.
 *
 * Iterates through the string array, frees each string,
 * then frees the array itself.
 *
 * @param string_array The array of strings to free.
 * @return Always returns NULL.
 */
static char	**free_string_array(char **string_array)
{
	char	**temp;

	temp = string_array;
	while (*temp)
		free(*temp++);
	free(string_array);
	return (NULL);
}

/**
 * @brief Splits a string into substrings.
 *
 * Processes the input string s, extracting substrings
 * separated by the delimiter c, and stores them in
 * result_array. If a substring allocation fails,
 * frees the entire array.
 *
 * @param s The string to split.
 * @param c The delimiter character.
 * @param total_words Total number of substrings to extract.
 * @param result_array Array to store the substrings.
 * @return The filled result_array, or NULL on allocation failure.
 */
static char	**split_string(const char *s, char c, int total_words,
		char **result_array)
{
	char	**current_result;
	int		len;

	current_result = result_array;
	while (total_words--)
	{
		while (*s == c)
			s++;
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		*current_result = ft_substr(s, 0, len);
		if (*current_result == NULL)
			return (free_string_array(result_array));
		current_result++;
		s += len;
	}
	*current_result = NULL;
	return (result_array);
}

/**
 * @brief Splits a string by a delimiter into an array of substrings.
 *
 * Allocates and returns an array of strings obtained by splitting s
 * using the character c as a delimiter. The array 
 * is terminated by a NULL pointer.
 *
 * @param s The string to split.
 * @param c The delimiter character.
 * @return A NULL-terminated array of substrings, or NULL if allocation fails.
 */
char	**ft_split(const char *s, char c)
{
	int		total_words;
	int		i;
	char	**result_array;

	if (!s)
		return (NULL);
	total_words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
			if (!i || s[i - 1] == c)
				total_words++;
		i++;
	}
	result_array = (char **)malloc((total_words + 1) * sizeof(char *));
	if (result_array == NULL)
		return (NULL);
	return (split_string(s, c, total_words, result_array));
}
