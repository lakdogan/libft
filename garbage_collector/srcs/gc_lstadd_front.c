/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 21:54:42 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/27 00:11:53 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/garbage_collector.h"

/**
 * @brief Adds a new node to the front of a list
 *
 * Creates a new node with the given content and adds it to the front
 * of the list. Both the node and its content are tracked by the GC.
 *
 * @param gc Pointer to the garbage collector
 * @param lst Address of the pointer to the first link of a list
 * @param content Content to add to the new node
 */
void	gc_lstadd_front(t_gc *gc, t_list **lst, void *content)
{
	t_list	*new_node;

	if (!lst)
		return ;
	new_node = gc_lstnew(gc, content);
	if (!new_node)
		return ;
	new_node->next = *lst;
	*lst = new_node;
}
