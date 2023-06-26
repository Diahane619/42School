/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:23:15 by francevi          #+#    #+#             */
/*   Updated: 2023/06/26 11:23:27 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile char *g_bit_to_send = 0;

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

static void sen_message(pid_t server_pid, char *message)
{
	int sig = 0;
	size_t i, j;
	i = 0;
	while(i < ft_strlen(message))
	{
		encode_bits(message[i])
		j = 0;
		while(j < 8)
		{
			if(g_bit_to_send[j] == '1')
				sig = SIGUSR1;
			else
				sig = SIGUSR2;
			kill(server_pd, sig);
	}

}