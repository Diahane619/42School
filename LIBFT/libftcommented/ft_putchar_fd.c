/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 14:36:07 by pbie              #+#    #+#             */
/*   Updated: 2022/10/19 15:48:18 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Questa funzione è esattamente la stessa della nostra funzione ft_putchar tranne che questa
funzione richiede il descrittore di file  dovescrivere l'output come un parametro. 
Quindi, invece di scrivere automaticamente sullo standard output, noi
scegliamo di utilizzare un descrittore di file ottenuto dall'open chiamata di sistema, 
oppure usiamo 0(standard input), 1(standard output) o 2(errore standard)
Usiamo la funzione di scrittura come abbiamo fattonella funzione ft_putchar 
ma questa volta invece di avere il primo  parametro di scrittura essere un 1 per lo standard output 
prendiamo int fd come primo parametro per la scrittura. Usiamo ancora
l'indirizzo della nostra stringa di caratteri char c con terminazione nulla 
come contenuto per scrivere, sapendo che scriveremo solo un carattere all'interno 
del nostro descrittore di file desiderato. Utilizziamo poi 1 poiché scriveremo 1 byte.*/

void		ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
