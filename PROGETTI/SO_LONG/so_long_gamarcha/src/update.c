/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 03:47:37 by gamarcha          #+#    #+#             */
/*   Updated: 2021/06/13 03:47:37 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Questa funzione controlla se il giocatore si è mosso rispetto alla sua posizione precedente.
 Se il giocatore si è mosso, incrementa il contatore delle mosse del giocatore e lo stampa su stdout. */
static void had_move(t_root *root, int x, int y)
{
	if (root->game->player.x != x || root->game->player.y != y)
	{
		root->game->player_move++; // Incrementa il contatore delle mosse del giocatore
		ft_putnbr_fd(root->game->player_move, 1); // Stampa il valore del contatore sul file descriptor 1 (stdout)
		ft_putendl_fd("", 1); // Stampa una nuova riga sul file descriptor 1 (stdout)
	}
}
 /* Questa funzione controlla se il giocatore ha raccolto un oggetto collezionabile nella sua posizione attuale. 
 Se sì, segna l'oggetto come raccolto e incrementa il contatore degli oggetti raccolti dal giocatore. */
static void iscollectable(t_root *root)
{
	int k;
 	k = 0;
	while (k < root->game->count_coll)
	{
		if (root->game->coll[k].x == root->game->player.x
			&& root->game->coll[k].y == root->game->player.y)
		{
			root->game->coll[k].x = -1; // Segna l'oggetto come raccolto impostando la sua coordinata x a -1
			root->game->coll[k].y = -1; // Segna l'oggetto come raccolto impostando la sua coordinata y a -1
			root->game->player_coll++; // Incrementa il contatore degli oggetti raccolti dal giocatore
		}
		k++;
	}
}
 /* Questa funzione aggiorna lo stato del gioco. Controlla la direzione in cui il giocatore si
  sta muovendo e chiama la funzione di movimento corrispondente. Successivamente, controlla se 
  il giocatore si è mosso e se ha raccolto tutti gli oggetti collezionabili. 
  Se sì, distrugge l'intera struttura del gioco. */
void update(t_root *root)
{
	int x;
	int y;
 	x = root->game->player.x;
	y = root->game->player.y;
	if (root->game->player_up != 0)
		move_up(root, x, y); // Chiamata alla funzione di movimento verso l'alto
	else if (root->game->player_down != 0)
		move_down(root, x, y); // Chiamata alla funzione di movimento verso il basso
	else if (root->game->player_left != 0)
		move_left(root, x, y); // Chiamata alla funzione di movimento verso sinistra
	else if (root->game->player_right != 0)
		move_right(root, x, y); // Chiamata alla funzione di movimento verso destra
	had_move(root, x, y); // Controlla se il giocatore si è mosso
	iscollectable(root); // Controlla se il giocatore ha raccolto un oggetto collezionabile
	draw(root); // Disegna lo stato del gioco
	if (root->game->exit.x == root->game->player.x
		&& root->game->exit.y == root->game->player.y)
		if (root->game->count_coll == root->game->player_coll)
			root_destroy(root, 0, 0); // Distrugge l'intera struttura del gioco se il giocatore ha raggiunto l'uscita e ha raccolto tutti gli oggetti collezionabili
}