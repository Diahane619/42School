/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:58:51 by francevi          #+#    #+#             */
/*   Updated: 2023/06/22 12:59:19 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strappend(char *s1, char *s2, bool free_s1, bool free_s2)
{
	char	*s;
	ssize_t	i;
	ssize_t	j;

	if (!s1)
		s = (char *)ft_calloc(ft_strlen(s2) + 1, sizeof(char));
	else
		s = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!s)
		return (0);
	i = -1;
	while (s1 && s1[++i])
		s[i] = s1[i];
	j = -1;
	if (!s1)
		i++;
	while (s2 && s2[++j])
		s[i++] = s2[j];
	if (free_s1 && s1)
		ft_free((void **)&s1);
	if (free_s2 && s2)
		ft_free((void **)&s2);
	return (s);
}
