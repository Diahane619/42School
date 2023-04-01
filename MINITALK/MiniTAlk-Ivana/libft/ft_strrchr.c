/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 22:22:20 by francevi          #+#    #+#             */
/*   Updated: 2022/11/04 18:15:01 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*str;

	str = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			str = (char *)&s[i];
		i++;
	}
	if ((char)c == s[i])
		return ((char *)&s[i]);
	return (str);
}
