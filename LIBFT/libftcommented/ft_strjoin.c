/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:41:51 by pbie              #+#    #+#             */
/*   Updated: 2022/10/22 19:06:09 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Questa funzione alloca memoria e restituisce una nuova stringa terminata da '\0'
che è il risultato di una concatenazione dei parametri s1 e s2. Se 
l'allocazione non riesce la funzione restituirà NULL.*/

char		*ft_strjoin(char const *s1, char const *s2)
{
/*Iniziamo dichiarando tre variabili. I primi due saranno contatori noi
useremo per muoverci attraverso le nostre stringhe. Il terzo è la nuova stringa che
allocheremo la memoria per restituire la concatenazione di
le nostre stringhe di parametri.*/

	int		i;
	int		j;
	char	*str;

/*Impostiamo entrambe le variabili su 0 (all'inizio delle rispettive stringhe). 
Poi allochiamo la memoria usando la funzione malloc combinando le nostre funzioni ft_strlen 
precedentemente realizzate. Usiamo la funzione ft_strlen su entrambe le stringhe 
per calcolare la lunghezza completa della concatenazione e aggiungiamo 1 
per assicurarci di aggiungere una terminazione '\0'. 
Se l'allocazione fallisce, restituiremo NULL.*/
	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
/*Se l'allocazione funziona, iniziamo a concatenare le nostre stringhe.
Iniziamo con s1 con un ciclo di stringhe standard dicendo che finché noi
non hanno raggiunto la fine della stringa, deve continuare. 
Posizioniamo l'indice "i" sia della nostra nuova stringa str che del nostro parametro
Quindi percorriamo la lunghezza di s1 posizionando ciascun carattere
in s1 in str. Una volta terminato, continuiamo con il ciclo successivo.*/
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
/*Questo ciclo successivo è esattamente lo stesso del ciclo precedente
tranne che va considerato "j"(attualmente uguale a 0). 
Per la nostra nuova stringa str impostiamo l'indice
uguale al contatore precedente i più il nostro nuovo contatore j. 
Questo ci tiene la posizione dell'indice "i" alla fine del ciclo precedente 
più j. Usiamo j per impostare l'indice della nostra stringa s2 e facciamo il ciclo
fino a quando non abbiamo raggiunto la fine di s2. Una volta che la fine di s2 è stata
raggiunto aggiungiamo una terminazione '\0' alla fine della nostra nuova stringa e
restituamo la nuova stringa che è una nuova concatenazione dei nostri parametri.*/
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
