/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:35:43 by gamarcha          #+#    #+#             */
/*   Updated: 2023/07/11 14:13:31 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <mlx.h>
# include <mlx_int.h>
# include "libft.h"

// La struttura "t_coord" contiene le coordinate x e y di un punto nel gioco
typedef struct s_coord
{
	int				x;
	int				y;
}				t_coord;

// "t_game" contiene variabili che rappresentano lo stato del gioco, come la mappa, le dimensioni, 
// la posizione del giocatore, gli oggetti da raccogliere, etc.
typedef struct s_game
{
	int				**map;
	int				height;
	int				width;
	t_coord			player;
	int				player_up;
	int				player_down;
	int				player_left;
	int				player_right;
	int				player_move;
	int				player_coll;
	t_coord			exit;
	t_coord			*coll;
	int				count_coll;
	int				count_exit;
	int				count_player;
}				t_game;

/*"t_root", che rappresenta il contesto principale del gioco.
Contiene puntatori a diverse immagini utilizzate nel gioco, nonché puntatori a strutture come "t_game" e "t_img".*/
typedef struct s_root
{
	void			*mlx;
	void			*mlx_win;
	t_img			*mlx_img;
	t_game			*game;
	t_img			*player;
	t_img			*exit;
	t_img			*coll;
	t_img			*wall;
	t_img			*ground;
}				t_root;

/*Vengono dichiarate diverse funzioni utilizzate nel progetto, come "die" per gestire gli errori,
"draw" per disegnare gli elementi del gioco, "key_press" e "key_release" per gestire gli input da tastiera, etc.*/
void			die(char *errmsg, int errnum);
void			draw(t_root *root);
int				key_press(int keycode, t_root *root);
int				key_release(int keycode, t_root *root);
int				destroy_hook(int keycode, t_root *root);
void			game_destroy(t_game *game);
void			game_init(t_root *root, char *filename);
void			map_height(t_root *root, char *file);
void			map_init(t_root *root, char *filename);
void			map_isvalid(t_root *root, char *file);
void			map_parsing(t_root *root, char *file);
void			map_read(t_root *root, char *file);
void			map_width(t_root *root, char *file);
unsigned int	mlx_get_pixel(t_img *img, int x, int y);
void			mlx_draw_pixel(t_img *mlx_img, int x, int y, int color);
unsigned int	mlx_rgb_to_int(int o, int r, int g, int b);
void			move_up(t_root *root, int x, int y);
void			move_down(t_root *root, int x, int y);
void			move_left(t_root *root, int x, int y);
void			move_right(t_root *root, int x, int y);
void			root_destroy(t_root *root, char *errmsg, int errnum);

// Alla fine del file viene definito un prototipo per la funzione "root_init", che inizializza il contesto del gioco e restituisce un puntatore a "t_root"
t_root			*root_init(char *filename);
void			update(t_root *root);

#endif
