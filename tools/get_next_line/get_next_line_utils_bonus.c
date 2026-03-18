/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:13:07 by nschutz           #+#    #+#             */
/*   Updated: 2026/03/16 16:09:51 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	gft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*gft_calloc(int size, int count)
{
	int		i;
	char	*out;

	out = malloc(size * count);
	if (out == NULL)
		return (NULL);
	i = 0;
	while (i < size * count)
	{
		out[i] = 0;
		i ++;
	}
	return (out);
}

char	*gft_strchr(char *s, int c)
{
	size_t			j;
	unsigned char	i;

	j = 0;
	i = (unsigned char)c;
	if (!s)
		return (0);
	while (j < gft_strlen(s))
	{
		if (s[j] == i)
			return (&s[j]);
		j++;
	}
	return (0);
}

char	*gft_strdup(char *s)
{
	char	*ptr;
	size_t	i;

	ptr = (char *)malloc(gft_strlen(s) + 1);
	if (ptr == NULL)
		return (0);
	i = 0;
	while (i < gft_strlen(s))
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*gft_strjoin(char *s1, char const *s2)
{
	int		i;
	int		j;
	char	*c;

	i = 0;
	j = 0;
	if (!s1)
		return (gft_strdup((char *)s2));
	c = (char *)malloc(gft_strlen(s1) + gft_strlen(s2) + 1);
	if (s2 && c)
	{
		while (s1[i])
		{
			c[i] = s1[i];
			i++;
		}
		while (s2[j])
			c[i++] = s2[j++];
		c[i] = '\0';
		return (c);
	}
	return (0);
}
