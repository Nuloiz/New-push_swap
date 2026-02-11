/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:40:12 by nschutz           #+#    #+#             */
/*   Updated: 2023/05/23 09:54:17 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*c;

	i = 0;
	j = 0;
	c = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	if (s1 && s2 && c)
	{
		while (s1[i])
		{
			c[i] = s1[i];
			i++;
		}
		while (s2[j])
		{
			c[i] = s2[j];
			i++;
			j++;
		}
		c[i] = '\0';
		return (c);
	}
	return (0);
}
