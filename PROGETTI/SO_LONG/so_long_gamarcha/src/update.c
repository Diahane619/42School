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

/* La funzione had_move() controlla se il giocatore si è spostato rispetto alla sua posizione precedente. 
Se si è spostato, incrementa il contatore dei movimenti del giocatore e lo stampa su stdout. */
static void had_move(t_root *root, int x, int y)
{
	if (root->game->player.x != x || root->game->player.y != y) // Controlla se le coordinate attuali del giocatore sono diverse dalle coordinate precedenti
	{
		root->game->player_move++; // Incrementa il contatore dei movimenti del giocatore
		ft_putnbr_fd(root->game->player_move, 1); // Stampa il numero dei movimenti del giocatore su stdout
		ft_putendl_fd("", 1); // Stampa una nuova riga vuota su stdout
	}
}
/* La funzione iscollectable() controlla se il giocatore si trova su un oggetto collezionabile. 
 Se si trova su un oggetto collezionabile, lo rimuove dalla mappa e incrementa il contatore degli oggetti collezionati dal giocatore. */
static void iscollectable(t_root *root)
{
	int k;
 	k = 0;
	while (k < root->game->count_coll) // Scorre tutti gli oggetti collezionabili sulla mappa
	{
		if (root->game->coll[k].x == root->game->player.x // Controlla se le coordinate del giocatore corrispondono a quelle di un oggetto collezionabile
			&& root->game->coll[k].y == root->game->player.y)
		{
			root->game->coll[k].x = -1; // Rimuove l'oggetto dalla mappa impostando le sue coordinate a -1
			root->game->coll[k].y = -1; 
			root->game->player_coll++; // Incrementa il contatore degli oggetti collezionati dal giocatore
		}
		k++;
	}
}
 /* La funzione update() aggiorna lo stato del gioco. Controlla la direzione del movimento del giocatore e chiama la funzione di movimento corrispondente. 
 In seguito, chiama le funzioni had_move() e iscollectable() per gestire il movimento del giocatore e la raccolta degli oggetti collezionabili. 
 Infine, richiama la funzione draw() per disegnare il gioco aggiornato sulla finestra. */
void update(t_root *root)
{
	int x;
	int y;
 	x = root->game->player.x; // Salva le coordinate attuali del giocatore
	y = root->game->player.y;
	if (root->game->player_up != 0) // Se il giocatore si sta muovendo verso l'alto, chiama la funzione move_up()
		move_up(root, x, y);
	else if (root->game->player_down != 0) // Se il giocatore si sta muovendo verso il basso, chiama la funzione move_down()
		move_down(root, x, y);
	else if (root->game->player_left != 0) // Se il giocatore si sta muovendo verso sinistra, chiama la funzione move_left()
		move_left(root, x, y);
	else if (root->game->player_right != 0) // Se il giocatore si sta muovendo verso destra, chiama la funzione move_right()
		move_right(root, x, y);
	had_move(root, x, y); // Controlla se il giocatore si è spostato e gestisce il contatore dei movimenti
	iscollectable(root); // Controlla se il giocatore ha raccolto un oggetto collezionabile
	draw(root); // Disegna il gioco aggiornato sulla finestra
	if (root->game->exit.x == root->game->player.x // Controlla se il giocatore si trova sull'uscita e ha raccolto tutti gli oggetti collezionabili
		&& root->game->exit.y == root->game->player.y)
		if (root->game->count_coll == root->game->player_coll)
			root_destroy(root, 0, 0); // Se sì, distrugge la struttura root e termina il programma
}