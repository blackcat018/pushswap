/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:16:41 by moel-idr          #+#    #+#             */
/*   Updated: 2025/03/24 16:47:30 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*find_smallest_nb(t_list **stack)
{
	int		nb;
	t_list	*current;
	t_list	*small;

	current = *stack;
	small = current;
	nb = current->value;
	while (current)
	{
		if (current->value < nb)
		{
			nb = current->value;
			small = current;
		}
		current = current->next;
	}
	return (small);
}

t_list	*find_biggest_nb(t_list **stack)
{
	int		nb;
	t_list	*current;
	t_list	*big;

	current = *stack;
	big = current;
	nb = current->value;
	while (current)
	{
		if (current->value > nb)
		{
			nb = current->value;
			big = current;
		}
		current = current->next;
	}
	return (big);
}

int num_of_moves(t_list **stack, t_list *curr)
{
	t_list *tmp;
	int moves;
	int pos;
	int size;

	moves = 0;
	pos = 0;
	tmp = *stack;
	size = ft_lstsize(tmp);
	while(tmp && tmp != curr)
	{
		pos++;
		tmp = tmp->next;
	}
	if (pos <= size / 2)
		while(pos-- > 0)
			moves++;
	else
		while(pos++ < size)
			moves++;
	return(moves);
}
