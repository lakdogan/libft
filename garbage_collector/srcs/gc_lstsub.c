/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_lstsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 21:59:41 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/27 00:12:06 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/garbage_collector.h"

/**
 * @brief Creates a sublist from a linked list
 *
 * Creates a new list containing nodes from the start position
 * to the start+len position in the original list.
 *
 * @param gc Pointer to the garbage collector
 * @param lst Original list
 * @param start Starting position (0-indexed)
 * @param len Number of nodes to include
 * @return t_list* New sublist or NULL if allocation fails
 */
t_list	*gc_lstsub(t_gc *gc, t_list *lst, size_t start, size_t len)
{
	t_list	*result;
	t_list	*current;
	size_t	i;

	if (!lst)
		return (NULL);
	result = NULL;
	current = lst;
	i = 0;
	while (current && i < start)
	{
		current = current->next;
		i++;
	}
	i = 0;
	while (current && i < len)
	{
		gc_lstadd_back(gc, &result, current->content);
		current = current->next;
		i++;
	}
	return (result);
}
