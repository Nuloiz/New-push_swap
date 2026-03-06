/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 12:08:58 by nschutz           #+#    #+#             */
/*   Updated: 2026/03/06 14:56:50 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void turk_sort (t_node **stack_a)
{
    t_node	*stack_b;
    t_cost  cost;
    t_node  *target_node;
    t_node  *pos_b;
	int	    nodes;

	stack_b = NULL;
    cost->total_cost = 2147483647;
    cost->pos = 0;
	nodes = count_nodes(stack_a);
    for (int i = 0; i < (nodes-3); i++)
        pb(stack_a, &stack_b);
    three_arg(*stack_a);
    while (stack_b != NULL)
    {
        while (pos_b != NULL)
        {
            target_node = find_target_node(*stack_a, stack_b->value);
            if (cost->total_cost > calculate_cost(*stack_a, stack_b, target_node, pos_b))
            {
                cost->total_cost = calculate_cost(*stack_a, stack_b, target_node, pos_b);
                cost->pos = pos_b;
            }
            pos_b = pos_b->next;
        }
        execute_operations(stack_a, stack_b, find_operations(*stack_a, stack_b, cost->pos, target_node));
    }
}

t_node *find_target_node(t_node *stack_a, int value)
{
    t_node *pos = stack_a;
    int target_value = 2147483647;
    while (pos != NULL)
    {
        if (pos->value > value && pos->value < target_value)
            target_value = pos->value;
        pos = pos->next;
    }
    return (pos);
}


void execute_operations(t_node *stack_a, t_node *stack_b, char **operations)
{
    int i

    i = 0;
    while (operations[i] != NULL)
    {
        if (ft_strcmp(operations[i], "ra") == 0)
            rotate_stack(&stack_a, NULL, "ra");
        else if (ft_strcmp(operations[i], "rb") == 0)
            rotate_stack(NULL, &stack_b, "rb");
        else if (ft_strcmp(operations[i], "rr") == 0)
            rotate_stack(&stack_a, &stack_b, "rr");
        else if (ft_strcmp(operations[i], "rra") == 0)
            rotate_stack(&stack_a, NULL, "rra");
        else if (ft_strcmp(operations[i], "rrb") == 0)
            rotate_stack(NULL, &stack_b, "rrb");
        else if (ft_strcmp(operations[i], "rrr") == 0)
            rotate_stack(&stack_a, &stack_b, "rrr");
        i++;
    }
    pa(&stack_a, &stack_b);
    free_array(operations);
}
