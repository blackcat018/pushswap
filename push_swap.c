/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-idr <moel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:42:00 by codespace         #+#    #+#             */
/*   Updated: 2025/03/25 21:29:26 by moel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_element(char *av)
{
	int (has_digit), (element), (i);
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

void	cleanup(t_list **stack_a, t_list **stack_b)
{
	if (stack_a && *stack_a)
		ft_lstclear(stack_a, del);
	if (stack_b && *stack_b)
		ft_lstclear(stack_b, del);
}

static int	process_arguments(int ac, char **av, t_list **stack_a)
{
	long	*tab;

	int (elems), (i), (j);
	i = 1;
	while (i < ac)
	{
		tab = get_args(av[i]);
		if (!tab)
			return (1);
		elems = count_element(av[i]);
		if (elems == 0)
			return (free(tab), 1);
		j = 0;
		while (j < elems)
		{
			ft_lstadd_back(stack_a, ft_lstnew(tab[j]));
			if (check_doubles(stack_a) == 1)
				return (free(tab), 1);
			j++;
		}
		free(tab);
		i++;
	}
	return (0);
}

static int	handle_stacks(t_list **stack_a, t_list **stack_b)
{
	if (is_it_minimal(*stack_a) != 0)
	{
		handle_minimals(stack_a, stack_b);
		return (1);
	}
	range(stack_a, stack_b);
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (ac < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (process_arguments(ac, av, &stack_a) != 0)
	{
		cleanup(&stack_a, &stack_b);
		return (ft_putstr_fd("Error\n", 2), 1);
	}
	if (sort_check(stack_a) == 1)
		return (cleanup(&stack_a, &stack_b), 0);
	handle_stacks(&stack_a, &stack_b);
	cleanup(&stack_a, &stack_b);
	return (0);
}
