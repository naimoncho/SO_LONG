/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncheniou <ncheniou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:36:04 by ncheniou          #+#    #+#             */
/*   Updated: 2025/02/04 11:38:41 by ncheniou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char(char c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_putstr(char *s, int *len)
{
	size_t	i;

	i = 0;
	if (!s)
	{
		write (1, "(null)", 6);
		(*len) += 6;
		return ;
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i ++;
		(*len)++;
	}
}
