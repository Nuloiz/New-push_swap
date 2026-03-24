/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_op_swap_stacks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:32:09 by nschutz           #+#    #+#             */
/*   Updated: 2026/03/24 12:57:21 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node	**stack_a, t_node **stack_b)
{
	t_node	*first_a;

	if ((*stack_b) == NULL)
		return ;
	first_a = *stack_b;
	*stack_b = (*stack_b)->next;
	first_a->next = *stack_a;
	*stack_a = first_a;
}

void	pb(t_node	**stack_a, t_node **stack_b)
{
	t_node	*first_a;

	if ((*stack_a) == NULL)
		return ;
	first_a = *stack_a;
	*stack_a = (*stack_a)->next;
	first_a->next = *stack_b;
	*stack_b = first_a;
}
