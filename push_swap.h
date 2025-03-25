/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-idr <moel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:15:14 by moel-idr          #+#    #+#             */
/*   Updated: 2025/03/25 15:24:37 by moel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "utils/libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

void	del(void *content);

void	range(t_list **stack_a, t_list **stack_b);

int		just_numbers(char *str);
long	*get_args(char *str);

t_list	*find_smallest_nb(t_list **stack);
t_list	*find_biggest_nb(t_list **stack);

int		pa(t_list **stack_a, t_list **stack_b);
int		pb(t_list **stack_a, t_list **stack_b);

int		rra(t_list **stack_a);
int		rrb(t_list **stack_b);

int		ra(t_list **stack_a);
int		rb(t_list **stack_b);

int		sa(t_list **stack_a);
int		sb(t_list **stack_b);

int	is_it_minimal(t_list *stack_a);
void	handle_minimals(t_list **stack_a, t_list **stack_b);
void	handle_two(t_list **stack_a);
void	handle_three(t_list **stack);
void	handle_four(t_list **stack_a, t_list **stack_b);
void	handle_five(t_list **stack_a, t_list **stack_b);

int		check_doubles(t_list **stack);

#endif
