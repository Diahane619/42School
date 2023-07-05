/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:22:30 by francevi          #+#    #+#             */
/*   Updated: 2023/06/22 13:22:57 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa(unsigned int nb)
{
	char			*str;
	unsigned int	n;
	size_t			len;

	n = nb;
	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	if (!nb)
		len++;
	str = ft_calloc(len + 1, sizeof(char));
	if (!nb)
		str[0] = '0';
	while (nb && len--)
	{
		str[len] = nb % 10 + '0';
		nb /= 10;
	}	
	return (str);
}
