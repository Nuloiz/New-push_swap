/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:17:54 by nschutz           #+#    #+#             */
/*   Updated: 2023/07/12 16:17:54 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*move_back(int argc, int *new)
{
	int	*list;
	int	i;

	list = malloc(argc * sizeof(int));
	i = 0;
	while (i < argc)
	{
		list[new[i]] = i;
		i++;
	}
	free (new);
	return (list);
}

int	*next_new_numbers(int argc, char **list, int *new, int index)
{
	int		loop;
	int		i;
	int		min;
	int		pos;

	loop = -1;
	while (++loop < argc)
	{
		i = 0;
		min = 2147483647;
		while (list[i])
		{
			if (ft_strncmp(list[i], "!", 1) && ft_atoi(list[i]) <= min)
			{
				min = (int)ft_atoi(list[i]);
				pos = i;
			}
			i++;
		}
		if (index == 2)
			free(list[pos]);
		list[pos] = ft_strdup("!");
		new[loop] = pos;
	}
	return (move_back(argc, new));
}

int	*new_numbers(int argc, char **list, int index)
{
	int		*new;

	new = malloc(argc * sizeof(int));
	if (!new)
		return (NULL);
	new = next_new_numbers(argc, list, new, index);
	return (new);
}
