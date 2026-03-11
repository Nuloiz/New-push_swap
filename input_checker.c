/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:29:34 by nschutz           #+#    #+#             */
/*   Updated: 2026/03/11 15:16:32 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	correct_input_digits(char *number)
{
	int		i;
	long	test;

	i = 1;
	test = ft_atoi(number);
	if (test > 2147483647 || test < -2147483648)
		return (0);
	if (!ft_isdigit(number[0]) && number[0] != '-')
		return (0);
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	correct_number(char **list)
{
	int	i;
	int	index;

	i = 0;
	while (list[i])
	{
		index = correct_input_digits(list[i]);
		if (index == 0)
			return (0);
		i++;
	}
	return (1);
}

int	input_checker(int argc, char **argv)
{
	int		index;
	int		one;
	char	**list;

	one = 0;
	if (argc == 1)
	{
		list = ft_split(argv[0], ' ');
		if (!list || !list[0])
		{
			if (list)
				free_array(list);
			return (0);
		}
		one = 1;
	}
	else
		list = argv;
	index = correct_number(list);
	if (!no_int_twice(list))
		index = 0;
	if (one == 1)
		free_array(list);
	if (one == 1 && index == 1)
		return (2);
	return (index);
}
