/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:22:53 by kichkiro          #+#    #+#             */
/*   Updated: 2023/04/06 22:46:41 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

/* Dichiarazione della variabile globale "g_bits_to_send" di tipo "char" */
volatile char	*g_bits_to_send = 0;
 /**
 * @brief 
	La funzione codifica un carattere in 8 bit e li aggiunge ad un array di caratteri globale.
 * @details 
	La funzione prende un carattere e lo codifica in 8 bit, che vengono poi aggiunti ad un array di caratteri globale, g_bits_to_send;
	Se il bit è 1, viene aggiunto '1' all'array, altrimenti viene aggiunto '0' all'array.
 * @param c 
 	Il carattere da codificare.
 */
static void	encode_bits(char c)
{
	size_t	i;
 	/* Inizializzazione della variabile "i" a 0 */
	i = 0;
	while (i < 8)
	{
		/* Se il bit i-esimo del carattere "c" è 1, viene aggiunto '1' all'array "g_bits_to_send", altrimenti viene aggiunto '0' */
		if (c & (1 << i))
			g_bits_to_send = ft_char_append((char *)g_bits_to_send, '1', true);
		else
			g_bits_to_send = ft_char_append((char *)g_bits_to_send, '0', true);
		i++;
	}
}
 /**
 * @brief 
	Invia un messaggio ad un processo server.
 * @details 
	La funzione prende l'ID di un processo server ed una stringa di messaggio, codifica ogni carattere del messaggio in bit e invia i bit al processo server utilizzando i segnali SIGUSR1 e SIGUSR2;
	Ogni bit viene inviato come segnale, con un ritardo di 50 microsecondi tra ogni segnale.
 * @param server_pid 
	L'ID del processo server.
 * @param message 
	La stringa di messaggio da inviare al processo server.
 */
static void	send_message(pid_t server_pid, char *message)
{
	int		sig;
	size_t	i;
	size_t	j;
 	/* Inizializzazione della variabile "sig" a 0 */
	sig = 0;
	i = 0;
	while (i < ft_strlen(message))
	{
		/* Codifica il carattere "i" del messaggio in bit */
		encode_bits(message[i]);
		j = 0;
		while (j < 8)
		{
			/* Se il bit j-esimo dell'array "g_bits_to_send" è 1, viene inviato il segnale SIGUSR1, altrimenti viene inviato il segnale SIGUSR2 */
			if (g_bits_to_send[j] == '1')
				sig = SIGUSR1;
			else
				sig = SIGUSR2;
			/* Invia il segnale "sig" al processo server con ID "server_pid" */
			kill(server_pid, sig);
			/* Aggiunge un ritardo di 50 microsecondi tra ogni segnale inviato */
			usleep(50);
			j++;
		}
		/* Libera la memoria dell'array "g_bits_to_send" */
		ft_free((void **)&g_bits_to_send);
		i++;
	}
}
 /**
 * @brief 
	Funzione signal handler per SIGUSR1.
 * @details 
	Questa funzione viene chiamata quando il processo riceve il segnale SIGUSR1;
	Attende semplicemente per 1 microsecondo.
 * @param sig 
	Il numero del segnale.
 */
static void	sig_handler(int sig)
{
	if (sig == SIGUSR1)
		usleep(1);
}
 /**
 * @brief 
	Invia un messaggio ad un processo server.
 * @details 
	Questa funzione prende l'ID del processo server ed il messaggio da inviare come argomenti; 
	Il messaggio viene codificato in bit e ogni bit viene inviato al processo server utilizzando i segnali SIGUSR1 e SIGUSR2;
	Viene aggiunto un ritardo di 50 microsecondi tra ogni segnale inviato.
 * @param server_pid 
	L'ID del processo server.
 * @param message 
	La stringa di messaggio da inviare al processo server.
 */
int	main(int argc, char **argv)
{
	struct sigaction	act;
 	/* Verifica che il numero di argomenti sia corretto */
	if (argc != 3)
		ft_exit("Numero di argomenti errato...\n", RED_B, 2, 1);
 	/* Inizializzazione della struttura "act" a 0 */
	ft_bzero(&act, sizeof(act));
	/* Imposta la funzione "sig_handler" come signal handler per il segnale SIGUSR1 */
	act.sa_handler = &sig_handler;
	sigaction(SIGUSR1, &act, NULL);
	/* Invia il messaggio al processo server con ID "ft_atoi(argv[1])" */
	send_message(ft_atoi(argv[1]), argv[2]);
	return (0);
}