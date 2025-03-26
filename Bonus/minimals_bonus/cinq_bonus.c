/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cinq_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-idr <moel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 20:46:06 by codespace         #+#    #+#             */
/*   Updated: 2025/03/25 21:30:14 by moel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	push_to_top(t_list **stack_a, int pos)
{
	if (pos < 0 || pos > 4)
		return ;
	if (pos == 1)
	{
		ra(stack_a);
	}
	else if (pos == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (pos == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (pos == 4)
	{
		rra(stack_a);
	}
}

void	handle_five(t_list **stack_a, t_list **stack_b)
{
	t_list	*small;
	t_list	*current;
	int		pos;

	small = find_smallest_nb(stack_a);
	if (!small)
		return ;
	pos = 0;
	current = *stack_a;
	while (current != small)
	{
		current = current->next;
		pos++;
	}
	push_to_top(stack_a, pos);
	pb(stack_a, stack_b);
	handle_four(stack_a, stack_b);
	pa(stack_a, stack_b);
}
