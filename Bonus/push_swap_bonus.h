/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-idr <moel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:15:14 by moel-idr          #+#    #+#             */
/*   Updated: 2025/03/25 23:13:25 by moel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../utils/libft/libft.h"
# include "gnl_bonus/get_next_line_bonus.h"
# include <stdio.h>
# include <stdlib.h>

void	cleanup(t_list **stack_a, t_list **stack_b);
void	free_split(char **strs);
void	del(void *content);

void	range(t_list **stack_a, t_list **stack_b);

int		just_numbers(char *str);
long	*get_args(char *str);

t_list	*find_smallest_nb(t_list **stack);
t_list	*find_biggest_nb(t_list **stack);

int		rotate(t_list **stack);
int		reverserotate(t_list **stack);

int		pa(t_list **stack_a, t_list **stack_b);
int		pb(t_list **stack_a, t_list **stack_b);

int		rra(t_list **stack_a);
int		rrb(t_list **stack_b);

int		ra(t_list **stack_a);
int		rb(t_list **stack_b);

int		sa(t_list **stack_a);
int		sb(t_list **stack_b);

int		rr(t_list **stack_a, t_list **stack_b);
int		rrr(t_list **stack_a, t_list **stack_b);

int		is_it_minimal(t_list *stack_a);
void	handle_minimals(t_list **stack_a, t_list **stack_b);
void	handle_two(t_list **stack_a);
void	handle_three(t_list **stack);
void	handle_four(t_list **stack_a, t_list **stack_b);
void	handle_five(t_list **stack_a, t_list **stack_b);

int		sort_check(t_list *stack);
int		check_doubles(t_list **stack);

int		apply_move(t_list **stack_a, t_list **stack_b, char *str);
void	read_input(t_list **stack_a, t_list **stack_b);

#endif
