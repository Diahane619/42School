/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 03:45:48 by gamarcha          #+#    #+#             */
/*   Updated: 2021/06/13 03:45:48 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Questa funzione sposta il giocatore verso l'alto nella mappa se la cella corrispondente è vuota.
   Parametri:
   - root: puntatore alla struttura t_root
   - x: coordinata x del giocatore
   - y: coordinata y del giocatore */
void	move_up(t_root *root, int x, int y)
{
	// Verifica se la cella sopra il giocatore è vuota
	if (root->game->map[y - 1][x] == 0)
		// Sposta il giocatore verso l'alto
		root->game->player.y -= 1;
}
 /* Questa funzione sposta il giocatore verso il basso nella mappa se la cella corrispondente è vuota*/
void	move_down(t_root *root, int x, int y)
{
	// Verifica se la cella sotto il giocatore è vuota
	if (root->game->map[y + 1][x] == 0)
		// Sposta il giocatore verso il basso
		root->game->player.y += 1;
}
 // Questa funzione sposta il giocatore verso sinistra nella mappa se la cella corrispondente è vuota.
void	move_left(t_root *root, int x, int y)
{
	// Verifica se la cella a sinistra del giocatore è vuota
	if (root->game->map[y][x - 1] == 0)
		// Sposta il giocatore verso sinistra
		root->game->player.x -= 1;
}
 // Questa funzione sposta il giocatore verso destra nella mappa se la cella corrispondente è vuota.
void	move_right(t_root *root, int x, int y)
{
	// Verifica se la cella a destra del giocatore è vuota
	if (root->game->map[y][x + 1] == 0)
		// Sposta il giocatore verso destra
		root->game->player.x += 1;
}