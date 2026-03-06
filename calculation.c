/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 12:41:01 by nschutz           #+#    #+#             */
/*   Updated: 2026/03/06 12:44:29 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int calculate_cost(t_node *stack_a, t_node *stack_b, t_node *target_node, t_node *pos_b)
{
    int cost_a;
    int cost_b;

    cost_a = calculate_cost_stacks(stack_a, target_node);
    cost_b = calculate_cost_stacks(stack_b, pos_b);
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
    if (cost > count_nodes(stack) / 2)
        cost = count_nodes(stack) - cost_; //adjust for reverse rotation
    return (cost);
}