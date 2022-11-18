/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 17:23:50 by pbie              #+#    #+#             */
/*   Updated: 2022/10/23 18:24:51 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Secondo il man questa funzione individua la prima occorrenza di c (convertita
 in un carattere unsigned) nella stringa s. ft_memchr restituisce un puntatore al byte
 localizzato o NULL se non esiste alcun byte di questo tipo all'interno di n byte.*/

void		*ft_memchr(const void *s, int c, size_t n)
{
/*Iniziamo creando un puntatore char *str in cui inseriremo un cast del nostro 
parametro s. Creiamo anche una variabile size_t per usarla come contatore. 
Facciamo size_t per confrontarlo con size_t n nel ciclo. Inizializzamo a 0
anche per iniziare all'inizio della nostra stringa str. Lanciamo s
come puntatore char e posizioniamolo all'interno della nostra variabile str. 
Entriamo quindi nel nostro ciclo.*/
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)s;
/*Mentre la nostra variabile i è minore del parametro n il nostro ciclo continua.
All'interno vogliamo vedere se l'attuale posizione dell'indice castato come 
unsigned char è uguale al parametro c anche questo castato con unsigned char. 
Se questa affermazione è vera, restituiremo un puntatore castato di caratteri che parte da c
e arriva alla fine della stringa. Se i non è più inferiore a n e non abbiamo 
ancora individuato c, restituisce NULL.*/
	while (i < n)
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
#include <stdio.h>

void main()
{
	const char *s = "porco cazzo";
	int	c = 'c';
	char *d;

	d = ft_memchr(s, c, 7);

	printf("%s\n", d);
}