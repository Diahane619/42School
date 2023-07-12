/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 03:48:59 by gamarcha          #+#    #+#             */
/*   Updated: 2021/06/13 03:48:59 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Questa funzione disegna un quadrato sulla finestra di gioco.
   Parametri:
   - root: puntatore alla struttura t_root
   - img: puntatore all'immagine da disegnare
   - x: coordinata x del quadrato
   - y: coordinata y del quadrato */
static void	draw_square(t_root *root, t_img *img, int x, int y)
{
	unsigned int	color;
	int				i;
	int				j;
 	j = 0;
	while (j < 40)
	{
		i = 0;
		while (i < 40)
		{
			// Ottiene il colore del pixel dall'immagine
			color = mlx_get_pixel(img, i, j);
			// Verifica se il colore è diverso dal colore di sfondo (azzurro)
			if (color != mlx_rgb_to_int(0, 255, 255, 255))
				// Se il colore è diverso dal colore di sfondo, disegna il pixel sulla finestra di gioco
				mlx_draw_pixel(root->mlx_img, x + i, y + j, color);
			i++;
		}
		j++;
	}
}
 /* Questa funzione disegna gli elementi ambientali (uscita, collezionabili, giocatore) sulla mappa di gioco.
   Parametri:
   - root: puntatore alla struttura t_root
   - i: coordinata x dell'elemento
   - j: coordinata y dell'elemento */
static void	draw_env(t_root *root, int i, int j)
{
	int				k;
 	// Verifica se l'uscita si trova nelle coordinate (i, j)
	if (root->game->exit.x == i && root->game->exit.y == j)
		// Se l'uscita si trova nelle coordinate (i, j), disegna il quadrato corrispondente sull'immagine root->exit
		draw_square(root, root->exit, i * 40, j * 40);
	k = -1;
	while (++k < root->game->count_coll)
		// Verifica se il collezionabile k si trova nelle coordinate (i, j)
		if (root->game->coll[k].x == i && root->game->coll[k].y == j)
			// Se il collezionabile k si trova nelle coordinate (i, j), disegna il quadrato corrispondente sull'immagine root->coll
			draw_square(root, root->coll, i * 40, j * 40);
	// Verifica se il giocatore si trova nelle coordinate (i, j)
	if (root->game->player.x == i && root->game->player.y == j)
		// Se il giocatore si trova nelle coordinate (i, j), disegna il quadrato corrispondente sull'immagine root->player
		draw_square(root, root->player, i * 40, j * 40);
}
 /* Questa funzione disegna la mappa di gioco sulla finestra.
   Parametri:
   - root: puntatore alla struttura t_root */
static void	draw_map(t_root *root)
{
	int				i;
	int				j;
 	j = 0;
	while (j < root->game->height)
	{
		i = 0;
		while (i < root->game->width)
		{
			// Verifica se il valore della cella (i, j) nella mappa è 1 (muro)
			if (root->game->map[j][i] == 1)
				// Se il valore della cella (i, j) nella mappa è 1, disegna il quadrato corrispondente sull'immagine root->wall
				draw_square(root, root->wall, i * 40, j * 40);
			else
				// Altrimenti, disegna il quadrato corrispondente sull'immagine root->ground
				draw_square(root, root->ground, i * 40, j * 40);
			// Disegna gli elementi ambientali (uscita, collezionabili, giocatore) nella cella (i, j)
			draw_env(root, i, j);
			i++;
		}
		j++;
	}
}
 /* Questa funzione disegna la mappa di gioco sulla finestra di gioco.
   Parametri:
   - root: puntatore alla struttura t_root */
void	draw(t_root *root)
{
	// Disegna la mappa di gioco
	draw_map(root);
	// Mostra l'immagine root->mlx_img sulla finestra root->mlx_win
	mlx_put_image_to_window(root->mlx, root->mlx_win, root->mlx_img, 0, 0);
}