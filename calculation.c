/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 12:41:01 by nschutz           #+#    #+#             */
/*   Updated: 2026/03/09 14:21:02 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost(t_node *stack_a, t_node *stack_b, t_node *t_node, t_node *pos_b)
{
	int	cost_a;
	int	cost_b;

	cost_a = calculate_cost_stacks(stack_a, t_node);
	if (cost_a > count_nodes(stack_a) / 2)
		cost_a = count_nodes(stack_a) - cost_a;
	cost_b = calculate_cost_stacks(stack_b, pos_b);
	if (cost_b > count_nodes(stack_b) / 2)
		cost_b = count_nodes(stack_b) - cost_b;
	if (rr_posibility(stack_a, stack_b, cost_a, cost_b) == 1)
		return (cost_a + cost_b - rr_cost(cost_a, cost_b, 1));
	else if (rr_posibility(stack_a, stack_b, cost_a, cost_b) == 2)
		return (cost_a + cost_b - rr_cost(cost_a, cost_b, 2));
	return (cost_a + cost_b);
}

int	calculate_cost_stacks(t_node *stack, t_node *target)
{
	int	cost;

	cost = 0;
	while (stack != target)
	{
		cost++;
		stack = stack->next;
	}
	return (cost);
}

int	rr_posibility(t_node *stack_a, t_node *stack_b, int cost_a, int cost_b)
{
	int	up_down_a;
	int	up_down_b;

	if (cost_a > count_nodes(stack_a) / 2)
		up_down_a = 1;
	else
		up_down_a = 0;
	if (cost_b > count_nodes(stack_b) / 2)
		up_down_b = 1;
	else
		up_down_b = 0;
	if (up_down_a == up_down_b)
	{
		if (up_down_a == 0)
			return (1);
		else
			return (2);
	}
	return (0);
}

int	rr_cost(int cost_a, int cost_b, int dir)
{
	int	cost;

	if (dir == 1)
	{
		if (cost_a > cost_b)
			cost = cost_b;
		else
			cost = cost_a;
	}
	else
	{
		if (cost_a > cost_b)
			cost = cost_a - (cost_a - cost_b);
		else
			cost = cost_b - (cost_b - cost_a);
	}
	return (cost);
}
