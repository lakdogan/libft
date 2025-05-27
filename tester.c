/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:05:46 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/27 18:44:21 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

typedef struct  s_test
{
    void* content;
    char* lst_str_content;
    char** str_2d;
    char*** str_3d;
    t_list *next;
    
} t_test;

int main(void)
{
    char *strs;
    char **str_2d;
    char ***str_3d;
    int *nums;
    int **nums_2d;
    int ***nums_3d;
    t_test *lst;

    t_gc *gc_one;
    t_gc *gc_two;
    t_gc *gc_three;
// instance creations and allocations    
    gc_one = gc_create();
    gc_two = gc_create();
    gc_three = gc_create();
// string allocations
    strs = gc_strdup(gc_one, "This is a test string");
    str_2d = gc_str_array_create(gc_one, 10);
    str_3d = gc_str_3d_create(gc_one, 2, 2, 10);
// integer allocations    
    nums = gc_int_array_create(gc_two, 50);
    nums_2d = gc_int_matrix_create(gc_two, 10, 5);
    nums_3d = gc_int_3d_create(gc_two, 2, 5, 2);
// lst node allocations
    lst = gc_alloc_struct(gc_one, 40); // 8 byte each datatype
    lst->content = gc_strdup(gc_three, "first node content");
    lst->lst_str_content = gc_strdup(gc_one, "String content");
    lst->str_2d = gc_str_array_create(gc_two, 10);
    lst->str_3d = gc_str_3d_create(gc_three, 55, 24, 212);
    lst->next = NULL;
// final cleanup
    gc_cleanup(&gc_one);
    gc_cleanup(&gc_two);
    gc_cleanup(&gc_three);

    return (0);
}
