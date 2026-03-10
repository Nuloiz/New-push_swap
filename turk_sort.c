/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 12:08:58 by nschutz           #+#    #+#             */
/*   Updated: 2026/03/10 14:08:44 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_nodes(t_node *stack_a)
{
	t_node	*pos;
	int		count;

	pos = stack_a;
	count = 0;
	while (pos != NULL)
	{
		count++;
		pos = pos->next;
	}
	return (count);
}

void	set_up_sort(t_node **stack_a, t_node **stack_b)
{
	int	nodes;
	int	i;

	nodes = count_nodes(*stack_a);
	i = 0;
	while (i < (nodes - 3))
	{
		pb(stack_a, stack_b);
		i++;
	}
	*stack_a = three_arg(*stack_a);
}

void	exec_operations(t_node **stack_a, t_node **stack_b, char **operations)
{
	int	i;

	i = 0;
	while (operations[i] != NULL)
	{
		if (ft_strncmp(operations[i], "ra", 2) == 0)
			rotate_stack(stack_a, NULL, "ra");
		else if (ft_strncmp(operations[i], "rb", 2) == 0)
			rotate_stack(NULL, stack_b, "rb");
		else if (ft_strncmp(operations[i], "rr", 2) == 0)
			rotate_stack(stack_a, stack_b, "rr");
		else if (ft_strncmp(operations[i], "rra", 3) == 0)
			rotate_stack(stack_a, NULL, "rra");
		else if (ft_strncmp(operations[i], "rrb", 3) == 0)
			rotate_stack(NULL, stack_b, "rrb");
		else if (ft_strncmp(operations[i], "rrr", 3) == 0)
			rotate_stack(stack_a, stack_b, "rrr");
		i++;
	}
	pa(stack_a, stack_b);
	free_array(operations);
}

void	rot_top(t_node **stack_a)
{
	t_node	*pos;
	int		count;

	pos = *stack_a;
	count = 0;
	while (pos->next != NULL && pos->value != 0)
	{
		count++;
		pos = pos->next;
	}
	if (count > count_nodes(*stack_a) / 2)
	{
		while ((*stack_a)->value != 0)
			rotate_stack(stack_a, NULL, "rra");
	}
	else
	{
		while ((*stack_a)->value != 0)
			rotate_stack(stack_a, NULL, "ra");
	}
}

void	turk_sort(t_node *stack_a)
{
	t_node	*b;
	t_cost	cost;
	t_node	*ta_node;
	t_node	*pos_b;

	b = NULL;
	set_up_sort(&stack_a, &b);
	while (b != NULL)
	{
		cost.total_cost = 2147483647;
		cost.pos = NULL;
		pos_b = b;
		while (pos_b != NULL)
		{
			ta_node = find_target_node(stack_a, pos_b->value);
			if (cost.total_cost > costs(stack_a, b, ta_node, pos_b))
			{
				cost.total_cost = costs(stack_a, b, ta_node, pos_b);
				cost.pos = pos_b;
			}
			pos_b = pos_b->next;
		}
		ta_node = find_target_node(stack_a, cost.pos->value);
		exec_operations(&stack_a, &b, find_op(stack_a, b, cost.pos, ta_node));
	}
	rot_top(&stack_a);
}
