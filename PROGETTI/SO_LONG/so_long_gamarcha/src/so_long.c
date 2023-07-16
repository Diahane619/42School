/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:36:29 by gamarcha          #+#    #+#             */
/*   Updated: 2023/07/13 11:19:00 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "so_long.h"

/* La funzione isber() controlla se il nome del file termina con l'estensione ".ber". Restituisce 1 se l'estensione è corretta, altrimenti restituisce 0. */
 int isber(char *file)
{
	int len;
 	len = ft_strlen(file); // Ottiene la lunghezza della stringa file
	if (file == 0) // Se il puntatore a file è nullo, restituisce 0
		return (0);
	if (len < 5) // Se la lunghezza della stringa è inferiore a 5 (minimo per ".ber"), restituisce 0
		return (0);
	if (ft_strcmp(file + len - 4, ".ber") != 0) // Confronta gli ultimi 4 caratteri della stringa con ".ber". Se non corrispondono, restituisce 0
		return (0);
	return (1); // Se tutte le condizioni sono soddisfatte, restituisce 1
}
/* La funzione main() è la funzione principale del programma. 
Controlla il numero di argomenti passati al programma e se l'argomento è un file valido con estensione ".ber".
Inizializza la struttura root, disegna il contenuto del file e imposta i gestori degli eventi. Infine, avvia la loop di rendering. */
 int main(int ac, char *av[])
{
	t_root *root;
	
 	if (ac != 2) // Se il numero di argomenti non è 2, mostra un messaggio di errore e termina il programma
		die("Numero di argomenti non validi", 0);
	if (isber(av[1]) == 0) // Se il file passato come argomento non ha estensione ".ber", mostra un messaggio di errore e termina il programma
		die("Argomento non valido (<nome>.ber)", 0);
	
	root = root_init(av[1]); // Inizializza la struttura root con il file passato come argomento
	draw(root); // Disegna il contenuto del file sulla finestra
	mlx_hook(root->mlx_win, 2, 1L << 0, key_press, root); // Imposta il gestore dell'evento di pressione dei tasti
	mlx_hook(root->mlx_win, 3, 1L << 1, key_release, root); // Imposta il gestore dell'evento di rilascio dei tasti
	mlx_hook(root->mlx_win, 17, 1L << 17, destroy_hook, root); // Imposta il gestore dell'evento di chiusura della finestra
	mlx_loop(root->mlx); // Avvia la loop di rendering
 	return (0); // Termina il programma
}