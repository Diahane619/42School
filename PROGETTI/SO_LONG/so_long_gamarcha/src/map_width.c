/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 04:08:54 by gamarcha          #+#    #+#             */
/*   Updated: 2021/06/13 04:08:54 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Questa funzione calcola la larghezza della mappa leggendo il file di input.
   Parametri:
   - root: puntatore alla struttura t_root
   - file: puntatore alla stringa contenente il file di input */
void	map_width(t_root *root, char *file)
{
	// Inizializza la larghezza della mappa a 0
	root->game->width = 0;
	// Scorri il file fino a trovare una nuova riga o la fine del file
	while (file[root->game->width] && file[root->game->width] != '\n')
		// Incrementa la larghezza della mappa
		root->game->width++;
	// Verifica se la larghezza della mappa è 0 o se il file è terminato prima di trovare una nuova riga
	if (root->game->width == 0 || file[root->game->width] == 0)
	{
		// Libera la memoria allocata per il file
		free(file);
		// Distruggi la struttura root e mostra un messaggio di errore
		root_destroy(root, "map file is invalid", 0);
	}
}