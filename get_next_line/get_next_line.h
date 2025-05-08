/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncheniou <ncheniou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 18:19:40 by ncheniou          #+#    #+#             */
/*   Updated: 2025/05/08 21:05:24 by ncheniou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <strings.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char			*get_next_line(int fd);
int				gnl_strlen(char *str);
char			*ft_strchr(const char *s, int c);
char			*gnl_substr(char *s, unsigned int start, size_t len);
char			*gnl_strjoin(char *s1, char *s2);

#endif