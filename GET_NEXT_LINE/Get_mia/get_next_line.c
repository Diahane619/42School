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

// partiamo dalla funzione get_next_line e poi vediamo le altre funzioni una volta che vengono chiamate

static char	*ft_next(char **temp)				// la funzione next prende come argomento un puntatore alla stringa temp, ci serve per passare alla linea successiva
{
	char	*line;						// puntatore alla prossima linea da leggere
	char	*ptr;						// puntatore 

	ptr = *temp;						// 
	while (*ptr && *ptr != '\n')				// fintanto non troviamo la nuova linea avanziamo il puntatore, poi lo assegniamo alla posizione successiva a "\n"
		++ptr;
	ptr += (*ptr == '\n');
	line = ft_substr(*temp, 0, (size_t)(ptr - *temp));	// assegniamo a line, la sottostringa di temp a partire dalla nuova linea.
	if (!line)						// caso limite
	{
		free (*temp);
		return (NULL);
	}
	ptr = ft_substr(ptr, 0, ft_strlen (ptr));		// accorciamo ptr togliendo la parte precedente la nuova linea che abbiamo trovato in precedenza
	free (*temp);						// liberiamo temp e assegniamo la nuova posizione di ptr
	*temp = ptr;
	return (line);						// torniamo il puntatore alla nuova linea
}

static char	*ft_read(char *temp, int fd, char *buf)	// la funzione prende il nostro temp, il fd e il buf e ritorna il nuovo valore di temp.
{								// Nello specifico, abbiamo un while che dura finche' non trova una nuova linea nel nostro temp.
	ssize_t		r;				// Dentro il while, leggiamo con read il fd nella misura massima del buffer size. Dopo aggiungiamo su temp
								// il contenuto di buf (cio' che abbiamo letto finora), e continua fino a che non si trova una nuova linea.
	r = 1;							// Appena la trova si libera il buff e si ritorna il temp, cioe' la stringa che abbiamo letto fino alla nuova linea.
	while (r && !ft_strchr (temp, '\n'))
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)					// caso limite in caso di errori nel read
		{
			free (buf);
			free (temp);
			return (NULL);
		}
		buf[r] = 0;
		temp = ft_strjoin(temp, buf);
		if (!temp)					// caso limite dove non troviamo la nuova linea e il temp e' terminato
		{
			free (buf);
			return (NULL);
		}
	}
	free (buf);
	return (temp);
}

char	*get_next_line(int fd)					// prototipo fornito dal soggetto, ritorna una stringa, ha come parametro un file descriptor (fd)
{
	static char	*temp[OPEN_MAX];			// stringa statica per immagazzinare i dati che leggiamo dal buffer
	char		*buf;					// stringa che usiamo come buffer

	if (fd == -1 || BUFFER_SIZE < 1)			// casi limite
		return (NULL);
	if (!temp[fd])						// casi limite
		return (NULL);
	buf = malloc (sizeof (*buf) * (BUFFER_SIZE + 1));	// mallocchiamo il buf per avere spazio a sufficienza (BUFFER SIZE) per leggere il fd
	if (!buf)						// se non va a buon fine ritorna null e liberiamo temp
	{
		free (temp[fd]);
		return (NULL);
	}
	temp[fd] = ft_read(temp[fd], fd, buf);		// assegniamo a temp i valori che leggiamo tramite la funzione ft_read (VEDI FUNZIONE). Questo ci serve per avanzare nella lettura del fd
	if (!temp[fd])						// con i valori assegnati al buffer. Negli IF vengono considerati i casi limite.
		return (NULL);
	if (!*temp[fd])
	{
		free (temp[fd]);
		temp[fd] = NULL;
		return (NULL);
	}
	return (ft_next(&temp[fd]));				// il nostro valore di ritorno e' il risultato della funzione ft_next
}