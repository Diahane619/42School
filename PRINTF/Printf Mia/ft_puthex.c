res/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fila <rel-fila@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:55:25 by rel-fila          #+#    #+#             */
/*   Updated: 2022/11/08 16:55:58 by rel-fila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_puthex(unsigned long n, int *res)
{
	if (n >= 16)
	{
		ft_puthex(n / 16, res);
		ft_puthex(n % 16, res);
	}
	else if (n < 10)
		ft_putchar(n + 48, res);
	else
		ft_putchar(n + 87, res);
}
