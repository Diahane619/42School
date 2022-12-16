/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:08:56 by francevi          #+#    #+#             */
/*   Updated: 2022/11/23 15:16:39 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!left_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i] != '\0')
			str[i] = left_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
	free(left_str);
	return (str);
}


/*
* ---------
* FT_PRENDIRIGA
* ---------
* Estrae la riga (che termina con un'interruzione di riga (`\n`) + (`\0`)) 
* dalla variabile statica.
* PARAMETRI
* #1. Il puntatore alla variabile statica cumulativa dalle esecuzioni precedenti di get_next_line.
* VALORI DI RITORNO
* La stringa con la riga completa che termina con un'interruzione di riga (`\n`) + (`\0`).
* -------------
*/

char	*ft_prendiriga(char *left_str)
{
	int		i;
	char	*str;

	i = 0; // inizializzo il contatore 
	if (!left_str[i]) // se la stringa non esiste ritorna NULL
		return (NULL);
	while (left_str[i] && left_str[i] != '\n') // fin quando non trova '\n' continua a scorrere
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2)); //alloco memoria al puntatore della stringa (+2 = (`\n`) + (`\0`))
	if (!str) // check malloc
		return (NULL);
	i = 0; //riporto il contatore della stringa a 0
	while (left_str[i] && left_str[i] != '\n') // fin quando non trova '\n' mi copia il contenuto della stringa
	{
		str[i] = left_str[i];
		i++;
	}
	if (left_str[i] == '\n') // Se trova '\n' continua a copiare
	{
		str[i] = left_str[i];
		i++;
	}
	str[i] = '\0'; // Se trova '\0'(fine) mi ritorna il puntatore alla stringa copiata
	return (str);
}

/*
* FT_RIMASTO
* -------------
* Memorizza nella variabile statica cumulativa la nuova variabile aggiornata con qualsiasi cosa
* viene lasciato dall'originale, meno la riga estratta.
* PARAMETRI
* #1. Il puntatore alla variabile statica cumulativa dalle esecuzioni precedenti di get_next_line.
* VALORI DI RITORNO
* La nuova stringa aggiornata con tutto ciò che è rimasto dallo statico originale, meno il
* riga estratta.
*/

char	*ft_rimasto(char *left_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0; // inizializzo il contatore
	while (left_str[i] && left_str[i] != '\n') // fin quando non trova '\n' continua a scorrere
		i++;
	if (!left_str[i]) // se la stringa non esiste liberamela e ritorna NULL
	{
		free(left_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(left_str) - i + 1)); //alloco memoria alla variabile statica per tutto il contenuto - la lunghezza della stringa precedente
	if (!str) //check malloc
		return (NULL);
	i++;
	j = 0; // inizializzo un nuovo contatore
	while (left_str[i]) // fin tanto che la stringa precedente esiste mi copi il suo contenuto nella variabile statica
		str[j++] = left_str[i++];
	str[j] = '\0'; // chiudo la nuova stringa e svuoto la variabile statica
	free(left_str); 
	return (str); // mi ritorna la nuova stringa aggiornata con tutto ciò che è rimasto dallo statico originale, meno il riga estratta.
}