<<<<<<< HEAD
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
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:08:48 by francevi          #+#    #+#             */
/*   Updated: 2022/11/21 15:08:50 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*buf[4096];
	char		*line;
	size_t		old_len;

	if (fd < 0 || fd > 4095 || BUFFER_SIZE < 0)
		return (NULL);
	line = NULL;
	if (gnl_strchr_i(buf[fd], '\n') == -1)
	{
		old_len = gnl_strlen(buf[fd]);
		buf[fd] = gnl_expand_buffer(buf[fd], fd);
		if (old_len == gnl_strlen(buf[fd]) && buf[fd])
			line = gnl_substr(buf[fd], 0, gnl_strlen(buf[fd]));
	}
	if (!buf[fd])
		return (NULL);
	if (!line && gnl_strchr_i(buf[fd], '\n') != -1)
		line = gnl_substr(buf[fd], 0, gnl_strchr_i(buf[fd], '\n') + 1);
	if (line)
	{
		buf[fd] = gnl_shrink_buffer(buf[fd], line);
		return (line);
	}
	return (get_next_line(fd));
}

char	*gnl_shrink_buffer(char *buf, char *line)
{
	char	*newbuf;
	int		line_len;

	if (!buf || !line)
		return (buf);
	line_len = gnl_strlen(line);
	if ((int)gnl_strlen(buf) == line_len)
	{
		free(buf);
		return (NULL);
	}
	newbuf = gnl_substr(buf, line_len, gnl_strlen(buf) - line_len);
	free(buf);
	return (newbuf);
}

char	*gnl_expand_buffer(char *buf, int fd)
{
	char	*newbuf;
	int		newlen;
	char	*aux;

	aux = gnl_newread(fd);
	if (!aux)
		return (NULL);
	if (!aux[0])
	{
		free(aux);
		return (buf);
	}
	if (!buf)
		return (aux);
	newlen = gnl_strlen(buf) + gnl_strlen(aux);
	newbuf = malloc(newlen + 1);
	if (!newbuf)
		return (NULL);
	gnl_strlcpy(newbuf, buf, newlen + 1);
	gnl_strlcat(newbuf, aux, newlen + 1);
	free(buf);
	free(aux);
	return (newbuf);
}

char	*gnl_newread(int fd)
{
	char	*aux;
	int		nbytes;

	aux = malloc(BUFFER_SIZE + 1);
	if (!aux)
		return (NULL);
	nbytes = read(fd, aux, BUFFER_SIZE);
	if (nbytes < 0)
	{
		free(aux);
		return (NULL);
	}
	aux[nbytes] = '\0';
	return (aux);
}
>>>>>>> origin/master