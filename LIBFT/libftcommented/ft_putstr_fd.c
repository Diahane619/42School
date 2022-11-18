/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 14:37:12 by pbie              #+#    #+#             */
/*   Updated: 2022/10/19 15:52:51 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Questa funzione è esattamente la stessa della nostra funzione ft_putstr 
tranne per il fatto che noi richiedono un descrittore di file nel parametro insieme 
a quello desiderato stringa da scrivere. Come facciamo nella nostra funzione 
ft_putchar_fd, utilizziamo un descrittore di file fd come primo parametro 
nella nostra funzione di scrittura. Posizioniamo la nostra stringa come parametro 
successivo di scrittura. Infine usiamo ft_strlen sul nostro stringa così 
sappiamo quanti byte dovranno essere scritti, che è lo stesso come 
la lunghezza della stringa data. Write scriverà quindi la stringa s 
nel file output desiderato.*/

void		ft_putstr_fd(char const *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
