/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge_and_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:38:09 by nschutz           #+#    #+#             */
/*   Updated: 2023/07/28 12:37:33 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	already_sorted(t_node	*list)
{
	t_node	*stack;

	stack = list;
	if (stack == NULL)
		return (1);
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
		{
			stack = list;
			return (0);
		}
		stack = stack->next;
	}
	stack = list;
	return (1);
}

static int	sorted(t_node *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	three_arg(t_node *stack_a)
{
	if (stack_a->next->next == NULL)
		stack_a = sa(stack_a);
	else if (stack_a->value < stack_a->next->value && \
			stack_a->value > stack_a->next->next->value)
		rotate_stack(&stack_a, NULL, "rra");
	else if (stack_a->value > stack_a->next->value && \
			stack_a->next->value < stack_a->next->next->value && \
			stack_a->value > stack_a->next->next->value)
		rotate_stack(&stack_a, NULL, "ra");
	else
	{
		stack_a = sa(stack_a);
		if (stack_a->value < stack_a->next->value && \
			stack_a->value > stack_a->next->next->value)
			rotate_stack(&stack_a, NULL, "rra");
		else if (stack_a->value > stack_a->next->value && \
			stack_a->value > stack_a->next->next->value)
			rotate_stack(&stack_a, NULL, "ra");
	}
	free_stack(&stack_a);
}

t_node	*three_arg_for_five(t_node *stack_a)
{
	if (sorted(stack_a))
		return (stack_a);
	if (stack_a->next->next == NULL)
		stack_a = sa(stack_a);
	else if (stack_a->value < stack_a->next->value && \
			stack_a->value > stack_a->next->next->value)
		rotate_stack(&stack_a, NULL, "rra");
	else if (stack_a->value > stack_a->next->value && \
			stack_a->next->value < stack_a->next->next->value && \
			stack_a->value > stack_a->next->next->value)
		rotate_stack(&stack_a, NULL, "ra");
	else
	{
		stack_a = sa(stack_a);
		if (stack_a->value < stack_a->next->value && \
			stack_a->value > stack_a->next->next->value)
			rotate_stack(&stack_a, NULL, "rra");
		else if (stack_a->value > stack_a->next->value && \
			stack_a->value > stack_a->next->next->value)
			rotate_stack(&stack_a, NULL, "ra");
	}
	return (stack_a);
}

void	five_arg(int num_of_arg, t_node *stack_a)
{
	t_node	*stack_b;
	int		i;

	i = -1;
	stack_b = NULL;
	while (++i < num_of_arg)
	{
		if (stack_a->value == 0 || stack_a->value == num_of_arg - 1)
			pb(&stack_a, &stack_b);
		rotate_stack(&stack_a, &stack_b, "rra");
	}
	stack_a = three_arg_for_five(stack_a);
	if (stack_b->value < stack_b->next->value)
	{
		pa(&stack_a, &stack_b);
		pa(&stack_a, &stack_b);
		rotate_stack(&stack_a, &stack_b, "ra");
	}
	else
	{
		pa(&stack_a, &stack_b);
		rotate_stack(&stack_a, &stack_b, "ra");
		pa(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
}
