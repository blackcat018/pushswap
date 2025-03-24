/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:42:00 by codespace         #+#    #+#             */
/*   Updated: 2025/03/24 20:06:16 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int main(int ac, char **av)
{
    t_list *stack_a;
    t_list *stack_b;
    long *tab;

    int (i), (j);
    i = 1;
    stack_b = NULL;
    stack_a = NULL;
    while(i < ac)
    {
        tab = get_args(av[i]);
        j = 0;
        while(tab[j])
        {
            ft_lstadd_back(&stack_a,ft_lstnew(tab[j]));
            if(check_doubles(&stack_a) == 1)
                return(ft_putstr_fd("Double argument detected!\n",1), 1);
            j++;
        }
        free(tab);
        i++;
    }
    range(&stack_a, &stack_b);
    return (0);
}