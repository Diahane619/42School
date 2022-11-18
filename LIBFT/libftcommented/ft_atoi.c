/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:01:57 by pbie              #+#    #+#             */
/*   Updated: 2022/10/23 18:37:53 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Questa è una ricreazione della funzione atoi in C. Prendiamo una stringa di
caratteri che poi convertiremo in un int."La funzione atoi converte la parte 
iniziale di una stringa che punta da str a int"*/

int			ft_atoi(const char *str)
{
/*Iniziamo creando tre variabili. 
"Res" = il nostro risultato che deve essere restituito. Usiamo long perché è deve 
essere in grado di memorizzare, come minimo, valori che si trovano all'interno 
dell'intervallo -2147483647 e 2147483647. 
"Sign" = per trasformare l'int negativo nel caso in cui sia un numero negativo 
che viene inserito nel corda. Usiamo long in modo da potelo moltoplicare con il
res. 
"i" = il contatore della nostra stringa. Usiamo unint senza segno per poter 
utilizzare il suo intervallo positivo esteso ha più di un int. 
Li imposteremo tutti a 0 tranne il nostro sign che impostiamo a 1 in modo 
da utilizzarlo nella moltiplicazione per la nostra stringa*/
	long			res;
	long			sign;
	unsigned int	i;

	res = 0;
	sign = 1;
	i = 0;
/* Adesso dobbiamo assicurarci di saltare qualsiasi tipo di spaziatura che 
potrebbe essere trovata all'inizio della stringa.*/
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
		str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
/*Adesso verifichiamo se è presente un simbolo negativo all'inizio del numero 
che convertiremo. se vediamo un simbolo negativo o positivo ci regoliamo di 
conseguenza. Se è negativo impostiamo il nostro segno uguale a -1 
per moltiplicare il nostro risultato quando lo restituiamo.*/
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
/*Qui convertiamo la nostra stringa di caratteri da char a int purché siano numeri. 
Se il carattere su cui ci troviamo attualmente è un numero, lo convertiamo nel suo valore numerico ascii.
Per il primo carattere ris è impostato attualmente a 0. Moltiplichiamo per 10 il nostro res in modo da posizionarlo e 
sottraiamo il valore numerico del carattere 0 sulla tabella ascii dal nostro attuale
numero di carattere. Questo lo imposta al suo valore numerico ascii. Continuiamo il nostro ciclo 
fino a quando non troviamo un carattere che non sia un numero*/
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
/*Infine restituamo il valore res moltiplicato per il valore del segno per restituire 
il numero a seconda che fosse negativo o meno. NOTA: int tra parentesi per 
eseguire il cast in modo che possa essere restituito come un int.*/
	return ((int)(res * sign));
}

#include <stdio.h>

void main()
{
	const char *s = "-895314";
	int 	d;

	d = ft_atoi(s);

	printf("%d\n", d);
}
