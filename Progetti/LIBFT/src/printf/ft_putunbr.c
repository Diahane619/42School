/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:31:30 by francevi          #+#    #+#             */
/*   Updated: 2023/06/24 08:54:52 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
