/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:31:59 by nschutz           #+#    #+#             */
/*   Updated: 2023/07/06 11:31:59 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*sa(t_node *stack_a)
{
	int	tmp;

	if (stack_a == NULL || stack_a->next == NULL)
		return (stack_a);
	tmp = stack_a->value;
	stack_a->value = stack_a->next->value;
	stack_a->next->value = tmp;
	ft_printf("sa\n");
	return (stack_a);
}

t_node	*sb(t_node *stack_b)
{
	int	tmp;

	if (stack_b == NULL || stack_b->next == NULL)
		return (stack_b);
	tmp = stack_b->value;
	stack_b->value = stack_b->next->value;
	stack_b->next->value = tmp;
	ft_printf("sb\n");
	return (stack_b);
}

void	ss(t_node *stack_a, t_node *stack_b)
{
	int	tmp;

	if ((stack_a) == NULL || (stack_a)->next == NULL)
		return ;
	if ((stack_b) == NULL || (stack_b)->next == NULL)
		return ;
	tmp = stack_a->value;
	stack_a->value = stack_a->next->value;
	stack_a->next->value = tmp;
	tmp = stack_b->value;
	stack_b->value = stack_b->next->value;
	stack_b->next->value = tmp;
	ft_printf("ss\n");
}
