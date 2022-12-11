/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:49:31 by francevi          #+#    #+#             */
/*   Updated: 2022/12/11 16:49:31 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...) // Il format rappresenta tutto il contenuto tra i doppi apici del 
                                       // printf e (...) sono i vari parametri (variabili int, char, str) associati ai relativi placeholder(%d, %c, %s)
{
	int	i; // contatore di format
	int	len; // lunghezza totale di format
	int	res; // il risultato finale del printf (il format dopo le tutte le conversioni dei formati) 
	va_list args; // dichiarazione del numero di argomenti per la funzione variadica 

	va_start (args, format) // faccio partire la funzione variadica passondogli gli argomenti (che varieranno) e il contenuto (format) 
	i = 0; //inizializzo il contatore
	res = 0;
	len = ft_strlen(format);
	while (format[i] && i < len) // fintanto che il contenuto esiste e il contatore i non raggiunge la fine
	{
		if (format[i] != '%') // se non incontra il %
			ft_putchar(format[i++], &res); // stampa e vammi avanti
		else
		{	
			i += 1; // vado al carattere dopo il %
			ft_placeholder(args, format, &res, &i); // controlla il tipo di placeholder(%cdiusxXp) e lo rimpiazza con il valore degli args 
		}
	}
	va_end (args); // chiude la variadica
	return (res); // ritorna il risultato finale
}
