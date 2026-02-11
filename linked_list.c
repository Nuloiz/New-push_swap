/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:34:09 by nschutz           #+#    #+#             */
/*   Updated: 2023/07/31 11:30:29 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*new_node(int current)
{
	t_node	*new;

	new = ft_calloc(1, sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = current;
	new->next = NULL;
	return (new);
}

/*static t_node	*add_node(t_node *head, int value)
{
	t_node	*temp;
	t_node	*p;

	temp = new_node(value);
	if (!temp)
		return (free_stack(head), NULL);
	if (head == NULL)
		head = temp;
	else
	{
		p = head;
		while (p->next != NULL)
			p = p->next;
		p->next = temp;
	}
	return (head);
}*/

t_node	**linked_list_start(int argc, int *list, t_node **stack_a)
{
	int		i;
	t_node	*new;

	i = 0;
	while (i < argc)
	{
		new = new_node(list[i]);
		if (!new)
			return (free_stack(stack_a), NULL);
		ft_lstadd_back(stack_a, new);
		i++;
	}
	return (stack_a);
}
