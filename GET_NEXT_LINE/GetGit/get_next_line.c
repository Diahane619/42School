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

// Unisci il contenuto della variabile satica e poi liberala
char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

/*
* FT_NEXT
* -------------
* Memorizza nella variabile statica cumulativa la nuova variabile aggiornata con qualsiasi cosa
* viene lasciato dall'originale, meno la riga estratta.
* PARAMETRI
* #1. Il puntatore alla variabile statica cumulativa dalle esecuzioni precedenti di get_next_line.
* VALORI DI RITORNO
* La nuova stringa aggiornata con tutto ciò che è rimasto dallo statico originale, meno il
* riga estratta.
*/

char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
// Trova la lunghezza della prima linea
	while (buffer[i] && buffer[i] != '\n')
		i++;
// Se arriva alla fine del file liberami buffer ritorna NULL
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	// Alloca memoria per la lunghezza del file - La lunghezza della prima linea + 1
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	// Fino a che non arriva alla fine del file mi copi il contenuto rimanente del file in line, mi liberi la variabile statica buffer e mi ritorni line
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

/*
* ---------
* FT_LINE
* ---------
* Estrae la riga (che termina con un'interruzione di riga (`\n`) + (`\0`)) 
* dalla variabile statica.
* PARAMETRI
* #1. Il puntatore alla variabile statica cumulativa dalle esecuzioni precedenti di get_next_line.
* VALORI DI RITORNO
* La stringa con la riga completa che termina con un'interruzione di riga (`\n`) + (`\0`).
* -------------
*/

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
	// Mi copi il contenuto di buffer in line
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

/*
* FT_READ_LINE
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

void	ft_read_line(int fd, char **keep, char **tmp)
{
	char	*buf;
	int		r;

	buf = malloc(sizeof * buf * (BUFFER_SIZE + 1));
	if (!buf)
		return ;
	r = 1;
	while (r > 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
		{
			ft_free_strs(&buf, keep, tmp);
			return ;
		}
		buf[r] = '\0';
		*tmp = ft_strdup(*keep);
		ft_free_strs(keep, 0, 0);
		*keep = ft_strjoin(*tmp, buf);
		ft_free_strs(tmp, 0, 0);
		if (contains_newline(*keep))
			break ;
	}
	ft_free_strs(&buf, 0, 0);
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
	static char	*buffer;
	char		*tmp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0) // gestione degli errori
		return (NULL);
	line = NULL;
	tmp = NULL;
	ft_read_line(fd, &buffer, &tmp); // lettura file e salvataggio dentro la varibile buffer
	if (!buffer) //controllo esistenza contenuto file
		return (NULL);
	line = ft_line(buffer); // inserisce ogni linea dentro la variabile line
	buffer = ft_next(buffer); // aggiorna buffer (senza le linee precedenti)
	return (line);
}

/*#include <stdio.h>

int	main(void)
{
	char	*line;
	int		fd1;
	int 	i;

	i = 0;
	
	fd1 = open("/nfs/homes/francevi/VsCode/42School/GET_NEXT_LINE/GetGit/tests/J. K. Rowling - Harry Potter 1 - Sorcerer's Stone.txt", O_RDONLY);
	while (i < 10)
	{
		line = get_next_line(fd1);
		printf("line(fd1): %s", line);
		free(line);
		i++;
	}
	close(fd1);
}*/
