/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:36:29 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/25 22:41:13 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/garbage_collector.h"

/**
 * @brief Creates a new list node managed by the garbage collector
 *
 * @param gc Pointer to the garbage collector
 * @param content Content to store in the node
 * @return t_list* Pointer to the new node, or NULL if allocation fails
 */
t_list	*gc_lstnew(t_gc *gc, void *content)
{
	t_list	*new;

	new = ft_lstnew(content);
	if (new)
		gc_register(gc, new, sizeof(t_list));
	return (new);
}
