/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:01:55 by francevi          #+#    #+#             */
/*   Updated: 2023/07/03 07:46:09 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile char	*g_received_bits = NULL;

static char	decode_bits(volatile char *bits)
{
	char	c = 0;
	size_t i = 0;

	while(i < 8)
	{
		if (bits[i] == '1')
			c |= (1 << i);
		i++;
	}
	return(c);
}

static void sig_handler(int sig)
{
	char	c;

	if (sig == SIGUSR1)
		g_received_bits = ft_char_append((char *)g_received_bits, '1', 1);
	else if (sig ==SIGUSR2)
		g_received_bits = ft_char_append((char *)g_received_bits, '0', 1);
	else
		exit(1);
	if(ft_strlen((char *)g_received_bits) == 8)
	{
		c = decode_bits(g_received_bits);
		write(1, &c, 1);
		ft_free((void **)&g_received_bits);
	}
}

int main(int ac, char **av)
{
	struct sigaction	act;

	(void)av;
	if(ac != 1)
		ft_exit("Troppi argomenti...\n", RED, 2, 1);
	ft_printf("%sServer PID ->%s%i%s\n", BLUE, GREEN, getpid(), RESET);
	while(true)
	{
		ft_bzero(&act, sizeof(act));
		act.sa_handler = &sig_handler;
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
	}
	return(0);
}