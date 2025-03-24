/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:42:00 by codespace         #+#    #+#             */
/*   Updated: 2025/03/24 16:28:29 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int main(int ac, char **av)
{
    int i;
    t_list *stack;
    long *tab;
    int j;

    i = 1;
    stack = NULL;
    while(i < ac)
    {
        tab = get_args(av[i]);
        j = 0;
        while(tab[j])
        {
            ft_lstadd_back(&stack,ft_lstnew(tab[j]));
            if(check_doubles(&stack) == 1)
            {
                ft_putstr_fd("Double argument detected!\n",1);
                return(1);
            }
            j++;
        }
        free(tab);
        i++;
    }
    while(stack)
    {
        printf("-------------- : %d ---------\n",stack->value);
        stack = stack->next;
    }
    return (0);
}