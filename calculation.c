/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 12:41:01 by nschutz           #+#    #+#             */
/*   Updated: 2026/03/11 12:35:19 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	costs(t_node *stack_a, t_node *stack_b, t_node *ta_node, t_node *pos_b)
{
	int	cost_a;
	int	cost_b;
	int	tmp_a;
	int	tmp_b;

	cost_a = cc_1w(stack_a, ta_node);
	cost_b = cc_1w(stack_b, pos_b);
	if (rr_posibility(stack_a, stack_b, cost_a, cost_b) == 1)
		return (cost_a + cost_b - rr_cost(cost_a, cost_b, 1));
	else if (rr_posibility(stack_a, stack_b, cost_a, cost_b) == 2)
	{
		tmp_a = cc_2w(stack_a, ta_node);
		tmp_b = cc_2w(stack_b, pos_b);
		return (tmp_a + tmp_b - rr_cost(tmp_a, tmp_b, 2));
	}
	return (cc_2w(stack_a, ta_node) + cc_2w(stack_b, pos_b));
}
//cost calculation 2 way

int	cc_2w(t_node *stack, t_node *target)
{
	int	cost;

	cost = cc_1w(stack, target);
	if (cost > count_nodes(stack) / 2)
		cost = cost - count_nodes(stack);
	return (cost);
}
//cost calculation 1 way

int	cc_1w(t_node *stack, t_node *target)
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
