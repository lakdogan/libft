/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_lst_from_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 21:58:09 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/27 00:11:46 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/garbage_collector.h"

/**
 * @brief Creates a linked list from a NULL-terminated array
 *
 * Converts an array of elements into a linked list. Each node's content
 * is a pointer to the corresponding array element.
 *
 * @param gc Pointer to the garbage collector
 * @param array Array of elements to convert to a list
 * @return t_list* Head of the new list or NULL if allocation fails
 */
t_list	*gc_lst_from_array(t_gc *gc, void **array)
{
	t_list	*list;
	size_t	i;

	if (!array)
		return (NULL);
	list = NULL;
	i = 0;
	while (array[i])
	{
		gc_lstadd_back(gc, &list, array[i]);
		i++;
	}
	return (list);
}
