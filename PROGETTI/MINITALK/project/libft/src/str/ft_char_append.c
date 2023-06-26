/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_append.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:48:02 by francevi          #+#    #+#             */
/*   Updated: 2023/06/26 10:55:46 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Questa funzione aggiunge un carattere alla fine di una stringa di caratteri.
   Se la stringa non esiste, viene creata una nuova stringa contenente solo il carattere.
   La funzione restituisce la nuova stringa risultante. Se l'argomento "to_free" è true,
   la funzione libera la memoria della stringa originale. */
char *ft_char_append(char *s, char c, bool to_free)
{
	size_t	i;
	char	*str;
 	if (!s) // se la stringa non esiste
	{
		str = (char *)malloc(sizeof(char) * 2); // alloca memoria per una nuova stringa di 2 caratteri
		if (!str)
			return (0); // se la memoria non può essere allocata, restituisce null
		str[0] = c; // assegna il carattere alla prima posizione della nuova stringa
		str[1] = 0; // aggiunge il terminatore di stringa
		return (str); // restituisce la nuova stringa
	}
	i = 0;
	while (s[i]) // trova la lunghezza della stringa originale
		i++;
	str = (char *)malloc(sizeof(char) * ++i + 1); // alloca memoria per una nuova stringa di una posizione in più della stringa originale
	if (!str)
		return (0); // se la memoria non può essere allocata, restituisce null
	str[i - 1] = c; // assegna il carattere alla fine della nuova stringa
	str[i--] = 0; // aggiunge il terminatore di stringa
	while (i--) // copia la stringa originale nella nuova stringa
		str[i] = s[i];
	if (to_free && s) // se l'argomento "to_free" è true e la stringa originale esiste
		ft_free((void **)&s); // libera la memoria della stringa originale
	return (str); // restituisce la nuova stringa
}