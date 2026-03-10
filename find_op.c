/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:44:16 by nschutz           #+#    #+#             */
/*   Updated: 2026/03/10 16:24:27 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_op	set_up_op(t_op operations)
{
	operations.ra = 0;
	operations.rb = 0;
	operations.rr = 0;
	operations.rra = 0;
	operations.rrb = 0;
	operations.rrr = 0;
	return (operations);
}

t_op	check_b_rot(t_node *stack_a, t_node *stack_b, int cost_a, int cost_b)
{
	t_op	operations;
	int		dif;

	operations = set_up_op(operations);
	if (cost_a == 0 || cost_b == 0)
		return (operations);
	if (rr_posibility(stack_a, stack_b, cost_a, cost_b) == 1)
	{
		dif = rr_cost(cost_a, cost_b, 1);
		while (dif-- > 0)
			operations.rr++;
	}
	else if (rr_posibility(stack_a, stack_b, cost_a, cost_b) == 2)
	{
		dif = rr_cost(cost_a, cost_b, 2);
		while (dif-- > 0)
			operations.rrr++;
	}
	return (operations);
}

t_op	rot_wo_rr(t_node *stack_a, t_node *stack_b, int cost_a, int cost_b)
{
	t_op	operations;
	int		tmp;

	tmp = cost_a;
	while (cost_a-- > 0)
	{
		if (tmp > count_nodes(stack_a) / 2)
			operations.rra++;
		else
			operations.ra++;
	}
	tmp = cost_b;
	while (cost_b-- > 0)
	{
		if (tmp > count_nodes(stack_b) / 2)
			operations.rrb++;
		else
			operations.rb++;
	}
	return (operations);
}

t_op	add_ra_rb_rrra_rrrb(t_op operations, int cost_a, int cost_b, int r)
{
	if (r == 1)
	{
		while (cost_a-- > 0)
			operations.ra++;
		while (cost_b-- > 0)
			operations.rb++;
	}
	else
	{
		while (cost_a-- > 0)
			operations.rra++;
		while (cost_b-- > 0)
			operations.rrb++;
	}
	return (operations);
}

t_op	find_op(t_node *a, t_node *b, t_node *pos_b, t_node *ta_node)
{
	t_op	operations;
	int		cost_a;
	int		cost_b;

	cost_a = calculate_cost_stacks(a, ta_node);
	cost_b = calculate_cost_stacks(b, pos_b);
	operations = check_b_rot(a, b, cost_a, cost_b);
	if (operations.rr > 0 || operations.rrr > 0)
	{
		if (rr_posibility(a, b, cost_a, cost_b) == 1)
			operations = add_ra_rb_rrra_rrrb(operations, cost_a, cost_b, 1);
		else if (rr_posibility(a, b, cost_a, cost_b) == 2)
			operations = add_ra_rb_rrra_rrrb(operations, cost_a, cost_b, 0);
	}
	else
		operations = rot_wo_rr(a, b, cost_a, cost_b);
	return (operations);
}
