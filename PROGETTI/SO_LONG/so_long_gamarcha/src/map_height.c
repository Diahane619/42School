/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_height.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 04:09:01 by gamarcha          #+#    #+#             */
/*   Updated: 2021/06/13 04:09:01 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/* Questa funzione calcola l'altezza della mappa a partire dal contenuto del file.
   Parametri:
   - root: puntatore alla struttura t_root
   - file: puntatore alla stringa contenente il file di input */
void	map_height(t_root *root, char *file)
{
	// Indice per la lettura del file
	int				i;
	// Indice per la lettura di ogni riga della mappa
	int				j;
	// Inizializza l'altezza della mappa a 1
	root->game->height = 1;
	// Inizia la lettura del file dalla posizione dopo la larghezza della mappa
	i = root->game->width + 1;
	// Continua a leggere il file finché non raggiunge la fine
	while (file[i] != 0)
	{
		// Inizia la lettura di una nuova riga dalla posizione 0
		j = 0;
		// Continua a leggere la riga finché non raggiunge la fine o il carattere di nuova linea
		while (file[i + j] != 0 && file[i + j] != '\n')
			j++;
		// Se la larghezza della riga è diversa dalla larghezza della mappa, libera la memoria del file, distrugge la radice e mostra un messaggio di errore
		if (root->game->width != j)
		{
			free(file);
			root_destroy(root, "map format is invalid", 0);
		}
		// Passa alla prossima riga della mappa
		i += root->game->width + 1;
		// Incrementa l'altezza della mappa
		root->game->height++;
	}
}