/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftminitalk.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:56:29 by iragusa           #+#    #+#             */
/*   Updated: 2023/04/01 16:37:07 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTMINITALK_H
# define LIBFTMINITALK_H
# include <signal.h>
# include	"libft/libft.h"

typedef struct s_info
{
	char	c;
	int		i;
	int		check;
	int		pid_client;
}	t_info;

void	action(int signum);
void	ft_send_msg(int pid, char *msg);
void	sighandler(int signum);
#endif
