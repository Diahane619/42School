/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_append.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:48:02 by francevi          #+#    #+#             */
/*   Updated: 2023/06/22 12:54:06 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_char_append(char *s, char c, bool to_free)
{
	size_t	i;
	char	*str;

	if(!s)
	{
		str = (char *)malloc(sizeof(char) * 2);
		if(!str)
			return (0);
		str[0] = c;
		str[1] = 0;
		return(str);
	}
	i = 0;
	while(s[i])
		i++;
	str = (char *)malloc(sizeof(char) * ++i + 1);
	if (!str)
		return(0);
	str[i - 1] = c;
	str[i--] = 0;
	while (i--)
		str[i] = s[i];
	if (to_free && s)
		ft_free((voi **)&s);
	return(str);
}