/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:40:42 by nschutz           #+#    #+#             */
/*   Updated: 2023/08/02 15:40:42 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_node **lst, t_node *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*last;

	if (!lst || !*lst)
	{
		*lst = new;
		(*lst)->next = NULL;
	}
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}

t_node	*ft_lstlast(t_node *lst)
{
	t_node	*last;

	last = lst;
	while (last->next != NULL)
		last = last->next;
	return (last);
}
