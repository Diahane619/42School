/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:34:33 by pbie              #+#    #+#             */
/*   Updated: 2015/11/26 16:43:00 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Secondo il manuale, la funzione memset scrive n byte di valore c
(convertito in un char senza segno) nella stringa b. 
Questa funzione restituisce il suo primo argomento, ovvero la stringa stessa.*/

void		*ft_memset(void *b, int c, size_t n)
{
/*Iniziamo creando una stringa char di p. Questo è ciò che useremo per tenere
una versione castata del nostro parametro void b. Impostiamo p uguale a una versione char cast di b.
Se non si ha familiarità con il type casting, si tratta di un modo per
convertire una variabile da un tipo di dati a un altro tipo di dati. Quindi
ft_memset deve fidarsi della dimensione di n che viene passata nel suo parametro e 
lavorare su una porzione generale di memoria, non solo su una stringa con terminazione '\0', 
quindi non possiamo avviare il nostro ciclo basandosi sulla solita idea che raggiungeremo la fine di una stringa.
In questo caso diciamo che finché il valore di n è maggiore di 0, continueremo il ciclo.
Quindi ci muoviamo all'indietro attraverso la stringa p inserendo l'int c in ogni posizione dell'indice. 
Facciamo n - 1 per compensare la fine "\0" della stringa che non vogliamo sostituire. 
Decrementiamo n e poi ricominciamo il ciclo fino a quando n non è più maggiore di 0.
A questo punto restituiamo b.*/
	char	*p;

	p = (char *)b;
	while (n > 0)
	{
		p[n - 1] = c;
		n--;
	}
	return (b);
}

#include <stdio.h>

void main()
{
	char b[10] = "diocane";

	char* d = ft_memset(b, '6', 3);

	printf("%s\n", d);
}