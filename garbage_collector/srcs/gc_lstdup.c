/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 21:56:46 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/27 00:11:58 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/garbage_collector.h"

/**
 * @brief Creates a full copy of a list
 *
 * Creates a complete duplicate of the given list, with all nodes and
 * content tracked by the garbage collector.
 *
 * @param gc Pointer to the garbage collector
 * @param lst List to duplicate
 * @return t_list* Newly created list or NULL if allocation fails
 */
t_list	*gc_lstdup(t_gc *gc, t_list *lst)
{
	t_list	*new_list;
	t_list	*current;
	t_list	*temp;

	if (!lst)
		return (NULL);
	new_list = NULL;
	current = lst;
	while (current)
	{
		temp = gc_lstnew(gc, current->content);
		if (!temp)
			return (NULL);
		ft_lstadd_back(&new_list, temp);
		current = current->next;
	}
	return (new_list);
}
