/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncheniou <ncheniou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:36:21 by ncheniou          #+#    #+#             */
/*   Updated: 2025/02/05 20:16:24 by ncheniou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check(char s, va_list args, int *len, int *i)
{
	if (s == 's')
		ft_putstr(va_arg(args, char *), len);
	else if (s == 'c')
		(*len) += ft_char(va_arg(args, int));
	else if (s == 'd')
		ft_putnbr(va_arg(args, int), len);
	else if (s == 'p')
		ft_putptr(va_arg(args, unsigned long), "0123456789abcdef", len);
	else if (s == 'i')
		ft_putnbr(va_arg(args, int), len);
	else if (s == 'u')
		ft_putnbr_base(va_arg(args, int), "0123456789", len);
	else if (s == 'x')
		ft_putnbr_base(va_arg(args, int), "0123456789abcdef", len);
	else if (s == 'X')
		ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF", len);
	else if (s == '%')
		(*len) += ft_char('%');
	else
		(*i)--;
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		length;
	va_list	args;

	va_start(args, str);
	i = 0;
	length = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i ++;
			ft_check(str[i], args, &length, &i);
			i ++;
		}
		else
		{
			write (1, &str[i], 1);
			i ++;
			length ++;
		}
	}
	va_end(args);
	return (length);
}
// int main()
// {
// 	int n = INT_MAX;
// 	//int nb = INT_MIN;

// 	void *ptr;
// 	ptr = &n;
// 	printf("%lu\n", sizeof(unsigned long));
// 	int i = ft_printf(" %p\n", ptr);
// 	printf("%d\n", i);
// 	int j = printf(" %p\n", ptr);
// 	printf("%d\n", j);  
// }
