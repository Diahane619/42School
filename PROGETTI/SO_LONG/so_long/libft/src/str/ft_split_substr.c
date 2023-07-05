/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_substr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:14:56 by francevi          #+#    #+#             */
/*   Updated: 2023/06/22 13:15:21 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_split_substr(char **s, int start, size_t len, char split)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (start < 0)
		start = 0;
	sub = malloc(len + 1);
	if (!sub)
		return (0);
	if ((ssize_t)start > ft_stridx(*s, 0))
	{
		sub[0] = 0;
		return (sub);
	}
	while (i < len && (*s)[start])
		sub[i++] = (*s)[start++];
	sub[i] = 0;
	if (split == 1)
		*s = ft_split_substr(s, ft_stridx(sub, 0), ft_stridx(*s, 0) \
			- ft_stridx(sub, 0), -1);
	if (split == -1)
		ft_free((void **)&(*s));
	return (sub);
}
