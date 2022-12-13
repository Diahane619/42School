/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:09:06 by jdecorte          #+#    #+#             */
/*   Updated: 2022/12/10 16:41:56 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// join and free
char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

// Ritorna il contenuto del file senza la la prima linea
char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
// Trova la lunghezza della prima linea
	while (buffer[i] && buffer[i] != '\n')
		i++;
// Se arriva alla fine del file ritorna NULL
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	// La lunghezza del file - La lunghezza della prima linea + 1
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	// Fino a che non arriva alla fine del file mi copi il contenuto rimanente del file in line e poi liberi la variabile statica buffer
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

// Prende la linea per fare il return
char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	// Se non ci sono linee ritorna NULL
	if (!buffer[i])
		return (NULL);
	// Vai alla fine della linea
	while (buffer[i] && buffer[i] != '\n')
		i++;
	// malloc fino alla fine
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	// line = buffer
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	// Se la fine della linea è \0 o \n, sostituiscila con \n e poi mi ritorna la linea
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}


char	*read_file(int fd, char *res)
{
	char	*buffer;
	int		byte_read;

	// malloc if res dont exist
	if (!res)
		res = ft_calloc(1, 1);
	// malloc buffer
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		// while not eof read
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		// 0 to end for leak
		buffer[byte_read] = 0;
		// join and free
		res = ft_free(res, buffer);
		// quit if \n find
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	// error handling
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (line);
}
