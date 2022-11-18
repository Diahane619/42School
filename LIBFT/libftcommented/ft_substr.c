/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 18:51:57 by pbie              #+#    #+#             */
/*   Updated: 2022/11/02 16:31:25 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Questa funzione alloca la memoria e restituisce una nuova copia di una porzione della stringa
 * passata nel parametro. La porzione inizia dall'indice del parametro
 * di start e avrà la lunghezza del parametro len. Se start e len non
 designano una porzione di stringa valida, il comportamento è indefinito. 
 Se l'allocazione della memoria fallisce, la funzione restituisce NULL.*/
char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
/*Iniziamo dichiarando due variabili. La prima, i, sarà il nostro contatore
* ed è un int senza segno per compensare l'eventualità di 
* stringa più lunga di quanto un int possa contare. Inoltre, 
dichiariamo un puntatore di tipo char str che conterrà la nostra stringa 
fresca che restituiremo.*/
	unsigned int	i;
	char			*str;

/*Imposteremo il nostro contatore a 0 perché lo confronteremo con len nella nostra
 * condizione del ciclo e presumiamo che len sia almeno 1. Quindi
 * allocare la memoria per la nostra stringa futura usando malloc. NOTA: stiamo
 * utilizzando la variabile len per la dimensione dell'allocazione di memoria e aggiungendovi
 * 1 ad essa in modo da creare uno spazio per terminare la nostra nuova stringa con '0'.
 * perché malloc prende la spaziatura letterale necessaria e le stringhe iniziano alla 
 * posizione 0. Controlliamo quindi che l'allocazione abbia funzionato. Se
 * non è riuscita, restituiamo NULL. In caso contrario, continuiamo il nostro ciclo.*/
 
	i = 0;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
/*Iniziamo il nostro ciclo impostando una condizione per cui il ciclo deve durare fino a quando
* il nostro contatore i è inferiore al parametro len. Se questa condizione è
* vera, prenderemo la stringa del parametro a partire dalla posizione dell'indice
* dato dal parametro start e vi aggiungeremo il valore corrente del nostro contatore i.
* del nostro contatore i, per spostarci lungo la stringa di parametri
* e inserire il carattere corrispondente nella nuova stringa. NOTA:
* utilizzando i per spostarsi lungo la stringa di parametri possiamo partire dalla posizione 0
* nella nostra nuova stringa e inserire il carattere all'indice di inizio desiderato
* della stringa s nello spazio allocato della nuova stringa. Una volta che il ciclo
* terminato, aggiungeremo un "0" finale alla nuova stringa e 
quindi la restituiremo.*/

	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
