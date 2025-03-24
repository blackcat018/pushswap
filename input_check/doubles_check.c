/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubles_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:15:09 by moel-idr          #+#    #+#             */
/*   Updated: 2025/03/24 15:29:04 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void del(void *content)
{
    content = NULL;
    (void)content;
}
int check_doubles(t_list **stack)
{
    int i;
    int *tab;
    int tracker;
    t_list  *tmp;

    tab = malloc(sizeof(int)*(ft_lstsize(*stack)));
    tmp = *stack;
    tracker = 0;
    while(tmp)
    {
        i = 0;
        while(i < tracker)
        {
            if(tmp->value == tab[i])
            {
                ft_lstclear(stack,del);
                return(1);
            }
            i++;
        }
        tab[i] = tmp->value;
        tracker++;
        tmp = tmp->next;
    }
    free(tmp);
    return(0);
}