/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:28:08 by francevi          #+#    #+#             */
/*   Updated: 2022/10/07 14:28:09 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memmove(void *dest, const void *src, size_t n)
{
        unsigned char    *d;
        unsigned char	*s;
        
        if(!dest && !src)
        	return(dest);
        if(dest < src)
        	return(ft_memcpy(dest, src, n));
        d = (unsigned char *)dest;
        s = (unsigned char *)src;
        while(n--)
                d[n] = s[n];
        return(dest);
}
