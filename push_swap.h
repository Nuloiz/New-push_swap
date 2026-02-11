/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:35:42 by nschutz           #+#    #+#             */
/*   Updated: 2023/07/03 11:35:42 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "./tools/libft/libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}				t_node;

int		main(int argc, char	**argv);
int		input_checker(int argc, char **argv);
int		no_int_twice(char **list);
t_node	**linked_list_start(int argc, int *list, t_node **stack_a);
t_node	*sa(t_node *stack_a);
t_node	*sb(t_node *stack_b);
void	ss(t_node *stack_a, t_node *stack_b);
void	rotate_stack(t_node **stack_a, t_node **stack_b, char *operation);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	radix_sort(t_node *stack_a);
int		already_sorted(t_node *stack);
void	three_arg(t_node *stack_a);
void	five_arg(int num_of_arg, t_node *stack_a);
int		*new_numbers(int argc, char **list, int index);
void	free_stack(t_node **stack);
void	free_array(char	**array);
void	free_array_list(int argc, char **array);
char	**new_array(char **argv);
void	ft_lstadd_front(t_node **lst, t_node *new);
void	ft_lstadd_back(t_node **lst, t_node *new);
t_node	*ft_lstlast(t_node *lst);
void	print_list(t_node *stack);

#endif