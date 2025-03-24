/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:15:01 by moel-idr          #+#    #+#             */
/*   Updated: 2025/03/24 16:27:16 by codespace        ###   ########.fr       */
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
				ft_putstr_fd("Error! Non Digit detected\n", 1);
				exit(EXIT_FAILURE);
			}
		}
		i = skip_numbers(i, str);
		if ((str[i] != '\0') && (str[i] != ' '))
		{
			ft_putstr_fd("Error! Non Digit detected\n", 1);
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}

long	*get_args(char *str)
{
	int i;
	char **args;
	long *nums;

	i = 0;
	if(just_numbers(str) == 0)
	{
		args =ft_split(str,' ');
		if(!args)
			exit(1);
		while(args[i])
			i++;
		nums = malloc(sizeof(int) * i);
		i = 0;
		while(args[i])
		{
			nums[i] = ft_atoi(args[i]);
			if(nums[i] > 2147483647 || nums[i] < -2147483648)
			{
				free(nums);
				ft_putstr_fd("number is not valid!",1);
				exit(1);
			}
			i++;
		}
		return (nums);
	}
	ft_putstr_fd("Error while getting arguments",1);
	exit(1);
}
