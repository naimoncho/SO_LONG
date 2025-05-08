/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncheniou <ncheniou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:36:14 by ncheniou          #+#    #+#             */
/*   Updated: 2025/02/05 20:04:18 by ncheniou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <strings.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

size_t	ft_strlen(const char *str);
void	ft_putnbr(int n, int *len);
void	ft_putnbr_base(unsigned long num, char *base, int *len);
void	ft_putptr(unsigned long n, char *base, int *len);
int		ft_char(char c);
void	ft_putstr(char *s, int *len);
void	ft_check(char s, va_list args, int *len, int *i);
int		ft_printf(char const *str, ...);

#endif 