/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-idr <moel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:16:28 by codespace         #+#    #+#             */
/*   Updated: 2025/03/25 13:16:41 by moel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	initialize_index(t_list **stack)
{
	t_list	*curr;

	curr = *stack;
	while (curr)
	{
		curr->index = -1;
		curr = curr->next;
	}
}

void	indexing(t_list **stack)
{
	int		size;
	int		i;
	t_list	*curr;
	t_list	*min;

	i = 0;
	size = ft_lstsize(*stack);
	curr = *stack;
	min = NULL;
	while (i < size)
	{
		curr = *stack;
		min = NULL;
		while (curr)
		{
			if (curr->index == -1 && (!min || curr->value < min->value))
				min = curr;
			curr = curr->next;
		}
		if (min)
			min->index = i++;
	}
}

void	pushing(t_list **stack_a, t_list **stack_b)
{
	int		a;
	int		b;
	t_list	*tmp;

	a = 0;
	b = (ft_lstsize(*stack_a) * 0.05 + 10);
	while (*stack_a)
	{
		tmp = *stack_a;
		if (tmp->index >= a && tmp->index <= b)
		{
			pb(stack_a, stack_b);
			a++;
			b++;
		}
		else if (tmp->index < a)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			a++;
			b++;
		}
		else if (tmp->index > b)
			ra(stack_a);
	}
}

void	get_back_to_a(t_list **stack_b, t_list *biggest)
{
	int		size;
	int		pos;
	t_list	*tmp;

	pos = 0;
	size = ft_lstsize(*stack_b);
	tmp = *stack_b;
	while (tmp && tmp != biggest)
	{
		tmp = tmp->next;
		pos++;
	}
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rb(stack_b);
	}
	else
	{
		while (pos++ < size)
			rrb(stack_b);
	}
}

void	range(t_list **stack_a, t_list **stack_b)
{
	initialize_index(stack_a);
	indexing(stack_a);
	pushing(stack_a, stack_b);
	while (*stack_b)
	{
		get_back_to_a(stack_b, find_biggest_nb(stack_b));
		pa(stack_a, stack_b);
	}
}
