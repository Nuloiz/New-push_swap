/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_get_lines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:47:38 by nschutz           #+#    #+#             */
/*   Updated: 2026/03/16 14:57:46 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_checker.h"

char	**get_lines(void)
{
	char	**lines;
	char	*line;
	int		i;

	lines = malloc(sizeof(char *) * 1000);
	if (!lines)
		return (NULL);
	i = 0;
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		lines[i] = line;
		i++;
	}
	lines[i] = NULL;
	return (lines);
}
