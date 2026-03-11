/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:44:16 by nschutz           #+#    #+#             */
/*   Updated: 2026/03/11 12:48:38 by nschutz          ###   ########.fr       */
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
	int		tmp_a;
	int		tmp_b;

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
		tmp_a = count_nodes(stack_a) - cost_a;
		tmp_b = count_nodes(stack_b) - cost_b;
		dif = rr_cost(tmp_a, tmp_b, 2);
		while (dif-- > 0)
			operations.rrr++;
	}
	return (operations);
}

t_op	add_ops(t_op operations, int cost_a, int cost_b, int r)
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

t_op	rot_wo_double(t_node *stack_a, t_node *stack_b, int cost_a, int cost_b)
{
	t_op	operations;

	if (cost_a > count_nodes(stack_a) / 2)
	{
		cost_a = count_nodes(stack_a) - cost_a;
		operations = add_ops(operations, cost_a, 0, 0);
	}
	else
		operations = add_ops(operations, cost_a, 0, 1);
	if (cost_b > count_nodes(stack_b) / 2)
	{
		cost_b = count_nodes(stack_b) - cost_b;
		operations = add_ops(operations, 0, cost_b, 0);
	}
	else
		operations = add_ops(operations, 0, cost_b, 1);
	return (operations);
}

t_op	find_op(t_node *a, t_node *b, t_node *pos_b, t_node *ta_node)
{
	t_op	ops;
	int		cost_a;
	int		cost_b;

	cost_a = cc_1w(a, ta_node);
	cost_b = cc_1w(b, pos_b);
	ops = check_b_rot(a, b, cost_a, cost_b);
	if (ops.rr > 0 || ops.rrr > 0)
	{
		if (rr_posibility(a, b, cost_a, cost_b) == 1)
			ops = add_ops(ops, cost_a, cost_b, 1);
		else if (rr_posibility(a, b, cost_a, cost_b) == 2)
			ops = add_ops(ops, cc_2w(a, ta_node), cc_2w(b, pos_b), 0);
	}
	else
		ops = rot_wo_double(a, b, cost_a, cost_b);
	return (ops);
}
