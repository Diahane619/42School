/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 04:00:01 by gamarcha          #+#    #+#             */
/*   Updated: 2021/06/13 04:00:01 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/* Questa funzione legge il contenuto del file di input e lo aggiunge alla stringa file.
   Parametri:
   - root: puntatore alla struttura t_root
   - file: puntatore alla stringa contenente il file di input
   - buf: buffer temporaneo per la lettura del file
   - fd: file descriptor del file di input */
static void	file_parse(t_root *root, char **file, char buf[], int fd)
{
	// Concatena il contenuto del buffer buf alla stringa file
	char			*tmp;
	tmp = ft_strjoin(*file, buf);
	// Libera la memoria della vecchia stringa file
	free(*file);
	// Assegna alla stringa file la nuova stringa concatenata
	*file = tmp;
	// Se l'allocazione di memoria per la nuova stringa file fallisce, chiude il file, distrugge la radice e mostra un messaggio di errore
	if (*file == 0)
	{
		close(fd);
		root_destroy(root, "map_init(): ft_strjoin()", errno);
	}
}
 /* Questa funzione legge il contenuto del file di input e lo passa alla funzione file_parse per l'aggiunta alla stringa file.
   Parametri:
   - root: puntatore alla struttura t_root
   - file: puntatore alla stringa contenente il file di input
   - buf: buffer temporaneo per la lettura del file
   - fd: file descriptor del file di input */
static void	file_read(t_root *root, char **file, char buf[], int fd)
{
	// Numero di byte letti dalla funzione read
	int				ret;
	// Continua a leggere il file finché non raggiunge la fine
	while (ret != 0)
	{
		// Legge dal file nel buffer buf fino a 1024 byte
		ret = read(fd, buf, 1024);
		// Se la lettura dal file fallisce, libera la memoria della stringa file, chiude il file, distrugge la radice e mostra un messaggio di errore
		if (ret == -1)
		{
			free(*file);
			close(fd);
			root_destroy(root, "map_init(): read()", errno);
		}
		else
		{
			// Aggiunge il terminatore di stringa al buffer buf
			buf[ret] = 0;
			// Passa il contenuto del buffer buf alla funzione file_parse per l'aggiunta alla stringa file
			file_parse(root, file, buf, fd);
		}
	}
}
 /* Questa funzione inizializza la stringa file con un byte allocato a zero.
   Parametri:
   - root: puntatore alla struttura t_root
   - fd: file descriptor del file di input
   Return:
   - Puntatore alla stringa file inizializzata */
static char	*file_init(t_root *root, int fd)
{
	// Alloca un byte di memoria e inizializza a zero
	char			*file;
	file = ft_calloc(1, 1);
	// Se l'allocazione di memoria fallisce, chiude il file, distrugge la radice e mostra un messaggio di errore
	if (file == 0)
	{
		close(fd);
		root_destroy(root, "map_init(): ft_calloc()", errno);
	}
	return (file);
}
 /* Questa funzione inizializza la lettura del file di input, legge il suo contenuto e lo passa alla funzione map_read per la lettura della mappa.
   Parametri:
   - root: puntatore alla struttura t_root
   - filename: nome del file di input */
void	map_init(t_root *root, char *filename)
{
	// File descriptor del file di input
	int				fd;
	// Stringa contenente il file di input
	char			*file;
	// Buffer temporaneo per la lettura del file
	char			buf[1024 + 1];
 	// Apre il file di input in modalità di sola lettura
	fd = open(filename, O_RDONLY);
	// Se l'apertura del file fallisce, distrugge la radice e mostra un messaggio di errore
	if (fd == -1)
		root_destroy(root, filename, errno);
	// Inizializza la stringa file
	file = file_init(root, fd);
	// Legge il contenuto del file e lo passa alla funzione map_read per la lettura della mappa
	file_read(root, &file, buf, fd);
	// Chiude il file
	close(fd);
	// Legge la mappa dal contenuto del file
	map_read