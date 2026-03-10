/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 12:41:01 by nschutz           #+#    #+#             */
/*   Updated: 2026/03/10 17:32:58 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	costs(t_node *stack_a, t_node *stack_b, t_node *ta_node, t_node *pos_b)
{
	int	cost_a;
	int	cost_b;

	cost_a = calculate_cost_stacks(stack_a, ta_node);
	cost_b = calculate_cost_stacks(stack_b, pos_b);
	if (rr_posibility(stack_a, stack_b, cost_a, cost_b) == 1)
		return (cost_a + cost_b - rr_cost(cost_a, cost_b, 1));
	else if (rr_posibility(stack_a, stack_b, cost_a, cost_b) == 2)
		return (cost_a + cost_b - rr_cost(cost_a, cost_b, 2));
	return (cost_a + cost_b);
}

int	calculate_cost_stacks(t_node *stack, t_node *target)
{
	int		cost;
	t_node	*tmp;

	cost = 0;
	tmp = stack;
	while (tmp != target)
	{
		cost++;
		tmp = tmp->next;
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
