/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 19:27:57 by kichkiro          #+#    #+#             */
/*   Updated: 2023/04/06 22:58:02 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile char	*g_received_bits = 0; // definisce una variabile globale volatile di tipo char puntatore, inizializzata a 0

/**
 * @brief 
	Decodifica 8 bit in un carattere.
 * @details 
	La funzione prende un array globale di char contenente 8 bit e decodifica i 
	bit in un carattere utilizzando operatori bitwise.
 * @param bits 
	Gli 8 bit da decodificare.
 * @return 
	Il carattere decodificato.
 */
static char	decode_bits(volatile char *bits)
{
	char	c;
	size_t	i;

	c = 0; // inizializza la variabile c a 0
	i = 0; // inizializza la variabile i a 0
	while (i < 8) // esegue un ciclo while per 8 volte
	{
		if (bits[i] == '1') // se il bit corrente è uguale a '1'
			c |= (1 << i); // esegue un OR bitwise tra c e il risultato dello shift a sinistra di 1 di i posizioni
		else
			c |= 0; // altrimenti esegue un OR bitwise tra c e 0
		i++; // incrementa la variabile i di 1
	}
	return (c); // restituisce il valore di c
}

/**
 * @brief 
	Gestisce gli eventi di segnale inviati al processo
 * @details 
	Quando viene ricevuto un segnale SIGUSR1 o SIGUSR2, questa funzione aggiunge un 
	bit corrispondente alla variabile globale g_received_bits; 
	Se la sequenza di bit raggiunge 8 caratteri, la sequenza viene decodificata in un 
	carattere e stampata sull'output standard.
 * @param sig 
	Il numero del segnale ricevuto.
 */
static void	sig_handler(int sig)
{
	char	c;

	if (sig == SIGUSR1) // se il segnale ricevuto è SIGUSR1
		g_received_bits = ft_char_append((char *)g_received_bits, '1', 1); // aggiunge '1' alla fine della variabile globale g_received_bits
	else if (sig == SIGUSR2) // altrimenti, se il segnale ricevuto è SIGUSR2
		g_received_bits = ft_char_append((char *)g_received_bits, '0', 1); // aggiunge '0' alla fine della variabile globale g_received_bits
	else
		exit(1); // altrimenti esce dal programma con codice di uscita 1
	if (ft_strlen((char *)g_received_bits) == 8) // se la lunghezza della variabile globale g_received_bits è uguale a 8
	{
		c = decode_bits(g_received_bits); // decodifica i bit in un carattere e lo memorizza nella variabile c
		write(1, &c, 1); // scrive il carattere c sull'output standard
		ft_free((void **)&g_received_bits); // libera la memoria occupata dalla variabile globale g_received_bits
	}
}

/**
 * @brief 
	Funzione principale per il processo server.
 * @details 
	La funzione inizializza un gestore di segnali per SIGUSR1 e SIGUSR2 e attende 
	segnali in arrivo; 
	Una volta ricevuto un segnale, viene chiamata la funzione gestore del segnale e il 
	bit corrispondente viene aggiunto a un array globale di char; 
	Una volta ricevuti 8 bit, vengono decodificati in un carattere e stampati sull'output standard utilizzando la funzione write; 
 * @param argc 
	Il numero di argomenti passati alla funzione.
 * @param argv 
	Gli argomenti passati alla funzione.
 * @return 
	Il codice di uscita della funzione.
 */
int	main(int argc, char **argv)
{
	struct sigaction	act;

	(void)argv; // ignora l'argomento argv
	if (argc != 1) // se il numero di argomenti passati alla funzione è diverso da 1
		ft_exit("Too many arguments...\n", RED_B, 2, 1); // esce dal programma con messaggio d'errore
	ft_printf("%sServer PID ->%s %i%s\n", WHITE_B, CYAN_B, getpid(), RESET); // stampa il PID del processo server
	while (true) // esegue un ciclo infinito
	{
		ft_bzero(&act, sizeof(act)); // azzera la struttura act
		act.sa_handler = &sig_handler; // imposta il campo sa_handler della struttura act con l'indirizzo della funzione sig_handler
		sigaction(SIGUSR1, &act, NULL); // imposta la funzione sig_handler come gestore del segnale SIGUSR1
		sigaction(SIGUSR2, &act, NULL); // imposta la funzione sig_handler come gestore del segnale SIGUSR2
	}
	return (0); // restituisce 0 come codice di uscita
}
