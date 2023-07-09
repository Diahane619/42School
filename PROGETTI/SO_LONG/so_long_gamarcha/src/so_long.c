/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:36:29 by gamarcha          #+#    #+#             */
/*   Updated: 2023/07/09 16:51:41 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Questo codice è un esempio di un programma che utilizza la libreria "so_long.h".
Il programma verifica se il secondo argomento passato da linea di comando ha l'estensione ".ber" 
e se il numero di argomenti è corretto. In caso contrario, viene chiamata la funzione "die" 
per gestire l'errore. Successivamente, viene inizializzata una struttura "t_root" 
chiamata "root" utilizzando il secondo argomento come parametro. Viene quindi chiamata la funzione "draw" 
per disegnare qualcosa utilizzando la struttura "root". Infine, vengono impostati degli hook 
per gestire gli eventi della finestra e viene avviato il loop di rendering con la funzione "mlx_loop". */
 #include "so_long.h"
 // Verifica se il file ha l'estensione ".ber"
int isber(char *file)
{
	int len;
 	len = ft_strlen(file);
	if (file == 0)
		return (0);
	if (len < 5)
		return (0);
	if (ft_strcmp(file + len - 4, ".ber") != 0)
		return (0);
	return (1);
}
 // Funzione principale del programma
int main(int ac, char *av[])
{
	t_root *root;
 	// Verifica se il numero di argomenti è diverso da 2 e gestisce l'errore in caso contrario
	if (ac != 2)
		die("invalid number of arguments", 0);
 	// Verifica se il secondo argomento non ha l'estensione ".ber" e gestisce l'errore in caso contrario
	if (isber(av[1]) == 0)
		die("invalid argument (<name>.ber)", 0);
 	// Inizializza la struttura "root" utilizzando il secondo argomento come parametro
	root = root_init(av[1]);
 	// Chiama la funzione "draw" per disegnare qualcosa utilizzando la struttura "root"
	draw(root);
 	// Imposta hook per gestire gli eventi della finestra
	mlx_hook(root->mlx_win, 2, 1L << 0, key_press, root);
	mlx_hook(root->mlx_win, 3, 1L << 1, key_release, root);
	mlx_hook(root->mlx_win, 17, 1L << 17, destroy_hook, root);
 	// Avvia il loop di rendering
	mlx_loop(root->mlx);
 	return (0);
}