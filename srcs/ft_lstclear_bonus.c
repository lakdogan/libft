/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 22:14:36 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 18:17:53 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

/**
 * @brief Clears and frees an entire linked list.
 *
 * Iterates through the list, applies the function del to free
 * the content of each node, then frees the node itself.
 * Finally, sets the list pointer to NULL.
 *
 * @param lst Pointer to the pointer of the first node.
 * @param del Function to free the content of a node.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
	return ;
}
