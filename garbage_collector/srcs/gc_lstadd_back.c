/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:53:50 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/25 22:40:50 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/garbage_collector.h"

/**
 * @brief Creates a new node and adds it to the end of a list
 *
 * Combines the functionality of gc_lstnew and ft_lstadd_back into a single
 * function. The new node is managed by the garbage collector.
 *
 * @param gc Pointer to the garbage collector
 * @param lst Address of the pointer to the first node
 * @param content Content to store in the new node
 */
void	gc_lstadd_back(t_gc *gc, t_list **lst, void *content)
{
	t_list	*new_node;

	new_node = gc_lstnew(gc, content);
	if (new_node)
		ft_lstadd_back(lst, new_node);
}
