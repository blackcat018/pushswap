/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:15:14 by moel-idr          #+#    #+#             */
/*   Updated: 2025/03/24 20:05:31 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include "utils/libft/libft.h"
#include<stdio.h>
#include <stdlib.h>



typedef struct range
{
	int		min;
	int		max;
}			t_range;

void range(t_list **stack_a, t_list **stack_b);

long	*get_args(char *str);

t_list	*find_smallest_nb(t_list **stack);
t_list	*find_biggest_nb(t_list **stack);

int	pa(t_list **stack_a, t_list **stack_b);
int	pb(t_list **stack_a, t_list **stack_b);

int	rra(t_list **stack_a);
int	rrb(t_list **stack_b);

int	ra(t_list **stack_a);
int	rb(t_list **stack_b);

int	sa(t_list **stack_a);
int	sb(t_list **stack_b);

int check_doubles(t_list **stack);

#endif


