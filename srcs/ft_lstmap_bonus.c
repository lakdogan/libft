/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 22:31:23 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:19:40 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/**
 * @brief Adds a new node to the mapped list.
 *
 * Transforms original_content using f and creates a new node.
 * If transformation or node creation fails, clears the new list.
 *
 * @param new_list_head Pointer to the head of the new list.
 * @param original_content The content from the original list.
 * @param f Function to transform the content.
 * @param del Function to delete content on error.
 * @return 1 on success, 0 on failure.
 */
static int	ft_lstmap_add_node(t_list **new_list_head, void *original_content,
		void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	void	*transformed_content;

	transformed_content = f(original_content);
	if (!transformed_content)
	{
		ft_lstclear(new_list_head, del);
		return (0);
	}
	new_node = ft_lstnew(transformed_content);
	if (!new_node)
	{
		del(transformed_content);
		ft_lstclear(new_list_head, del);
		return (0);
	}
	ft_lstadd_back(new_list_head, new_node);
	return (1);
}

/**
 * @brief Maps a function over a linked list.
 *
 * Iterates over the original list and applies f to each node's
 * content, building a new list. On error, the new list is cleared.
 *
 * @param list The original linked list.
 * @param f Function to transform each node's content.
 * @param del Function to delete content if needed.
 * @return The new linked list, or NULL on failure.
 */
t_list	*ft_lstmap(t_list *list, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list_head;

	new_list_head = NULL;
	if (!list || !f || !del)
		return (NULL);
	while (list)
	{
		if (!ft_lstmap_add_node(&new_list_head, list->content, f, del))
			return (NULL);
		list = list->next;
	}
	return (new_list_head);
}
