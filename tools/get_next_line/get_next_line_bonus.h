/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:15:04 by nschutz           #+#    #+#             */
/*   Updated: 2026/03/16 15:58:58 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000
# endif

char	*get_next_line(int fd);
size_t	gft_strlen(const char *s);
char	*gft_strchr(char *s, int c);
char	*gft_calloc(int size, int count);
char	*gft_strjoin(char *s1, char const *s2);
char	*gft_strdup(char *s);

#endif