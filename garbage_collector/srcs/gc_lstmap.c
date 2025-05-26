/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:52:47 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/27 00:13:22 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/garbage_collector.h"

/**
 * @brief Maps a list to a new list with transformed content
 *
 * Creates a new list by applying a function to each element of the original
 * list. All nodes in the new list are managed by the garbage collector.
 *
 * @param gc Pointer to the garbage collector
 * @param lst List to map
 *
 * @param f Function to apply to each element's 
 * content (receives GC and content)
 * @param del Function to delete content if an error occurs
 * @return t_list* New list with transformed content,
 *	or NULL if allocation fails
 */
t_list	*gc_lstmap(t_gc *gc, t_list *lst, void *(*f)(t_gc *, void *),
		void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_elem;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_elem = gc_lstnew(gc, f(gc, lst->content));
		if (!new_elem)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_elem);
		lst = lst->next;
	}
	return (new_list);
}
