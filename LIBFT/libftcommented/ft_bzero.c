/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:46:03 by pbie              #+#    #+#             */
/*   Updated: 2022/10/23 18:46:33 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Secondo il man questa funzione scrive n byte azzerati nella stringa s. Se
 n è zero, ft_bzero non fa nulla.Usiamo la nostra funzione ft_memset precedentemente 
 creata per farlo. Impostiamo void per riempire qualsiasi tipo di stringa di dimensione n con 0.*/

void		ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

#include <stdio.h>

void main()
{
	void *s = "diocane";

	ft_bzero(s, 8);
	printf("%s\n", s);
}