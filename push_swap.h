/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:15:14 by moel-idr          #+#    #+#             */
/*   Updated: 2025/03/24 16:27:28 by codespace        ###   ########.fr       */
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

long	*get_args(char *str);
int check_doubles(t_list **stack);

#endif


