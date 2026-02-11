/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raddix_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 11:43:46 by nschutz           #+#    #+#             */
/*   Updated: 2023/07/11 12:41:47 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_int(t_node *stack_a)
{
	t_node	*pos;
	int		count;
	int		max_shift;

	pos = stack_a;
	count = -2147483647;
	max_shift = 0;
	while (pos != NULL)
	{
		if (pos->value > count)
			count = pos->value;
		pos = pos->next;
	}
	while (count >> max_shift != 0)
		max_shift++;
	return (max_shift);
}

static int	count_nodes(t_node *stack_a)
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

static void	push_rotate(t_node **stack_a, t_node **stack_b, int pos, int nodes)
{
	while (nodes > 0)
	{
		if ((((*stack_a)->value >> pos) & 1) == 0)
			pb(stack_a, stack_b);
		else
			rotate_stack(stack_a, stack_b, "ra");
		nodes--;
	}
}

void	radix_sort(t_node *stack_a)
{
	t_node	*stack_b;
	int		pos_bit_shift;
	int		max_bit_shift;
	int		nodes;

	stack_b = NULL;
	pos_bit_shift = 0;
	max_bit_shift = max_int(stack_a);
	nodes = count_nodes(stack_a);
	while (pos_bit_shift < max_bit_shift)
	{
		push_rotate(&stack_a, &stack_b, pos_bit_shift, nodes);
		pos_bit_shift++;
		while (stack_b != NULL)
			pa(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
}
