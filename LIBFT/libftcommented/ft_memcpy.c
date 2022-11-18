/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 17:04:45 by pbie              #+#    #+#             */
/*   Updated: 2015/12/07 22:21:33 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Secondo il manuale, questa funzione copia n byte dall'area di memoria src 
all'area di memoria dst.Se dst e src si sovrappongono, il comportamento è indefinito. 
Nei casi in cui dst e src potrebbero sovrapporsi si dovrebbe utilizzare 
ft_memmove. Questa funzione restituisce il valore originale di dst.*/

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
/*Iniziamo creando tre variabili. La prima sarà il nostro contatore che useremo
per eseguire il nostro ciclo e muoverci attraverso le posizioni dell'indice
di ogni stringa data. Poiché eseguiremo il nostro ciclo solo
finché siamo più piccoli della size_t n data, vogliamo assicurarci anche 
la nostra variabile contatore sia una size_t, in modo da poterla confrontare con n.
Poi creiamo due variabili puntatore a char. Impostiamo il nostro contatore a 0 e
trasformiamo le stringhe dei nostri parametri in puntatori a char e le collochiamo
all'interno delle nostre variabili puntatore a char d e s. 
Poi iniziamo il nostro ciclo.*/
	size_t	i;
	char	*d;
	char	*s;

	i = 0;
	d = (char *)dst;
	s = (char *)src;
/*Finché il nostro contatore i è più piccolo della size_t n data vogliamo che 
il nostro loop continui, poiché stiamo copiando n byte dall'area di memoria 
src all'area di memoria dst.
All'interno del nostro ciclo posizioniamo la posizione i dell'indice s 
(che attualmente contiene src) nell'indice dst.
Nella posizione i dell'indice d (che attualmente contiene l'area di memoria dst) 
incrementiamo il nostro i e continuiamo il ciclo fino a quando i non è p
iù piccolo di n. A questo punto restituiamo dst.*/
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}