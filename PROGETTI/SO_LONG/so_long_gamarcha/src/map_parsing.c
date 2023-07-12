/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 04:03:36 by gamarcha          #+#    #+#             */
/*   Updated: 2021/06/13 04:03:36 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Questa funzione libera la memoria allocata per la matrice e il file di input.
   Parametri:
   - root: puntatore alla struttura t_root
   - file: puntatore alla stringa contenente il file di input
   - m: puntatore alla matrice da liberare
   - size: dimensione della matrice */
static void	free_matrix(t_root *root, char *file, int **m, int size)
{
	int i;
 	// Libera la memoria per ogni riga della matrice
	i = 0;
	while (i < size)
		free(m[i++]);
	// Libera la memoria per la matrice stessa
	free(m);
	root->game->map = 0;
	// Libera la memoria per il file di input
	free(file);
	// Distruggi la struttura root e mostra un messaggio di errore
	root_destroy(root, "map_parsing(): malloc()", errno);
}
 /* Questa funzione ottiene le coordinate dei vari oggetti all'interno della mappa.
   Parametri:
   - root: puntatore alla struttura t_root
   - file: puntatore alla stringa contenente il file di input
   - k: indice corrente nel file di input
   - obj: puntatore all'indice degli oggetti */
static void	get_coord(t_root *root, char *file, int k, int *obj)
{
	// Se il carattere corrente è 'P', salva le coordinate del giocatore
	if (file[k] == 'P')
	{
		root->game->player.x = k % (root->game->width + 1);
		root->game->player.y = k / (root->game->width + 1);
		file[k] = '0';
	}
	// Se il carattere corrente è 'E', salva le coordinate dell'uscita
	else if (file[k] == 'E')
	{
		root->game->exit.x = k % (root->game->width + 1);
		root->game->exit.y = k / (root->game->width + 1);
		file[k] = '0';
	}
	// Se il carattere corrente è 'C', salva le coordinate di un muro
	else if (file[k] == 'C')
	{
		root->game->coll[*obj].x = k % (root->game->width + 1);
		root->game->coll[*obj].y = k / (root->game->width + 1);
		file[k] = '0';
		(*obj)++;
	}
}
 /* Questa funzione effettua il parsing del file di input e popola la struttura di gioco.
   Parametri:
   - root: puntatore alla struttura t_root
   - file: puntatore alla stringa contenente il file di input */
void	map_parsing(t_root *root, char *file)
{
	int i;
	int j;
	int k;
	int obj;
 	obj = 0;
	k = 0;
	j = -1;
	// Itera sulle righe della mappa
	while (++j < root->game->height)
	{
		// Alloca memoria per la riga corrente della mappa
		root->game->map[j] = (int *)malloc(sizeof(int) * root->game->width);
		// Verifica se l'allocazione di memoria è riuscita
		if (root->game->map[j] == 0)
			// Libera la memoria e mostra un messaggio di errore
			free_matrix(root, file, root->game->map, j);
		i = 0;
		// Itera sulle colonne della mappa
		while (i < root->game->width)
		{
			// Ottiene le coordinate degli oggetti e salva il valore nella mappa
			get_coord(root, file, k, &obj);
			root->game->map[j][i++] = file[k++] - 48;
		}
		// Salta il carattere di nuova riga
		k++;
	}
}