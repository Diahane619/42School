/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 04:01:24 by gamarcha          #+#    #+#             */
/*   Updated: 2021/06/13 04:01:24 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Questa funzione legge il file di input della mappa e inizializza la struttura di gioco.
   Parametri:
   - root: puntatore alla struttura t_root
   - file: puntatore alla stringa contenente il file di input */
void	map_read(t_root *root, char *file)
{
	// Calcola la larghezza della mappa
	map_width(root, file);
	// Calcola l'altezza della mappa
	map_height(root, file);
	// Verifica se la mappa è valida
	map_isvalid(root, file);
	// Alloca memoria per l'array di coordinate dei muri
	root->game->coll = (t_coord *)malloc(sizeof(t_coord) * root->game->count_coll);
	// Verifica se l'allocazione di memoria è riuscita
	if (root->game->coll == 0)
	{
		// Libera la memoria allocata per il file
		free(file);
		// Distruggi la struttura root e mostra un messaggio di errore
		root_destroy(root, "map_parsing(): malloc()", errno);
	}
	// Alloca memoria per la matrice che rappresenta la mappa
	root->game->map = (int **)malloc(sizeof(int *) * root->game->height);
	// Verifica se l'allocazione di memoria è riuscita
	if (root->game->map == 0)
	{
		// Libera la memoria allocata per il file
		free(file);
		// Distruggi la struttura root e mostra un messaggio di errore
		root_destroy(root, "map_parsing(): malloc()", errno);
	}
	// Effettua il parsing del file e popola la struttura di gioco
	map_parsing(root, file);
}