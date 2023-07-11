/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   root_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 04:11:06 by gamarcha          #+#    #+#             */
/*   Updated: 2021/06/13 04:11:06 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Questa funzione distrugge la struttura t_root e libera la memoria allocata per essa.
   Parametri:
   - root: puntatore alla struttura t_root da distruggere
   - errmsg: messaggio di errore da visualizzare in caso di errore
   - errnum: numero di errore da visualizzare in caso di errore */
void	root_destroy(t_root *root, char *errmsg, int errnum)
{
	// Verifica se la struttura root non è nulla
	if (root != 0)
	{
		// Verifica se l'immagine ground non è nulla e la distrugge
		if (root->ground != 0)
			mlx_destroy_image(root->mlx, root->ground);
		// Verifica se l'immagine wall non è nulla e la distrugge
		if (root->wall != 0)
			mlx_destroy_image(root->mlx, root->wall);
		// Verifica se l'immagine coll non è nulla e la distrugge
		if (root->coll != 0)
			mlx_destroy_image(root->mlx, root->coll);
		// Verifica se l'immagine exit non è nulla e la distrugge
		if (root->exit != 0)
			mlx_destroy_image(root->mlx, root->exit);
		// Verifica se l'immagine player non è nulla e la distrugge
		if (root->player != 0)
			mlx_destroy_image(root->mlx, root->player);
		// Verifica se l'immagine mlx_img non è nulla e la distrugge
		if (root->mlx_img != 0)
			mlx_destroy_image(root->mlx, root->mlx_img);
		// Verifica se la finestra mlx_win non è nulla e la distrugge
		if (root->mlx_win != 0)
			mlx_destroy_window(root->mlx, root->mlx_win);
		// Verifica se il display mlx non è nulla e lo distrugge
		if (root->mlx != 0)
			mlx_destroy_display(root->mlx);
		// Verifica se il gioco game non è nullo e lo distrugge
		if (root->game != 0)
			game_destroy(root->game);
		// Libera la memoria allocata per la struttura root
		free(root);
	}
	// Chiama la funzione die per gestire l'errore
	die(errmsg, errnum);
}