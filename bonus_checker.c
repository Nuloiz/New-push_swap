/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 16:08:46 by nschutz           #+#    #+#             */
/*   Updated: 2026/03/16 12:49:25 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_checker.h"

int	check_stacks(t_node *stack_a, t_node *stack_b)
{
	if (stack_b != NULL)
		return (0);
	while (stack_a != NULL)
	{
		if (stack_a->next != NULL && stack_a->value > stack_a->next->value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	create_stack(int argc, char **argv, int index, t_node **stack_a)
{
	char	**list;
	int		num;

	if (index == 2)
	{
		list = ft_split(argv[0], ' ');
		if (!list)
			return (0);
	}
	else
		list = argv;
	while (list[num])
		num++;
	linked_list_start(num, list, stack_a);
	free(list);
	if (!(*stack_a))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	int		index;
	t_node	*stack_a;
	t_node	*stack_b;
	char	**list;

	argc = argc -1;
	argv = argv + 1;
	stack_a = NULL;
	stack_b = NULL;
	index = input_checker(argc, argv);
	if (argc == 0 || index == 0)
		return (ft_putendl_fd("Error", 2), 0);
	index = create_stack(argc, argv, index, &stack_a);
	list = get_lines();
	if (!list)
		return (free_stack(&stack_a), 0);
    //Save operations in a list
    //Execute operations on stacks
	if (check_stacks(stack_a, stack_b))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	free(list);
	free_stack(&stack_a);
	return (0);
}
