/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:34:38 by nschutz           #+#    #+#             */
/*   Updated: 2023/07/19 11:24:15 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	no_int_twice(char **list)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (list[i])
	{
		j = i;
		k = (int)ft_atoi(list[i]);
		while (list[j + 1])
		{
			if (k == (int)ft_atoi(list[j + 1]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void	sorting(int num_of_arg, t_node *stack)
{
	if (already_sorted(stack))
		return ;
	if (num_of_arg <= 3)
		three_arg(stack);
	else if (num_of_arg <= 5)
		five_arg(num_of_arg, stack);
	else
		radix_sort(stack);
}

static void	new_list(char **list, int index)
{
	t_node	*stack_a;
	int		*new_list;
	int		num_of_arg;

	num_of_arg = 0;
	stack_a = NULL;
	while (list[num_of_arg])
		num_of_arg++;
	new_list = new_numbers(num_of_arg, list, index);
	if (!new_list)
		return ;
	linked_list_start(num_of_arg, new_list, &stack_a);
	free(new_list);
	if (!stack_a)
		return ;
	sorting(num_of_arg, stack_a);
}

int	main(int argc, char	**argv)
{
	int		index;
	char	**list;

	argc = argc -1;
	argv = argv + 1;
	index = input_checker(argc, argv);
	if (argc == 0 || index == 0)
		return (ft_putendl_fd("Error", 2), 0);
	else if (index == 2)
	{
		list = ft_split(argv[0], ' ');
		if (!list)
			return (0);
	}
	else
		list = argv;
	new_list(list, index);
	if (index == 2)
		free_array(list);
	else
		free_array_list(argc, list);
	return (1);
}
