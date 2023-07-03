/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:41:28 by francevi          #+#    #+#             */
/*   Updated: 2023/07/03 07:40:51 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_exit(char *msg, char *color, int fd, int exit_code)
{
	if (color)
		write(fd, color, ft_strlen(color));
	write(fd, msg, ft_strlen(msg));
	if (color)
		write(fd, RESET, ft_strlen(RESET));
	exit(exit_code);
}