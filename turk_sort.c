/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 12:08:58 by nschutz           #+#    #+#             */
/*   Updated: 2026/03/06 15:35:43 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_nodes(t_node *stack_a)
{
	t_node	*pos;
	int		count;

	pos = stack_a;
	count = 0;
	while (pos != NULL)
	{
		count++;
		pos = pos->next;
	}
	return (count);
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
    int i;

    i = 0;
    while (operations[i] != NULL)
    {
        if (ft_strncmp(operations[i], "ra", 2) == 0)
            rotate_stack(&stack_a, NULL, "ra");
        else if (ft_strncmp(operations[i], "rb", 2) == 0)
            rotate_stack(NULL, &stack_b, "rb");
        else if (ft_strncmp(operations[i], "rr", 2) == 0)
            rotate_stack(&stack_a, &stack_b, "rr");
        else if (ft_strncmp(operations[i], "rra", 3) == 0)
            rotate_stack(&stack_a, NULL, "rra");
        else if (ft_strncmp(operations[i], "rrb", 3) == 0)
            rotate_stack(NULL, &stack_b, "rrb");
        else if (ft_strncmp(operations[i], "rrr", 3) == 0)
            rotate_stack(&stack_a, &stack_b, "rrr");
        i++;
    }
    pa(&stack_a, &stack_b);
    free_array(operations);
}

void turk_sort (t_node **stack_a)
{
    t_node	*stack_b;
    t_cost  cost;
    t_node  *target_node;
    t_node  *pos_b;
	int	    nodes;

	stack_b = NULL;
    cost.total_cost = 2147483647;
    cost.pos = 0;
	nodes = count_nodes(*stack_a);
    for (int i = 0; i < (nodes-3); i++)
        pb(stack_a, &stack_b);
    three_arg(*stack_a);
    while (stack_b != NULL)
    {
        while (pos_b != NULL)
        {
            target_node = find_target_node(*stack_a, stack_b->value);
            if (cost.total_cost > calculate_cost(*stack_a, stack_b, target_node, pos_b))
            {
                cost.total_cost = calculate_cost(*stack_a, stack_b, target_node, pos_b);
                cost.pos = pos_b;
            }
            pos_b = pos_b->next;
        }
        execute_operations(*stack_a, stack_b, find_operations(*stack_a, stack_b, cost.pos, target_node));
    }
}
