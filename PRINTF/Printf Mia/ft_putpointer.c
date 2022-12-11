/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:31:14 by francevi          #+#    #+#             */
/*   Updated: 2022/12/11 18:31:14 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putpointer(void *p, int *res)
{
	if (p == 0)
		ft_putstr("(nil)", res);
	else
	{
		ft_putstr("0x", res);
		ft_puthex((unsigned long long)p, res);
	}
}
