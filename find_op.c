/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:44:16 by nschutz           #+#    #+#             */
/*   Updated: 2026/03/09 15:07:24 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**check_b_rot(t_node *stack_a, t_node *stack_b, int cost_a, int cost_b)
{
	char	**operations;
	int		dif;

	if (rr_posibility(stack_a, stack_b, cost_a, cost_b) == 1)
	{
		dif = rr_cost(cost_a, cost_b, 1);
		operations = ft_calloc(dif + 1, sizeof(char *));
		while (dif-- > 0)
			operations[dif - 1] = ft_strdup("rr");
	}
	else if (rr_posibility(stack_a, stack_b, cost_a, cost_b) == 2)
	{
		dif = rr_cost(cost_a, cost_b, 2);
		operations = ft_calloc(dif + 1, sizeof(char *));
		while (dif-- > 0)
			operations[dif - 1] = ft_strdup("rrr");
	}
	return (NULL);
}

char	**rot_wo_rr(t_node *stack_a, t_node *stack_b, int cost_a, int cost_b)
{
	char	**operations;

	operations = ft_calloc(cost_a + cost_b + 1, sizeof(char *));
	while (cost_a-- > 0)
	{
		if (cost_a > count_nodes(stack_a) / 2)
			operations[i++] = ft_strdup("rra");
		else
			operations[i++] = ft_strdup("ra");
	}
	while (cost_b-- > 0)
	{
		if (cost_b > count_nodes(stack_b) / 2)
			operations[i++] = ft_strdup("rrb");
		else
			operations[i++] = ft_strdup("rb");
	}
	return (operations);
}

char	**add_ra_rb_rrra_rrrb(char **operations, int cost_a, int cost_b, int r)
{
	int		i;

	i = 0;
	while (operations[i] != NULL)
		i++;
	if (r == 1)
	{
		while (cost_a-- > 0)
			operations[i++] = ft_strdup("ra");
		while (cost_b-- > 0)
			operations[i++] = ft_strdup("rb");
	}
	else
	{
		while (cost_a-- > 0)
			operations[i++] = ft_strdup("rra");
		while (cost_b-- > 0)
			operations[i++] = ft_strdup("rrb");
	}
	return (operations);
}

char	**find_op(t_node *a, t_node *b, t_node *pos_b, t_node *ta_node)
{
	char	**operations;
	int		cost_a;
	int		cost_b;
	int		i;

	cost_a = calculate_cost_stacks(a, ta_node);
	cost_b = calculate_cost_stacks(b, pos_b);
	operations = check_b_rot(a, b, cost_a, cost_b);
	i = 0;
	if (operations != NULL)
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
