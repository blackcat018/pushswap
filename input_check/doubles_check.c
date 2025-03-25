/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubles_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-idr <moel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:15:09 by moel-idr          #+#    #+#             */
/*   Updated: 2025/03/25 16:42:06 by moel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	del(void *content)
{
	content = NULL;
	(void)content;
}
int	check_doubles(t_list **stack)
{
	int		*tab;
	t_list	*tmp;
	
	int (list_size), (tracker), (i);
	list_size = ft_lstsize(*stack);
	tab = malloc(sizeof(int) * list_size);
	if (!tab)
		return (1);
	tmp = *stack;
	tracker = 0;
	while (tmp)
	{
		i = 0;
		while (i < tracker)
		{
			if (tmp->value == tab[i])
				return (free(tab), 1);
			i++;
		}
		tab[tracker] = tmp->value;
		tracker++;
		tmp = tmp->next;
	}
	return (free(tab), 0);
}
