/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:44:16 by nschutz           #+#    #+#             */
/*   Updated: 2026/03/09 11:31:19 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char **check_both_rotate(t_node *stack_a, t_node *stack_b, int cost_a, int cost_b)
{
    char    **operations;
    int     up_down_a;
    int     up_down_b;
    int     dif;

    up_down_a = (cost_a > count_nodes(stack_a) / 2) ? 1 : 0;
    up_down_b = (cost_b > count_nodes(stack_b) / 2) ? 1 : 0;
    dif = (cost_a > cost_b) ? cost_a - cost_b : cost_b - cost_a;
    if (up_down_a == up_down_b)
    {
        operations = ft_calloc((cost_a + cost_b + 1), sizeof(char *));
        if (up_down_a == 0)
        {
            for (int i = 0; i < dif; i++)
                operations[i] = ft_strdup("rr");
        } else
        {
            for (int i = 0; i < dif; i++)
                operations[i] = ft_strdup("rrr");
        }
        return (operations);
    } else
        return (NULL);
}

char **write_rest_rotate(t_node *stack_a, t_node *stack_b, int rotate, char **operations)
{
    int to_do;
    //UNBEDINGT noch Schreiben, dass sowhl rotate b als auch rotate a noch gemacht wird 
    //UND die Operations an der Richtigen Stelle einfuegen
    to_do = stack_a->value + stack_b->value;
    ft_printf("to do: %d\n", to_do);
    if (rotate > 0)
    {
        for (int i = 0; i < rotate; i++)
            operations[i] = ft_strdup("ra");
    } else
    {
        rotate = rotate * -1;
        for (int i = 0; i < rotate; i++)
            operations[i] = ft_strdup("rra");
    }
    return (operations);
}

char **write_op_wo_rr(t_node *stack_a, t_node *stack_b, int cost_a, int cost_b)
{
    char **operations;

    operations = ft_calloc(cost_a + cost_b + 1, sizeof(char *));    
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
    return (operations);
}

char **find_op(t_node *a, t_node *b, t_node *pos_b, t_node *t_node)
{
    char    **operations;
    int     cost_a;
    int     cost_b;
    int     i;
    
    cost_a = calculate_cost_stacks(a, t_node);
    cost_b = calculate_cost_stacks(b, pos_b);
    operations = check_both_rotate(a, b, cost_a, cost_b);
    if (operations != NULL)
    {
        if (cost_a > cost_b)
        i = cost_a - cost_b;
        else
        i = cost_b - cost_a;
        if (i == 0)
            return (operations);
        if (cost_a > count_nodes(a) / 2)
            i = i * -1;
        operations = write_rest_rotate(a, b, i, operations);
    }    
    else
        operations = write_op_wo_rr(a, b, cost_a, cost_b);
    return (operations);
}