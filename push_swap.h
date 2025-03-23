/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-idr <moel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:15:14 by moel-idr          #+#    #+#             */
/*   Updated: 2025/03/23 23:15:15 by moel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include "utils/libft/libft.h"

typedef struct s_list
{
	void			*content;
	int				value;
	int				index;
	struct s_list	*next;
}					t_list;

typedef struct range
{
	int		min;
	int		max;
}			t_range;
#endif