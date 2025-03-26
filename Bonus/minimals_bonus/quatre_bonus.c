/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quatre_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-idr <moel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 20:46:06 by codespace         #+#    #+#             */
/*   Updated: 2025/03/25 21:30:18 by moel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	is_it_minimal(t_list *stack_a)
{
	if (ft_lstsize(stack_a) == 2)
		return (2);
	else if (ft_lstsize(stack_a) == 3)
		return (3);
	else if (ft_lstsize(stack_a) == 4)
		return (4);
	else if (ft_lstsize(stack_a) == 5)
		return (5);
	return (0);
}

void	handle_minimals(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = is_it_minimal(*stack_a);
	if (size == 2)
		handle_two(stack_a);
	else if (size == 3)
		handle_three(stack_a);
	else if (size == 4)
		handle_four(stack_a, stack_b);
	else if (size == 5)
		handle_five(stack_a, stack_b);
	else
		return ;
}

void	handle_four(t_list **stack_a, t_list **stack_b)
{
	t_list	*small;
	t_list	*tmp;
	int		pos;

	small = find_smallest_nb(stack_a);
	pos = 0;
	tmp = *stack_a;
	while (tmp != small)
	{
		tmp = (tmp)->next;
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

void	handle_two(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*small;

	tmp = *stack_a;
	small = find_smallest_nb(stack_a);
	if (tmp->next == small)
		sa(stack_a);
}
