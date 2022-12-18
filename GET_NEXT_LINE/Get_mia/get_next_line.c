/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:08:48 by francevi          #+#    #+#             */
/*   Updated: 2022/11/21 17:52:55 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_unisci(int fd, char *left_str)
{
	char	*buffer;
	int		leggibyte;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	leggibyte = 1;
	while (leggibyte > 0)
	{
		leggibyte = read(fd, buffer, BUFFER_SIZE);
		if (leggibyte == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[leggibyte] = 0;
		left_str = ft_strjoin(left_str, buffer);
	}
	free(buffer);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	left_str = ft_unisci(fd, left_str);
	if (!left_str)
		return (NULL);
	line = ft_riga(left_str);
	left_str = ft_resto(left_str);
	return (line);
}
