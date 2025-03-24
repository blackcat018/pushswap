/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trois.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 20:46:06 by codespace         #+#    #+#             */
/*   Updated: 2025/03/24 23:51:44 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void middle_is_small(t_list **stack, t_list *big)
{
    if((*stack)->next == big)
        sa(stack);
    else
        ra(stack);
}

void middle_is_big(t_list **stack, t_list *small)
{
    if((*stack)->next == small)
        rra(stack);
    else
    {
        rra(stack);
        sa(stack);
    }
}

void middle(t_list **stack, t_list *small)
{
    if((*stack)->next == small)
    {
        sa(stack);
        rra(stack);
    }
}
 void handle_three(t_list **stack)
 {
    t_list *tmp;
    t_list *small;
    t_list *big;

    tmp = *stack;
    small = find_smallest_nb(stack);
    big = find_biggest_nb(stack);
    if(tmp->next == small)
        middle_is_small(stack,big);
    else if (tmp->next == big)
        middle_is_big(stack,small);
    else
        middle(stack,small);
 }