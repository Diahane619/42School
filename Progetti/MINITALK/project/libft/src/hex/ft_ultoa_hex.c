/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:25:07 by francevi          #+#    #+#             */
/*   Updated: 2023/06/22 13:25:37 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa_hex(unsigned int n, bool is_upper)
{
	char	*base;
	char	*str;
	size_t	i;

	base = "0123456789abcdef";
	if (is_upper)
		base = "0123456789ABCDEF";
	str = ft_calloc(ft_hexlen(n) + 1, sizeof(char));
	str[0] = '0';
	i = 0;
	while (n)
	{
		str[i] = base[n % 16];
		n /= 16;
		i++;
	}
	ft_strrev(str);
	return (str);
}
