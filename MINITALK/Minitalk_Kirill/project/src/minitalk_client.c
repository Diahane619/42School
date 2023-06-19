/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 19:24:17 by kichkiro          #+#    #+#             */
/*   Updated: 2023/04/06 22:41:37 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile char *g_bits_to_send = 0; // Dichiarazione di una variabile globale char *g_bits_to_send
 /**
 * @brief 
	Codifica un carattere in 8 bit e li aggiunge ad un array char globale.
 * @details 
	La funzione prende un carattere e lo codifica in 8 bit, che vengono poi 
	aggiunti ad un array char globale, g_bits_to_send;
	Se il bit è 1, aggiunge '1' all'array, altrimenti aggiunge '0'.
 * @param c 
 	Il carattere da codificare.
 */
static void encode_bits(char c)
{
	size_t i; // Dichiarazione di una variabile di tipo size_t
 	i = 0;
	while (i < 8) // Ciclo while che itera 8 volte
	{
		if (c & (1 << i)) // Se il carattere "c" AND bit-shift di "i" è uguale a 1
			g_bits_to_send = ft_char_append((char *)g_bits_to_send, '1', true); // Aggiungi '1' alla fine della variabile "g_bits_to_send"
		else
			g_bits_to_send = ft_char_append((char *)g_bits_to_send, '0', true); // Aggiungi '0' alla fine della variabile "g_bits_to_send"
		i++; // Incremento di "i"
	}
}
 /**
 * @brief 
	Invia un messaggio ad un processo server.
 * @details 
	La funzione prende l'ID di un processo server e una stringa di messaggio, codifica ogni 
	carattere del messaggio in bit e invia i bit al processo server utilizzando i segnali SIGUSR1 e SIGUSR2;
	Ogni bit viene inviato come segnale, con un ritardo di 50 microsecondi tra ogni segnale.
 * @param server_pid 
	L'ID del processo server.
 * @param message 
	La stringa di messaggio da inviare al processo server.
 */
static void send_message(pid_t server_pid, char *message)
{
	int sig; // Dichiarazione di una variabile di tipo int
	size_t i, j; // Dichiarazione di due variabili di tipo size_t
 	sig = 0;
	i = 0;
	while (i < ft_strlen(message)) // Ciclo while che itera per la lunghezza della stringa "message"
	{
		encode_bits(message[i]); // Chiamata alla funzione "encode_bits" con il carattere "i" della stringa "message"
		j = 0;
		while (j < 8) // Ciclo while che itera 8 volte
		{
			if (g_bits_to_send[j] == '1') // Se il bit è uguale a '1'
				sig = SIGUSR1; // Assegna il segnale SIGUSR1 alla variabile "sig"
			else
				sig = SIGUSR2; // Assegna il segnale SIGUSR2 alla variabile "sig"
			kill(server_pid, sig); // Invia il segnale "sig" al processo server con ID "server_pid"
			usleep(50); // Delay di 50 microsecondi
			j++; // Incremento di "j"
		}
		ft_free((void **)&g_bits_to_send); // Libera la memoria allocata per la variabile "g_bits_to_send"
		i++; // Incremento di "i"
	}
}
 /**
 * @brief 
	La funzione principale.
 * @details 
	La funzione prende due argomenti: l'ID di un processo server e una stringa di messaggio;
	Se il numero di argomenti non è uguale a 3, la funzione termina con un messaggio di errore;
	Altrimenti, la funzione chiama la funzione send_message con l'ID del processo server e la stringa di messaggio forniti.
 * @param argc 
	Il numero di argomenti passati al programma.
 * @param argv 
	Un array di stringhe contenente gli argomenti del programma.
 * @return 
	0 se il programma viene eseguito correttamente.
 */
int main(int argc, char **argv)
{
	if (argc != 3) // Se il numero di argomenti non è uguale a 3
		ft_exit("Numero di argomenti errato...\n", RED_B, 2, 1); // Stampa un messaggio di errore e termina il programma
	send_message(ft_atoi(argv[1]), argv[2]); // Chiamata alla funzione "send_message" con il primo argomento convertito in intero e il secondo argomento come stringa
	return (0); // Termina il programma con successo
}
