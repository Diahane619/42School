/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:23:15 by francevi          #+#    #+#             */
/*   Updated: 2023/07/03 07:46:12 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile char *g_bits_to_send = NULL;

static void	encode_bits(char c)
{
	size_t i = 0;
	while(i < 8)
	{
		if (c & (1 << i))
			g_bits_to_send = ft_char_append((char *)g_bits_to_send, '1', true);
		else
			g_bits_to_send = ft_char_append((char *)g_bits_to_send, '0', true);
		i++;
	}
}

static void send_message(pid_t server_pid, char *message)
{
	int sig;
	size_t i, j;
	sig = 0;
	i = 0;
	while(i < ft_strlen(message))
	{
		encode_bits(message[i]);
		j = 0;
		while(j < 8)
		{
			if (g_bits_to_send[j] == '1')
				sig = SIGUSR1;
			else
				sig = SIGUSR2;
			kill(server_pid, sig);
			usleep(50);
			j++;
		}
		ft_free((void **)&g_bits_to_send);
		i++;
	}
}

int main(int ac, char **av)
{
	if(ac != 3)
		ft_exit("Numero di argomenti errato...\n", RED_B, 2, 1);
	send_message(ft_atoi(av[1]), av[2]);
	return(0);
}