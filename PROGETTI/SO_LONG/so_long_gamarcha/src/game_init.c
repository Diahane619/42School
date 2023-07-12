/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 03:59:10 by gamarcha          #+#    #+#             */
/*   Updated: 2021/06/13 03:59:10 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Questa funzione inizializza la struttura di gioco (t_game) all'interno della radice (t_root).
   Parametri:
   - root: puntatore alla struttura t_root
   - filename: puntatore alla stringa contenente il nome del file di input */
void	game_init(t_root *root, char *filename)
{
	// Alloca la memoria per la struttura di gioco
	root->game = (t_game *)malloc(sizeof(t_game));
	// Verifica se l'allocazione di memoria è andata a buon fine
	if (root->game == 0)
		// Se l'allocazione di memoria non è riuscita, distrugge la radice e mostra un messaggio di errore
		root_destroy(root, "game_init(): malloc()", errno);
	// Inizializza i puntatori della struttura di gioco a zero
	root->game->map = 0;
	root->game->coll = 0;
	root->game->count_coll = 0;
	root->game->count_exit = 0;
	root->game->count_player = 0;
	root->game->player_move = 0;
	root->game->player_coll = 0;
	root->game->player_up = 0;
	root->game->player_down = 0;
	root->game->player_left = 0;
	root->game->player_right = 0;
	// Inizializza la mappa di gioco richiamando la funzione map_init
	map_init(root, filename);
}