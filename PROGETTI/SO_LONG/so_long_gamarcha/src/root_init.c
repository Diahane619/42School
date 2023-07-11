/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   root_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 03:51:29 by gamarcha          #+#    #+#             */
/*   Updated: 2021/06/13 03:51:29 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/* La funzione texture_load() carica un'immagine da un file XPM utilizzando la libreria mlx.
Prende come argomenti un puntatore a una struttura t_img, un puntatore a un percorso di file e restituisce void. */
static void	texture_load(t_root *root, t_img **img, char *path)
{
    int width;
    int height;
     *img = mlx_xpm_file_to_image(root->mlx, path, &width, &height); // Carica l'immagine dal file utilizzando mlx_xpm_file_to_image()
    if (*img == 0) // Se l'immagine non viene caricata correttamente, termina il programma con un messaggio di errore
        root_destroy(0, "texture_init(): can't load texture", 0);
    (*img)->width = width; // Imposta la larghezza dell'immagine nella struttura t_img
    (*img)->height = height; // Imposta l'altezza dell'immagine nella struttura t_img
}
 /* La funzione texture_init() inizializza le texture del gioco richiamando la funzione texture_load() per ogni texture. 
 Prende come argomento un puntatore a una struttura t_root e restituisce void. */
static void	texture_init(t_root *root)
{
    texture_load(root, &root->player, "./img/player.xpm"); // Carica la texture del giocatore
    texture_load(root, &root->exit, "./img/helicopter.xpm"); // Carica la texture dell'uscita
    texture_load(root, &root->coll, "./img/gas.xpm"); // Carica la texture del collezionabile
    texture_load(root, &root->wall, "./img/wall.xpm"); // Carica la texture del muro
    texture_load(root, &root->ground, "./img/sand.xpm"); // Carica la texture del terreno
}
 /* La funzione renderer_init() inizializza il renderer del gioco utilizzando la libreria mlx.
 Prende come argomento un puntatore a una struttura t_root e restituisce void. */
static void	renderer_init(t_root *root)
{
    root->mlx = mlx_init(); // Inizializza la connessione con il server grafico utilizzando mlx_init()
    if (root->mlx == 0) // Se la connessione non viene stabilita correttamente, termina il programma con un messaggio di errore
        root_destroy(root, "mlx_init(): can't load mlx", 0);
    root->mlx_win = mlx_new_window(root->mlx, root->game->width * 40, root->game->height * 40, "so_long"); // Crea una nuova finestra utilizzando mlx_new_window()
    if (root->mlx_win == 0) // Se la finestra non viene creata correttamente, termina il programma con un messaggio di errore
        root_destroy(root, "mlx_new_window(): can't create a window", 0);
    root->mlx_img = mlx_new_image(root->mlx, root->game->width * 40, root->game->height * 40); // Crea una nuova immagine utilizzando mlx_new_image()
    if (root->mlx_img == 0) // Se l'immagine non viene creata correttamente, termina il programma con un messaggio di errore
        root_destroy(root, "mlx_new_image(): can't create an image", 0);
}
 /* La funzione root_init() inizializza la struttura t_root del gioco, alloca memoria per essa e richiama altre funzioni di inizializzazione.
 Prende come argomento una stringa che rappresenta il nome del file e restituisce un puntatore a una struttura t_root. */
t_root	*root_init(char *filename)
{
    t_root *root;
     root = (t_root *)malloc(sizeof(t_root)); // Alloca memoria per la struttura t_root
    if (root == 0) // Se l'allocazione di memoria fallisce, termina il programma con un messaggio di errore
        root_destroy(0, "root_init(): malloc()", errno);
    root->game = 0; // Inizializza il puntatore alla struttura t_game a 0
    root->mlx = 0; // Inizializza il puntatore alla connessione grafica a 0
    root->mlx_win = 0; // Inizializza il puntatore alla finestra a 0
    root->mlx_img = 0; // Inizializza il puntatore all'immagine a 0
    root->player = 0; // Inizializza il puntatore alla texture del giocatore a 0
    root->exit = 0; // Inizializza il puntatore alla texture dell'uscita a 0
    root->coll = 0; // Inizializza il puntatore alla texture del collezionabile a 0
    root->wall = 0; // Inizializza il puntatore alla texture del muro a 0
    root->ground = 0; // Inizializza il puntatore alla texture del terreno a 0
    game_init(root, filename); // Richiama la funzione game_init() per inizializzare la struttura t_game
    renderer_init(root); // Richiama la funzione renderer_init() per inizializzare il renderer
    texture_init(root); // Richiama la funzione texture_init() per inizializzare le texture
    return (root); // Restituisce il puntatore alla struttura t_root inizializzata
}