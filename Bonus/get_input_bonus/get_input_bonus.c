/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-idr <moel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:36:02 by moel-idr          #+#    #+#             */
/*   Updated: 2025/03/25 23:58:31 by moel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	apply_move(t_list **stack_a, t_list **stack_b, char *str)
{
	if (ft_strncmp(str, "rr\n", 3) == 0)
		rr(stack_a, stack_b);
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		rrr(stack_a, stack_b);
	else if (ft_strncmp(str, "ra\n", 3) == 0)
		ra(stack_a);
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		rra(stack_a);
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		rb(stack_b);
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		rrb(stack_b);
	else if (ft_strncmp(str, "sa\n", 3) == 0)
		sa(stack_a);
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		sb(stack_b);
	else if (ft_strncmp(str, "pa\n", 3) == 0)
		pa(stack_a, stack_b);
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		pb(stack_a, stack_b);
	else
		return (-1);
	return (0);
}

void	read_input(t_list **stack_a, t_list **stack_b)
{
	char	*str;

	str = get_next_line(0);
	while (str != NULL)
	{
		if (apply_move(stack_a, stack_b, str) == -1)
		{
			free(str);
			cleanup(stack_a, stack_b);
			exit(1);
		}
		free(str);
		str = get_next_line(0);
	}
	if (sort_check(*stack_a) == 1 && *stack_b == NULL)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	cleanup(stack_a, stack_b);
}
