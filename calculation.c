/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 12:41:01 by nschutz           #+#    #+#             */
/*   Updated: 2026/03/06 13:02:07 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int calculate_cost(t_node *stack_a, t_node *stack_b, t_node *target_node, t_node *pos_b)
{
    int cost_a;
    int cost_b;

    cost_a = calculate_cost_stacks(stack_a, target_node);
    if (cost_a > count_nodes(stack_a) / 2)
        cost_a = count_nodes(stack_a) - cost_a;
    cost_b = calculate_cost_stacks(stack_b, pos_b);
    if (cost_b > count_nodes(stack_b) / 2)
        cost_b = count_nodes(stack_b) - cost_b;
    //check for rr and rrr possibilities and adjust costs accordingly
    return (cost_a + cost_b);
}

int calculate_cost_stacks(t_node *stack, t_node *target)
{
    int cost;

    cost = 0;
    while (stack != target)
    {
        cost++;
        stack = stack->next;
    }
    return (cost);
}