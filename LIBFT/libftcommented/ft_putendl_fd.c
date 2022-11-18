/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 14:42:13 by pbie              #+#    #+#             */
/*   Updated: 2022/10/19 15:54:27 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Questa funzione scrive la stringa s nel descrittore di file fd seguita da a
'\n' per creare una nuova riga. Questa funzione è esattamente la stessa del nostro ft_putendl
funzione tranne per il fatto che prendiamo un parametro per il descrittore di file. Noi
usa le nostre funzioni ft_putstr_fd e ft_putchar_fd per far funzionare questa funzione.*/

void		ft_putendl_fd(char const *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
