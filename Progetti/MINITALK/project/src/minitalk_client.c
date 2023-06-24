/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 10:07:35 by francevi          #+#    #+#             */
/*   Updated: 2023/06/24 10:07:39 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile char *g_bits_to_send = 0; // Dichiarazione di una variabile globale char *g_bits_to_send

/* La funzione encode_bits prende un carattere come parametro e lo codifica in 8 bit.
Questi bit vengono poi aggiunti ad un array char globale, g_bits_to_send. 
Se il bit è 1, viene aggiunto '1' all'array, altrimenti viene aggiunto '0'. 
La funzione utilizza un ciclo while che itera 8 volte per codificare ogni bit del carattere. 
All'interno del ciclo, viene utilizzato l'operatore AND bit a bit per verificare se il bit corrente
del carattere è 1. Se è 1, viene aggiunto '1' all'array g_bits_to_send utilizzando 
la funzione ft_char_append, altrimenti viene aggiunto '0'. */
static void encode_bits(char c)
{
	size_t i; // Dichiarazione di una variabile di tipo size_t
 	i = 0;
	while (i < 8) // Ciclo while che itera 8 volte
	{
		if (c & (1 << i)) // Se il carattere "c" esiste & la "i" del bit che scorre è uguale a 1
			g_bits_to_send = ft_char_append((char *)g_bits_to_send, '1', true); // Aggiungi '1' alla fine della variabile "g_bits_to_send"
		else
			g_bits_to_send = ft_char_append((char *)g_bits_to_send, '0', true); // Aggiungi '0' alla fine della variabile "g_bits_to_send"
		i++; // Incremento di "i"
	}
}

/* La funzione send_message prende l'ID di un processo server e una stringa di messaggio come parametri.
La funzione codifica ogni carattere del messaggio in bit utilizzando la funzione encode_bits e invia i
bit al processo server utilizzando i segnali SIGUSR1 e SIGUSR2. Ogni bit viene inviato come segnale,
con un ritardo di 50 microsecondi tra ogni segnale. La funzione utilizza un ciclo while che itera per
la lunghezza della stringa di messaggio per codificare ogni carattere del messaggio in bit.
All'interno del ciclo, viene chiamata la funzione encode_bits con il carattere corrente della
stringa di messaggio come parametro. Viene quindi utilizzato un altro ciclo while che itera 8
volte per inviare ogni bit del carattere codificato al processo server.
All'interno di questo ciclo, viene verificato se il bit corrente è uguale a '1'. Se è uguale a '1', viene
assegnato il segnale SIGUSR1 alla variabile sig, altrimenti viene assegnato il segnale SIGUSR2. 
Viene quindi inviato il segnale sig al processo server con ID server_pid utilizzando la funzione kill. 
Viene quindi eseguito un delay di 50 microsecondi utilizzando la funzione usleep. 
Alla fine del ciclo interno, viene liberata la memoria allocata per la variabile g_bits_to_send utilizzando 
la funzione ft_free.*/
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

/*La funzione principale main prende due argomenti: l'ID di un processo server e 
una stringa di messaggio. Se il numero di argomenti non è uguale a 3, la funzione 
termina con un messaggio di errore utilizzando la funzione ft_exit.
Altrimenti, la funzione chiama la funzione send_message con l'ID del processo server
e la stringa di messaggio forniti come parametri.*/
int main(int argc, char **argv)
{
	if (argc != 3) // Se il numero di argomenti non è uguale a 3
		ft_exit("Numero di argomenti errato...\n", RED_B, 2, 1); // Stampa un messaggio di errore e termina il programma
	send_message(ft_atoi(argv[1]), argv[2]); // Chiamata alla funzione "send_message" con il primo argomento convertito in intero e il secondo argomento come stringa
	return (0); // Termina il programma con successo
}
