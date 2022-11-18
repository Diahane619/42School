/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:21:12 by pbie              #+#    #+#             */
/*   Updated: 2022/10/23 18:24:49 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Secondo il man questa funzione confronta la stringa di byte s1 con la stringa di byte
 * s2. Si presume che entrambe le stringhe siano lunghe n byte. La funzione ft_memcmp
 * restituisce zero se le due stringhe sono identiche, altrimenti restituisce la
 * la differenza tra i primi due byte che differiscono (trattati come valori di char senza segno, quindi '\\code(0144)*)).
 * valori, in modo che '\200' sia maggiore di '\0', ad esempio). Le stringhe a lunghezza zero sono sempre identiche.*/


int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	/*Iniziamo con la creazione di due variabili puntatore char, all'interno delle quali collocheremo
	 le versioni castate in char dei nostri parametri s1 e s2. Creiamo anche
	 una variabile size_t i per contare le posizioni di indice di str1 e str2 e usarla
	 per il confronto con il parametro s1 e s2.
	 Impostiamo i uguale a 0 e inseriamo le versioni castate di s1 e
	 s2 in str1 e str2. Avviamo quindi il nostro ciclo.*/

	char	*str1;
	char	*str2;
	size_t	i;

	i = 0;
	str1 = (char *)s1;
	str2 = (char *)s2;
/*Finché i è inferiore a n, il ciclo deve continuare.
Ma se in un qualsiasi momento prima di allora, e se raggiungiamo una posizione dell'indice in cui
il carattere in str1 non è lo stesso di str2, vogliamo immediatamente
restituire la differenza in byte tra i due diversi char unsigned castati.
Se i raggiunge il punto in cui non è più inferiore a n e non abbiamo ancora trovato alcun byte diverso,
restituiremo uno 0 per dire che entrambe le stringhe di byte sono uguali.*/
	while (i < n)
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}

#include <stdio.h>

void main()
{
	const void* s1 = "diomerda";
	const void* s2 = "diomerdb";

		printf("%d\n", ft_memcmp(s1, s2, 8));
}