/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:38:53 by gamarcha          #+#    #+#             */
/*   Updated: 2023/07/11 17:50:48 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/* Questa funzione restituisce il valore del pixel alle coordinate specificate all'interno dell'immagine.
   Parametri:
   - img: puntatore alla struttura t_img
   - x: coordinata x del pixel
   - y: coordinata y del pixel */
unsigned int	mlx_get_pixel(t_img *img, int x, int y)
{
	// Calcola l'indirizzo del pixel all'interno dei dati dell'immagine
	return (*(unsigned int *)(img->data + (x * img->bpp / 8 + y * img->size_line)));
}
 /* Questa funzione disegna un pixel dell'immagine alle coordinate specificate con il colore specificato.
   Parametri:
   - mlx_img: puntatore alla struttura t_img
   - x: coordinata x del pixel
   - y: coordinata y del pixel
   - color: colore del pixel */
void	mlx_draw_pixel(t_img *mlx_img, int x, int y, int color)
{
	// Calcola l'indirizzo del pixel all'interno dei dati dell'immagine
	char *target = mlx_img->data + (x * mlx_img->bpp / 8 + y * mlx_img->size_line);
	// Assegna il colore al pixel
	*(unsigned int *)target = color;
}
 /* Questa funzione converte i valori RGBA (opacità, rosso, verde, blu) in un valore intero rappresentante il colore.
   Parametri:
   - o: valore di opacità
   - r: valore rosso
   - g: valore verde
   - b: valore blu */
unsigned int	mlx_rgb_to_int(int o, int r, int g, int b)
{
	// Combina i valori RGBA in un unico valore intero
	return (o << 24 | r << 16 | g << 8 | b);
}