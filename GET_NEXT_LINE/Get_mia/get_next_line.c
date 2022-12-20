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

char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

char	*ft_riga(char *left_str)
{
	int		i;
	char	*riga;

	i = 0;
	if (!left_str[i])
		return (NULL);
	while (left_str[i] && left_str[i] != '\n')
		i++;
	riga = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (left_str[i] && left_str[i] != '\n')
	{
		riga[i] = left_str[i];
		i++;
	}
	if (left_str[i] && left_str[i] == '\n')
	{
		riga[i] = '\n';
		i++;
	}
	return (riga);
}

char	*ft_resto(char *left_str)
{
	int		i;
	int		j;
	char	*riga;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
	{
		free(left_str);
		return (NULL);
	}
	riga = ft_calloc((ft_strlen(left_str) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (left_str[i])
		riga[j++] = left_str[i++];
	free(left_str);
	return (riga);
}

char	*ft_unisci(int fd, char *left_str)
{
	char	*buffer;
	int		leggibyte;

	if (!left_str)
		left_str = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
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
		left_str = ft_free(left_str, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
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
