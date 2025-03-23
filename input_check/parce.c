/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-idr <moel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:15:01 by moel-idr          #+#    #+#             */
/*   Updated: 2025/03/23 23:15:02 by moel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	skip_space(int i, char *str)
{
	while (str[i] == ' ')
		i++;
	return (i);
}

void	is_empty(char *str)
{
	int	i;

	i = skip_space(0, str);
	if (str[i] == '\0')
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}

int	skip_numbers(int i, char *str)
{
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}
int	just_numbers(char *str)
{
	int	i;

	i = 0;
	is_empty(str);
	while (str[i])
	{
		i = skip_space(i, str);
		if (str[i] == '-' || str[i] == '+')
		{
			i++;
			if (!ft_isdigit(str[i]))
			{
				write(2, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
		}
		i = skip_numbers(i, str);
		if ((str[i] != '\0') && (str[i] != ' '))
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}
