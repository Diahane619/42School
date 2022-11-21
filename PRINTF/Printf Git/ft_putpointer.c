/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:56:59 by rel-fila          #+#    #+#             */
/*   Updated: 2022/11/20 17:21:56 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putpointer(void *p, int *count)
{
	if (p == 0)
		ft_putstr("(nil)", count);
	else
	{
		ft_putstr("0x", count);
		ft_puthex((unsigned long long)p, count);
	}
}
