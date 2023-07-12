/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 04:11:04 by gamarcha          #+#    #+#             */
/*   Updated: 2021/06/13 04:11:04 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/* Questa funzione distrugge la struttura di gioco (t_game) e libera la memoria allocata.
   Parametri:
   - game: puntatore alla struttura t_game da distruggere */
void	game_destroy(t_game *game)
{
	// Indice per la lettura delle righe della mappa
	int				i;
 	// Verifica se la struttura di gioco esiste
	if (game != 0)
	{
		// Libera la memoria allocata per l'array di oggetti raccoglibili (coll)
		if (game->coll != 0)
			free(game->coll);
		// Libera la memoria allocata per la mappa di gioco (map)
		if (game->map != 0)
		{
			// Inizia la lettura delle righe della mappa
			i = 0;
			// Continua a leggere finché non raggiunge l'altezza della mappa
			while (i < game->height)
				// Libera la memoria allocata per ogni riga della mappa
				free(game->map[i++]);
			// Libera la memoria allocata per l'array di puntatori alle righe della mappa
			free(game->map);
		}
		// Libera la memoria allocata per la struttura di gioco
		free(game);
	}
}