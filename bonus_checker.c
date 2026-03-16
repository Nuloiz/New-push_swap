/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 16:08:46 by nschutz           #+#    #+#             */
/*   Updated: 2026/03/16 16:35:04 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_checker.h"

int	create_stack_helper(int argc, char **list, int index, t_node **stack_a)
{
	int		num;
	int		*new_list;

	num = 0;
	while (list[num])
		num++;
	new_list = new_numbers(num, list, index);
	if (!new_list)
		return (0);
	linked_list_start(num, new_list, stack_a);
	free(new_list);
	if (index == 2)
		free_array(list);
	else
		free_array_list(argc, list);
	if (!(*stack_a))
		return (0);
	return (1);
}

int	create_stack(int argc, char **argv, int index, t_node **stack_a)
{
	char	**list;

	if (index == 2)
	{
		list = ft_split(argv[0], ' ');
		if (!list)
			return (0);
	}
	else
		list = argv;
	return (create_stack_helper(argc, list, index, stack_a));
}

int	exec_check_op(char *list, t_node **stack_a, t_node **stack_b)
{
	if (ft_strncmp(list, "sa", 3) == 0)
		sa(*stack_a);
	else if (ft_strncmp(list, "sb", 3) == 0)
		sb(*stack_b);
	else if (ft_strncmp(list, "ss", 3) == 0)
		ss(*stack_a, *stack_b);
	else if (ft_strncmp(list, "ra", 3) == 0)
		rotate_stack(stack_a, stack_b, "ra");
	else if (ft_strncmp(list, "rb", 3) == 0)
		rotate_stack(stack_a, stack_b, "rb");
	else if (ft_strncmp(list, "rr", 3) == 0)
		rotate_stack(stack_a, stack_b, "rr");
	else if (ft_strncmp(list, "rra", 4) == 0)
		rotate_stack(stack_a, stack_b, "rra");
	else if (ft_strncmp(list, "rrb", 4) == 0)
		rotate_stack(stack_a, stack_b, "rrb");
	else if (ft_strncmp(list, "rrr", 4) == 0)
		rotate_stack(stack_a, stack_b, "rrr");
	else if (ft_strncmp(list, "pa", 3) == 0)
		pa(stack_a, stack_b);
	else if (ft_strncmp(list, "pb", 3) == 0)
		pb(stack_a, stack_b);
	else
		return (0);
	return (1);
}

int	exec_check(t_node **stack_a, t_node **stack_b)
{
	int		i;
	char	**list;

	i = 0;
	list = get_lines();
	if (!list)
		return (0);
	while (list[i])
	{
		if (!exec_check_op(list[i], stack_a, stack_b))
		{
			free_array(list);
			return (0);
		}
		i++;
	}
	free_array(list);
	return (1);
}

int	main(int argc, char **argv)
{
	int		index;
	t_node	*stack_a;
	t_node	*stack_b;

	argc = argc -1;
	argv = argv + 1;
	stack_a = NULL;
	stack_b = NULL;
	index = input_checker(argc, argv);
	if (argc == 0 || index == 0)
		return (ft_putendl_fd("Error", 2), 0);
	if (!create_stack(argc, argv, index, &stack_a))
		return (ft_putendl_fd("Error", 2), 0);
	if (!exec_check(&stack_a, &stack_b))
		return (ft_putendl_fd("Error", 2), 0);
	if (check_stacks(stack_a, stack_b))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	free_stack(&stack_a);
	return (0);
}
