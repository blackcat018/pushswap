/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubles_check_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-idr <moel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:15:09 by moel-idr          #+#    #+#             */
/*   Updated: 2025/03/25 21:31:18 by moel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	del(void *content)
{
	content = NULL;
	(void)content;
}

int	sort_check(t_list *stack)
{
	if (!stack)
		return (1);
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	free_split(char **strs)
{
	char	**temp;

	if (strs == NULL)
		return ;
	temp = strs;
	while (*temp)
	{
		free(*temp);
		temp++;
	}
	free(strs);
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
