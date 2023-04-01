/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:55:50 by francevi          #+#    #+#             */
/*   Updated: 2022/10/31 15:18:57 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*d;

	d = (unsigned char *)s;
	c = (unsigned char)c;
	while (n)
	{
		if (*d == c)
			return ((void *)d);
		++d;
		--n;
	}
	return (NULL);
}
