/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:19:57 by lakdogan          #+#    #+#             */
/*   Updated: 2025/02/20 17:50:39 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/**
 * @brief Validates the new size and frees memory if the size is zero.
 *
 * This function checks if the new memory size is zero. If so, it frees
 * the given pointer and resets the allocated size to zero.
 *
 * @param ptr Pointer to the currently allocated memory.
 * @param new_size The requested new size of the memory block.
 * @param allocated_size Pointer to the variable holding the current allocated size.
 * @return 1 if new_size is non-zero and reallocation should proceed, 0 if memory was freed.
 */
static int	validate_size_and_free(void *ptr, size_t new_size,
		size_t *allocated_size)
{
	if (new_size == 0)
	{
		free(ptr);
		*allocated_size = 0;
		return (0);
	}
	return (1);
}

/**
 * @brief Copies memory content from old pointer to new pointer and frees the old memory.
 *
 * Copies the minimum of `new_size` and `allocated_size` bytes from `ptr` to `new_ptr`,
 * and then frees the old pointer.
 *
 * @param new_ptr Pointer to the newly allocated memory.
 * @param ptr Pointer to the previously allocated memory.
 * @param new_size The size of the new memory block.
 * @param allocated_size The size of the original memory block.
 */
static void	copy_memory_and_free(void *new_ptr, void *ptr, size_t new_size,
		size_t allocated_size)
{
	size_t	copy_size;

	if (allocated_size < new_size)
		copy_size = allocated_size;
	else
		copy_size = new_size;
	ft_memcpy(new_ptr, ptr, copy_size);
	free(ptr);
}

/**
 * @brief Custom realloc implementation that resizes a memory block with bookkeeping.
 *
 * Handles NULL pointers, zero-size reallocations, and copies old data into the new block.
 * It also updates the `allocated_size` to reflect the new memory size.
 *
 * @param ptr Pointer to the currently allocated memory (can be NULL).
 * @param new_size The requested size for the new memory block.
 * @param allocated_size Pointer to the variable tracking the currently allocated size.
 * @return Pointer to the newly allocated memory block, or NULL on failure or if new_size is 0.
 */
void	*ft_realloc(void *ptr, size_t new_size, size_t *allocated_size)
{
	void	*new_ptr;
	size_t	allocated_size_for_calloc;

	allocated_size_for_calloc = *allocated_size;
	if (!validate_size_and_free(ptr, new_size, allocated_size))
		return (NULL);
	if (ptr == NULL)
	{
		new_ptr = ft_calloc(new_size, allocated_size_for_calloc);
		return (new_ptr);
	}
	new_ptr = ft_calloc(1, new_size);
	if (check_memory_allocation(new_ptr) == NULL)
		return (NULL);
	copy_memory_and_free(new_ptr, ptr, new_size, *allocated_size);
	*allocated_size = new_size;
	return (new_ptr);
}
