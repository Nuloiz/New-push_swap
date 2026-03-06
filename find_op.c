/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:44:16 by nschutz           #+#    #+#             */
/*   Updated: 2026/03/06 14:44:27 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char **find_operations(t_node *stack_a, t_node *stack_b, t_node *pos_b, t_node *target_node)
{
    char    **operations;
    int     cost_a;
    int     cost_b;
    int     up_down_a;
    int     up_down_b;
    
    cost_a = calculate_cost_stacks(stack_a, target_node);
    cost_b = calculate_cost_stacks(stack_b, pos_b);
    operations = ft_calloc(cost_a + cost_b + 1, sizeof(char *));
    up_down_a = (cost_a > count_nodes(stack_a) / 2) ? 1 : 0;
    up_down_b = (cost_b > count_nodes(stack_b) / 2) ? 1 : 0;
    if (up_down_a == up_down_b)
    {
    }
    if (cost_a > count_nodes(stack_a) / 2)
    {
        cost_a = count_nodes(stack_a) - cost_a;
        for (int i = 0; i < cost_a; i++)
            operations[i] = ft_strdup("rra");
    } else
    {
        for (int i = 0; i < cost_a; i++)
            operations[i] = ft_strdup("ra");
    }
    if (cost_b > count_nodes(stack_b) / 2)
    {
        cost_b = count_nodes(stack_b) - cost_b;
        for (int i = 0; i < cost_b; i++)
            operations[cost_a + i] = ft_strdup("rrb");
    } else
    {
        for (int i = 0; i < cost_b; i++)
            operations[cost_a + i] = ft_strdup("rb");
    }    
    //check for rr and rrr possibilities and adjust operations accordingly
    operations[cost_a + cost_b] = ft_strdup("pa");
    return (operations);
}