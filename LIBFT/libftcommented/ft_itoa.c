/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:43:26 by pbie              #+#    #+#             */
/*   Updated: 2022/10/22 21:29:21 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Questa funzione alloca memoria e restituisce una stringa di caratteri "nuova"
che finisce con un '\0' ed è l'equivalente char dell'int passato come parametro. 
Anche i numeri negativi devono essere gestiti. Se l'assegnazione non riesce 
la funzione restituirà NULL. NOTA: questa è una funzione ricorsiva
(funzione che richiama se stessa al suo interno)*/

char		*ft_itoa(int n)
{
/*Iniziamo creando una variabile char string(il return della funzione). 
Quindi allochiamo memoria per la nostra variabile stringa str. NOTA:
Assegniamo memoria solo per una dimensione di 2 caratteri, perché
usiamo la ricorsiva e vogliamo allocare memoria solo quando ne abbiamo bisogno. 
Facciamo una dimensione di 2 nella nostra funzione malloc perché vogliamo 
un carattere alla volta dal dato int n (1 x la cifra convertita in carattere, 2 x lo "/0"). 
Dobbiamo completare la stringa di quel singolo carattere.Se l'assegnazione non riesce restituiamo NULL. 
Vogliamo anche assicurarci di restituire una stringa se l'int passato da noi 
equivale al numero intero più piccolo possibile (-2147483648)*/
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(str, "-2147483648"));

/*Successivamente vogliamo vedere se l'int che viene passato nel nostro parametro è a
numero negativo. Se int n è minore di zero, facciamo il refresh della nostra stringa
(nella prima casella 0 un segno negativo e nella casella 1 lo '\0'). 
Quindi impostiamo la stringa str uguale a ft_strjoin con il nostro str come parametro e 
chiamiamo ricorsivamente la nostra funzione con -n per trasformare l'int negativo in un positivo. 
Quindi ricominciamo la funzione ancora.*/

	if (n < 0)
	{
		str[0] = '-';
		str[1] = '\0';
		str = ft_strjoin(str, ft_itoa(-n));
	}
	/*Di seguito diciamo che se l'int n passato nel nostro parametro è maggiore di
	 10, vogliamo scomporlo in modo ricorsivo, in modo da poterlo ricostruire come
	 come stringa. Lo facciamo impostando la nostra stringa allocata in memoria str
	 uguale alla nostra funzione ft_strjoin precedentemente creata e gli passiamo il
	 il parametro della nostra funzione ft_itoa con n diviso 10 e della nostra funzione ft_itoa con n modulo 10.
	 funzione con n modulo 10. Qui è dove l'idea di come funziona la ricorsione
	 funziona può essere difficile da capire. Questo uso di ft_strjoin non avverrà
	 solo in un secondo momento, perché chiameremo di nuovo ft_itoa. Questo dividerà il nostro
	 dato int per 10 e prenderà il risultato per ricominciare la funzione,
	 dividendola costantemente fino a quando non avremo il primo numero nell'int
	 int. Ad esempio, se abbiamo iniziato con il numero n = 123, la chiamata di
	 ft_itoa(n / 10) e ft_itoa(n % 10) è in realtà ft_itoa(123 / 10) e
	 ft_itoa(123 % 10). Questo chiamerà ft_itoa su un valore di 12 per la divisione per 10 e chiamerà ft_itoa(123).
	 divisione per 10 e chiama ft_itoa sul valore 3 per il nostro modulo 10.
	 In questo modo scomponiamo il numero in singole cifre. Per il nostro
	 risultato di 3, la funzione ricomincerà da capo e salterà questa sezione.
	 poiché ora sarà un valore inferiore a 10. Nel prossimo
	 else if che se il numero è maggiore di 0 e minore di 10
	 lo convertiamo qui in una stringa indiviuale che sarebbe "3\0" perché
	 dobbiamo avere un "0" finale. Questa stringa individuale sarà
	 restituita alla funzione ft_strjoin in cui è stata chiamata per essere unita
	 con la stringa che verrà restituita dal suo parametro compagno. Ma cosa
	 è successo alla ft_itoa(123 / 10)? Beh, ci ha dato il numero
	 12 da inserire in questa funzione ft_itoa. Poiché questo numero è ancora maggiore
	 di 10, useremo l'istruzione if che utilizzerà ft_strjoin con le
	 due funzioni ft_itoa passate nei suoi parametri, ma questa volta sul valore
	 valore di 12. Come è successo in precedenza con il valore intero di 123, ora
	 dividere questo 12 in un singolo 1 e 2. Eseguire ft_itoa su
	 ogni singolo numero. Dal momento che entrambi i numeri hanno un valore inferiore a 10 ma
	 maggiore di 0, li convertiremo in una stringa. Quindi a questo punto
	 abbiamo ora le stringhe "1\0", "2\0", e dalla nostra precedente chiamata di
	 ft_itoa(123 % 10) abbiamo la stringa "3\0". Poiché abbiamo raggiunto un punto di
	 punto di ritorno per la nostra ricorsione, combineremo prima le stringhe
	 "1\0" e "2\0" all'interno della funzione ft_strjoin in cui si trovano al momento
	 trasformandole nella stringa "12\0". Questo ci porta indietro di un livello nella
	 la nostra ricorsione per unire ora "12\0" con la stringa "3\0", ottenendo la stringa
	 "123\0". Poiché questa stringa è stata inserita nella nostra stringa str 
	 (NOTA: abbiamo allocato memoria per ogni stringa a ogni chiamata di ft_itoa nella nostra ricorsione)
	 possiamo restituirlo ora che l'intero numero è stato convertito in una stringa di caratteri. 
	 Termina così la nostra funzione. Se questo è stato difficile da immaginare nella vostra testa,
	 provate a ripercorrere la funzione su un foglio di carta. Dovrebbe essere una specie di albero binario.*/
	else if (n >= 10)
		str = ft_strjoin(ft_itoa(n / 10), ft_itoa(n % 10));
	else if (n < 10 && n >= 0)
	{
		str[0] = n + '0';
		str[1] = '\0';
	}
	return (str);
}

#include <stdio.h>

void main()
{
	int	s = -895314;
	char	*d;

	d = ft_itoa(s);

	printf("%s\n", d);
}