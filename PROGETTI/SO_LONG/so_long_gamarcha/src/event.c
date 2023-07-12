/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 03:43:05 by gamarcha          #+#    #+#             */
/*   Updated: 2021/06/13 03:43:05 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Questa funzione gestisce l'evento di pressione di un tasto.
   Parametri:
   - keycode: codice del tasto premuto
   - root: puntatore alla struttura t_root */
int	key_press(int keycode, t_root *root)
{
	// Verifica se il tasto premuto è il tasto ESC (65307)
	if (keycode == 65307)
		// Se il tasto premuto è ESC, distrugge la radice e termina il programma
		root_destroy(root, 0, 0);
	// Verifica se il tasto premuto è il tasto W (119)
	if (keycode == 119)
		// Se il tasto premuto è W, imposta il flag player_up della struttura di gioco a 1
		root->game->player_up = 1;
	// Verifica se il tasto premuto è il tasto S (115)
	if (keycode == 115)
		// Se il tasto premuto è S, imposta il flag player_down della struttura di gioco a 1
		root->game->player_down = 1;
	// Verifica se il tasto premuto è il tasto A (97)
	if (keycode == 97)
		// Se il tasto premuto è A, imposta il flag player_left della struttura di gioco a 1
		root->game->player_left = 1;
	// Verifica se il tasto premuto è il tasto D (100)
	if (keycode == 100)
		// Se il tasto premuto è D, imposta il flag player_right della struttura di gioco a 1
		root->game->player_right = 1;
	// Aggiorna lo stato del gioco richiamando la funzione update
	update(root);
	// Restituisce 0 per indicare che l'evento è stato gestito correttamente
	return (0);
}
 /* Questa funzione gestisce l'evento di rilascio di un tasto.
   Parametri:
   - keycode: codice del tasto rilasciato
   - root: puntatore alla struttura t_root */
int	key_release(int keycode, t_root *root)
{
	// Verifica se il tasto rilasciato è il tasto W (119)
	if (keycode == 119)
		// Se il tasto rilasciato è W, imposta il flag player_up della struttura di gioco a 0
		root->game->player_up = 0;
	// Verifica se il tasto rilasciato è il tasto S (115)
	if (keycode == 115)
		// Se il tasto rilasciato è S, imposta il flag player_down della struttura di gioco a 0
		root->game->player_down = 0;
	// Verifica se il tasto rilasciato è il tasto A (97)
	if (keycode == 97)
		// Se il tasto rilasciato è A, imposta il flag player_left della struttura di gioco a 0
		root->game->player_left = 0;
	// Verifica se il tasto rilasciato è il tasto D (100)
	if (keycode == 100)
		// Se il tasto rilasciato è D, imposta il flag player_right della struttura di gioco a 0
		root->game->player_right = 0;
	// Aggiorna lo stato del gioco richiamando la funzione update
	update(root);
	// Restituisce 0 per indicare che l'evento è stato gestito correttamente
	return (0);
}
 /* Questa funzione gestisce l'evento di distruzione della finestra.
   Parametri:
   - keycode: codice dell'evento di distruzione
   - root: puntatore alla struttura t_root */
int	destroy_hook(int keycode, t_root *root)
{
	// Ignora il parametro keycode
	(void)keycode;
	// Ignora il parametro root
	(void)root;
	// Distrugge la radice e termina il programma
	root_destroy(0, 0, 0);
	// Restituisce 0 per indicare che l'evento è stato gestito correttamente
	return (0);
}