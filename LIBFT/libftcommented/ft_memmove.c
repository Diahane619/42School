/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 17:11:32 by pbie              #+#    #+#             */
/*   Updated: 2015/12/07 22:44:13 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Secondo il manuale, questa funzione copia n byte dalla stringa src alla stringa
 dst. Le due stringhe possono sovrapporsi; la copia avviene sempre in modo 
 non distruttivo. La funzione ft_memmove restituisce il valore originale di
 dst.*/

void	*ft_memmove(void *dst, const void *src, size_t n)
{
/*Iniziamo creando una variabile puntatore char tmp che utilizzeremo come
contenitore temporaneo per copiare i byte da src a dst, utilizzando la funzione 
ft_memcpy. Ma prima di fare questo dobbiamo assicurarci di allocare la memoria 
per tmp in modo che sia in grado di contenere i byte di src per spostarli in dst. 
Utilizziamo il parametro len per determinare la dimensione della malloc per tmp. 
Se l'allocazione fallisce, restituiamo NULL. 
In caso contrario, si procederà con ft_memcpy prima su tmp, src e n, 
e poi lo richiamiamo su dst, tmp e n. Una volta terminato il nostro spostamento 
di memoria, libereremo la memoria allocata per tmp. 
E infine restituiremo il valore originale di dst.*/
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * n);
	if (tmp == NULL)
		return (NULL);
	ft_memcpy(tmp, src, n);
	ft_memcpy(dst, tmp, n);
	free(tmp);
	return (dst);
}

#include <stdio.h>

void main()
{
	void *s1;
	const void *s2 = "diomerda";

	char *dhn = (char *)ft_memmove(s1, s2, 10);

	printf("%s\n", dhn);
}