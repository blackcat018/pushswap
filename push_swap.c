/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-idr <moel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:42:00 by codespace         #+#    #+#             */
/*   Updated: 2025/03/25 14:49:03 by moel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_it_minimal(t_list *stack_a)
{
	if(ft_lstsize(stack_a) == 2)
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

int	count_element(char *av)
{
	int(has_digit), (element), (i);
	i = 0;
	element = 0;
	has_digit = 0;
	if (just_numbers(av) == 0)
	{
		while (av[i])
		{
			if (av[i] >= '0' && av[i] <= '9')
			{
				if (has_digit == 0)
				{
					element++;
					has_digit = 1;
				}
			}
			else if (av[i] == ' ')
				has_digit = 0;
			i++;
		}
		return (element);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	long	*tab;

	int(i), (j), (elems);
	i = 1;
	elems = 0;
	stack_b = NULL;
	stack_a = NULL;
	while (i < ac)
	{
		tab = get_args(av[i]);
		elems = count_element(av[i]);
		j = 0;
		while (j < elems)
		{
			ft_lstadd_back(&stack_a, ft_lstnew(tab[j]));
			if (check_doubles(&stack_a) == 1)
				return (ft_putstr_fd("Error\n", 2), 1);
			j++;
		}
		free(tab);
		i++;
	}
	if (is_it_minimal(stack_a) != 0)
	{
		handle_minimals(&stack_a, &stack_b);
		return (0);
	}
	return (range(&stack_a, &stack_b), 0);
}
