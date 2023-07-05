/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:49:31 by francevi          #+#    #+#             */
/*   Updated: 2023/06/24 08:53:45 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_placeholder(va_list args, const char *format, int *res, int *i)
{
	if (format[*i] == '%')
		ft_putchar(format[*i], res);
	else if (format[*i] == 'c')
		ft_putchar(va_arg(args, int), res);
	else if (format[*i] == 's')
		ft_putstr(va_arg(args, char *), res);
	else if (format[*i] == 'd' || format[*i] == 'i')
		ft_putnbr(va_arg(args, int), res);
	else if (format[*i] == 'u')
		ft_putunbr(va_arg(args, unsigned int), res);
	else if (format[*i] == 'x')
		ft_puthex(va_arg(args, unsigned int), res);
	else if (format[*i] == 'X')
		ft_putuphex(va_arg(args, unsigned int), res);
	else if (format[*i] == 'p')
		ft_putpointer(va_arg(args, void *), res);
	*i += 1;
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		res;
	int		len;

	va_start(args, format);
	i = 0;
	res = 0;
	len = ft_strlen(format);
	while (format[i] && i < len)
	{
		if (format[i] != '%')
			ft_putchar(format[i++], &res);
		else
		{
			i += 1;
			ft_placeholder(args, format, &res, &i);
		}
	}
	va_end (args);
	return (res);
}
