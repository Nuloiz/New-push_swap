/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:14:16 by nschutz           #+#    #+#             */
/*   Updated: 2026/03/09 17:18:54 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*tn_smallest(t_node *stack_a)
{
	t_node	*tmp;
	t_node	*pos;
	int		target_value;

	tmp = NULL;
	pos = stack_a;
	target_value = 2147483647;
	while (pos != NULL)
	{
		if (pos->value < target_value)
		{
			target_value = pos->value;
			tmp = pos;
		}
		pos = pos->next;
	}
	return (tmp);
}

t_node	*find_target_node(t_node *stack_a, int value)
{
	t_node	*tmp;
	t_node	*pos;
	int		target_value;

	pos = stack_a;
	tmp = NULL;
	target_value = 2147483647;
	while (pos != NULL)
	{
		if (pos->value > value && pos->value < target_value)
		{
			target_value = pos->value;
			tmp = pos;
		}
		pos = pos->next;
	}
	if (tmp == NULL)
		tmp = tn_smallest(stack_a);
	return (tmp);
}
