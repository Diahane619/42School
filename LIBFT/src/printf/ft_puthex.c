/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:30:57 by francevi          #+#    #+#             */
/*   Updated: 2023/06/24 08:54:10 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex(unsigned long n, int *res)
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
