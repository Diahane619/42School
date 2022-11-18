/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 19:17:48 by pbie              #+#    #+#             */
/*   Updated: 2022/10/25 10:56:18 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*La funzione strcat concatena due stringhe, appendendo la seconda stringa in coda alla prima.*/
char		*ft_strcat(char *s1, const char *s2)
{
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	s2 = (char *)s2;
	while (*s1)
		s1++;
	while (*s2)
		*s1++ = *s2++;
	*s1 = '\0';
	return (s1 - len);
}
