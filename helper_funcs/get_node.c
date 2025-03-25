/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-idr <moel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:16:41 by moel-idr          #+#    #+#             */
/*   Updated: 2025/03/25 13:29:23 by moel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*find_smallest_nb(t_list **stack)
{
	int		nb;
	t_list	*current;
	t_list	*small;

	// if (*stack == NULL)
    //     return NULL;  
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

    // if (*stack == NULL)
    //     return NULL;  
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
