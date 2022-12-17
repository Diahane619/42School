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
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

/*
* FT_UNISCI
* -----------------
* DESCRIZIONE
* Prende il file descriptor aperto e salva su una variabile "buff" quanto letto
* Poi lo unisce alla variabile statica cumulativa per la persistenza delle informazioni.
* PARAMETRI
* #1. Un descrittore di file.
* #2. Puntatore alla variabile statica cumulativa delle esecuzioni precedenti di get_next_line.
* VALORI DI RITORNO
* Il nuovo valore della variabile statica con buffer unito per la persistenza delle informazioni,
* o NULL in caso di errore.
*/

char	*ft_unisci(int fd, char *left_str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(left_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		left_str = ft_strjoin(left_str, buff);
	}
	free(buff);
	return (left_str);
}

/*
* GET_NEXT_LINE
* -------------
* DESCRIZIONE
* Questa funzione prende un file descriptor(fd) aperto e restituisce la riga successiva.
* Questa funzione ha un comportamento indefinito durante la lettura da un file binario.
* PARAMETRI
* #1. Un descrittore di file
* VALORI DI RITORNO
* In caso di successo, get_next_line restituisce una stringa con la riga completa che termina con
* un'interruzione di riga (`\n`) quando ce n'è una.
* Se si verifica un errore o non c'è altro da leggere, restituisce NULL.
* ------------------------------------------------- ---------------------------
*/

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str = ft_unisci(fd, left_str);
	if (!left_str)
		return (NULL);
	line = ft_prendiriga(left_str);
	left_str = ft_rimasto(left_str);
	return (line);
}


/*int	main(void)
{
	char	*line;
	int		fd1;
	
	fd1 = open("/nfs/homes/francevi/VsCode/42School/GET_NEXT_LINE/Get_mia/tests/J. K. Rowling - Harry Potter 1 - Sorcerer's Stone.txt", O_RDONLY);
	while (line)
	{
		line = get_next_line(fd1);
		printf("line(fd1): %s", line);
		free(line);
	}
	close(fd1);
}*/
