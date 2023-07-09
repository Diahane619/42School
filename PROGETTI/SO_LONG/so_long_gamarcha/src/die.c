/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 04:20:06 by gamarcha          #+#    #+#             */
/*   Updated: 2021/06/13 04:20:06 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* La funzione "die" viene utilizzata per gestire gli errori nel programma. Prende due argomenti: "errmsg",
 una stringa che rappresenta un messaggio di errore personalizzato, e "errnum", un numero che rappresenta un codice di errore. */
 void die(char *errmsg, int errnum)
{
	// Se sia il messaggio di errore che il codice di errore sono presenti, stampa la stringa "Error" sul file di output con il numero 2 (stderr)
	if (errmsg != 0 || errnum != 0)
		ft_putendl_fd("Error", 2);
 	// Se è presente un messaggio di errore, stampa il messaggio di errore sullo stesso file di output
	if (errmsg != 0)
		ft_putstr_fd(errmsg, 2);
 	// Se sia il messaggio di errore che il codice di errore sono presenti, stampa il carattere ":" sullo stesso file di output
	if (errmsg != 0 && errnum != 0)
		ft_putstr_fd(": ", 2);
 	// Se è presente un codice di errore, stampa il messaggio di errore corrispondente al codice tramite la funzione "strerror"
	if (errnum != 0)
		ft_putstr_fd(strerror(errnum), 2);
 	// Se sia il messaggio di errore che il codice di errore sono presenti, stampa un carattere di nuova linea vuoto sul file di output con il numero 2
	if (errmsg != 0 || errnum != 0)
	{
		ft_putendl_fd("", 2);
		exit(1); // Termina l'esecuzione del programma con un codice di uscita 1
	}
 	exit(0); // Termina l'esecuzione del programma con un codice di uscita 0
}