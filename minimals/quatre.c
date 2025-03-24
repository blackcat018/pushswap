/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quatre.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 20:46:06 by codespace         #+#    #+#             */
/*   Updated: 2025/03/24 23:49:58 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	handle_four(t_list **stack_a, t_list **stack_b)
{
	t_list	*small;
	int		pos;

	small = find_smallest_nb(stack_a);
	pos = 0;
	while (*stack_a != small)
	{
		*stack_a = (*stack_a)->next;
		pos++;
	}
	if (pos == 1)
		ra(stack_a);
	else if (pos == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (pos == 3)
		rra(stack_a);
	pb(stack_a, stack_b);
	handle_three(stack_a);
	pa(stack_a, stack_b);
}
