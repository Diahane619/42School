/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:49:32 by rel-fila          #+#    #+#             */
/*   Updated: 2022/11/20 17:15:38 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print(va_list args, const char *format, int *count, int *i)
{
	if (format[*i] == '%')
		ft_putchar(format[*i], count);
	else if (format[*i] == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (format[*i] == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (format[*i] == 'd' || format[*i] == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (format[*i] == 'u')
		ft_putunbr(va_arg(args, unsigned int), count);
	else if (format[*i] == 'x')
		ft_puthex(va_arg(args, unsigned int), count);
	else if (format[*i] == 'X')
		ft_putuphex(va_arg(args, unsigned int), count);
	else if (format[*i] == 'p')
		ft_putpointer(va_arg(args, void *), count);
	*i += 1;
}


int ft_printf(const char *format, ...) // Il format rappresenta tutto il contenuto tra i doppi apici del 
                                       // printf e (...) sono i vari parametri (variabili int, char, str) associati ai relativi placeholder(%d, %c, %s)
{
	int	i; // contatore di format
	int	len; // lunghezza totale di format
	int	count; // il risultato finale del printf (il format dopo le tutte le conversioni dei formati) 
	va_list args; // dichiarazione del numero di argomenti per la funzione variadica 

	va_start (args, format); // faccio partire la funzione variadica passondogli gli argomenti (che varieranno) e il contenuto (format) 
	i = 0; //inizializzo il contatore
	count = 0;
	len = ft_strlen(format);
	while (format[i] && i < len) // fintanto che il contenuto esiste e il contatore i non raggiunge la fine
	{
		if (format[i] != '%') // se non incontra il %
			ft_putchar(format[i++], &count); // stampa e vammi avanti
		else
		{	
			i += 1; // vado al carattere dopo il %
			ft_placeholder(args, format, &count, &i); // controlla il tipo di placeholder(%cdiusxXp) e lo rimpiazza con il valore degli args 
		}
	}
	va_end (args); // chiude la variadica
	return (count); // ritorna il numero dei caratteri stampati
}