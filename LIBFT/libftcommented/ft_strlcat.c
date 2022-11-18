/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:40:17 by pbie              #+#    #+#             */
/*   Updated: 2022/10/28 19:53:30 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	j;
	size_t	k;

	j = 0;
	k = 0;
	while (dst[j] && j < size)
		j++;
	while ((src[k]) && ((j + k + 1) < size))
	{
		dst[j + k] = src[k];
		k++;
	}
	if (j + k < size)
		dst[j + k] = '\0'; /*per chiudere la stringa*/
	return (j + ft_strlen(src));
}

#include <stdio.h>

int main()
{
	char src[50], dest[50];

	ft_strcpy(src, "This is source");
	ft_strcpy(dest, "This is destination");

	printf("%ld\n", ft_strlcat(dest, src, 18));

	return(0);
}
