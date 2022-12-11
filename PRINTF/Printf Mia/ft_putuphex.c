/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuphex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fila <rel-fila@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:59:11 by rel-fila          #+#    #+#             */
/*   Updated: 2022/11/08 16:59:43 by rel-fila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putuphex(unsigned int n, int *res)
{
	if (n >= 16)
	{
		ft_putuphex(n / 16, res);
		ft_putuphex(n % 16, res);
	}
	else if (n < 10)
		ft_putchar(n + 48, res);
	else
		ft_putchar(n + 55, res);
}
