/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 16:09:54 by nschutz           #+#    #+#             */
/*   Updated: 2026/03/16 15:51:17 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_CHECKER_H
# define BONUS_CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "./tools/libft/libft.h"
# include "./tools/get_next_line/get_next_line_bonus.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}				t_node;

typedef struct s_op
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}				t_op;

int		input_checker(int argc, char **argv);
int		no_int_twice(char **list);
int		*new_numbers(int num, char **list, int index);
t_node	**linked_list_start(int argc, int *list, t_node **stack_a);
t_node	*sa(t_node *stack_a);
t_node	*sb(t_node *stack_b);
void	ss(t_node *stack_a, t_node *stack_b);
void	rotate_stack(t_node **stack_a, t_node **stack_b, char *operation);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
char	**get_lines(void);
void	free_stack(t_node **stack);
void	free_array(char	**array);
void	free_array_list(int argc, char	**array);

#endif