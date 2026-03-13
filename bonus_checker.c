/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 16:08:46 by nschutz           #+#    #+#             */
/*   Updated: 2026/03/13 16:15:37 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_checker.h"

int check_stacks(t_node *stack_a, t_node *stack_b)
{
    if (stack_b != NULL)
        return (0);
    while (stack_a != NULL)
    {
        if (stack_a->next != NULL && stack_a->value > stack_a->next->value)
            return (0);
        stack_a = stack_a->next;
    }
    return (1);
}

int	main(int argc, char **argv)
{
    int		index;
    t_node	*stack_a;
    t_node	*stack_b;

	argc = argc -1;
	argv = argv + 1;
	index = input_checker(argc, argv);
	if (argc == 0 || index == 0)
		return (ft_putendl_fd("Error", 2), 0);
    //Get Operations
    //Save operations in a list
    //Execute operations on stacks
    if (check_stacks(stack_a, stack_b))
        ft_putendl_fd("OK", 1);
    else
        ft_putendl_fd("KO", 1);
    return (0);
}
