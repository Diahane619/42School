/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:30:48 by francevi          #+#    #+#             */
/*   Updated: 2023/06/24 08:54:20 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n, int *res)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", res);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		ft_putchar(('-'), res);
	}
	if (n >= 10)
		ft_putnbr(n / 10, res);
	ft_putchar(n % 10 + 48, res);
}
