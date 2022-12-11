/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fila <rel-fila@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:58:31 by rel-fila          #+#    #+#             */
/*   Updated: 2022/11/08 16:58:42 by rel-fila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunbr(unsigned int n, int *res)
{
	if (n >= 10)
	{
		ft_putunbr((n / 10), res);
		ft_putunbr((n % 10), res);
	}
	else
		ft_putchar((n + 48), res);
}
