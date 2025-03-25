/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trois.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-idr <moel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 20:46:06 by codespace         #+#    #+#             */
/*   Updated: 2025/03/25 14:46:03 by moel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	middle_is_small(t_list **stack, t_list *big)
{
	if (big->next == NULL)
		sa(stack);
	else
		ra(stack);
}

void	middle_is_big(t_list **stack, t_list *small)
{
	if (small->next == NULL)
		rra(stack);
	else
	{
		rra(stack);
		sa(stack);
	}
}

void	middle(t_list **stack, t_list *small)
{
	if (small->next == NULL)
	{
		sa(stack);
		rra(stack);
	}
}
void	handle_three(t_list **stack)
{
	t_list *tmp;
	t_list *small;
	t_list *big;

	tmp = *stack;
	small = find_smallest_nb(stack);
	big = find_biggest_nb(stack);
	if (tmp->next == small)
		middle_is_small(stack, big);
	else if (tmp->next == big)
		middle_is_big(stack, small);
	else
		middle(stack, small);
}
