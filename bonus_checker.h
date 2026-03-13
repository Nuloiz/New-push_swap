/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 16:09:54 by nschutz           #+#    #+#             */
/*   Updated: 2026/03/13 16:15:17 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_CHECKER_H
# define BONUS_CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "./tools/libft/libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}				t_node;

int		input_checker(int argc, char **argv);

#endif