/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-idr <moel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:15:01 by moel-idr          #+#    #+#             */
/*   Updated: 2025/03/25 21:31:30 by moel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

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
				ft_putstr_fd("Error\n", 2);
				exit(EXIT_FAILURE);
			}
		}
		i = skip_numbers(i, str);
		if ((str[i] != '\0') && (str[i] != ' '))
		{
			ft_putstr_fd("Error\n", 2);
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}

long	*get_args(char *str)
{
	char	**args;
	long	*nums;

	int (i), (count);
	if (just_numbers(str) != 0)
		return (ft_putstr_fd("Error\n", 2), exit(1), NULL);
	args = ft_split(str, ' ');
	if (!args)
		exit(1);
	count = 0;
	while (args[count])
		count++;
	nums = malloc(sizeof(long) * (count + 1));
	if (!nums)
		return (free_split(args), ft_putstr_fd("Error\n", 2), exit(1), NULL);
	i = 0;
	while (i < count)
	{
		nums[i] = ft_atoi(args[i]);
		if (nums[i] > 2147483647 || nums[i] < -2147483648)
			return (free(nums), free_split(args), ft_putstr_fd("Error\n", 2),
				exit(1), NULL);
		i++;
	}
	return (free_split(args), nums);
}
