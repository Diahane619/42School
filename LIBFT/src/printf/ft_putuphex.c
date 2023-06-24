/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuphex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:30:23 by francevi          #+#    #+#             */
/*   Updated: 2023/06/24 08:55:04 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
