/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_isvalid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 04:06:30 by gamarcha          #+#    #+#             */
/*   Updated: 2021/06/13 04:06:30 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/* Questa funzione controlla se un indice i corrisponde ai bordi della mappa.
   Parametri:
   - root: puntatore alla struttura t_root
   - i: indice da controllare
   Return:
   - 1 se l'indice è un bordo della mappa, altrimenti 0 */
static int	isborder(t_root *root, int i)
{
	// Controlla se l'indice è minore della larghezza della mappa
	if (i < root->game->width
		// Controlla se l'indice è maggiore dell'ultimo indice della penultima riga
		|| i > (root->game->width + 1) * (root->game->height - 1)
		// Controlla se l'indice è un multiplo della larghezza + 1
		|| i % (root->game->width + 1) == 0
		// Controlla se l'indice è un multiplo della larghezza + 1 meno 1
		|| i % (root->game->width + 1) == root->game->width - 1)
		return (1);
	// Se nessuna delle condizioni precedenti è soddisfatta, restituisce 0
	return (0);
}
 /* Questa funzione controlla la validità del contenuto della mappa.
   Parametri:
   - root: puntatore alla struttura t_root
   - file: puntatore alla stringa contenente il file di input
   - i: indice corrente nel file di input */
static void	isvalid(t_root *root, char *file, int i)
{
	// Se il carattere corrente è 'P', incrementa il contatore dei giocatori
	if (file[i] == 'P')
		root->game->count_player++;
	// Se il carattere corrente è 'E', incrementa il contatore delle uscite
	else if (file[i] == 'E')
		root->game->count_exit++;
	// Se il carattere corrente è 'C', incrementa il contatore dei muri
	else if (file[i] == 'C')
		root->game->count_coll++;
	// Se il carattere corrente è '1' o '0', passa al carattere successivo
	else if (file[i] == '1' || file[i] == '0')
		return ;
	// Se il carattere corrente non è valido, libera la memoria e mostra un messaggio di errore
	else
	{
		free(file);
		root_destroy(root, "map content is invalid", 0);
	}
}
 /* Questa funzione controlla la validità della configurazione della mappa.
   Parametri:
   - root: puntatore alla struttura t_root
   - file: puntatore alla stringa contenente il file di input */
void	map_isvalid(t_root *root, char *file)
{
	int	i;
	i = -1;
	// Itera sui caratteri del file di input
	while (file[++i] != 0)
	{
		// Se il carattere corrente è un carattere di nuova riga, passa al carattere successivo
		if (file[i] == '\n')
			continue ;
		// Se l'indice corrente corrisponde a un bordo della mappa
		if (isborder(root, i))
		{
			// Se il carattere corrente non è '1', libera la memoria e mostra un messaggio di errore
			if (file[i] != '1')
			{
				free(file);
				root_destroy(root, "map isn't surrounded by walls", 0);
			}
		}
		// Altrimenti, controlla la validità del carattere corrente
		else
			isvalid(root, file, i);
	}
	// Se il numero di giocatori non è esattamente 1, il numero di uscite non è esattamente 1
	// o il numero di muri è inferiore a 1, libera la memoria e mostra un messaggio di errore
	if (root->game->count_player != 1
		|| root->game->count_exit != 1
		|| root->game->count_coll < 1)
	{
		free(file);
		root_destroy(root, "map configuration is invalid", 0);
	}
}