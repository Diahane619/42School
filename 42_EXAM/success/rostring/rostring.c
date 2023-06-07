/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:02:47 by francevi          #+#    #+#             */
/*   Updated: 2023/05/29 17:20:37 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> // Includi il file di intestazione per la funzione write()

int skip_whitespace(char *str, int i)
{
    while (str[i] == ' ' || str[i] == '\t') // Finché il carattere corrente è uno spazio o una tabulazione
        ++i; // Incrementa l'indice per saltare lo spazio vuoto
    return (i); // Restituisce l'indice aggiornato
}

int ft_wordlen(char *str)
{
    int i = 0;

    while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t') // Finché il carattere corrente non è la fine della stringa, uno spazio o una tabulazione
        ++i; // Incrementa l'indice per contare la lunghezza della parola
    return (i); // Restituisce la lunghezza della parola
}

int print_word(char *str, int i, int *is_first)
{
    int word_len;

    i = skip_whitespace(str, i); // Salta eventuali spazi vuoti iniziali
    word_len = ft_wordlen(str + i); // Ottieni la lunghezza della parola a partire dall'indice corrente
    if (*is_first == 0) // Se non è la prima parola
        write(1, " ", 1); // Scrivi uno spazio per separarla dalla parola precedente
    write(1, str + i, word_len); // Scrivi la parola nell'output standard
    *is_first = 0; // Aggiorna il flag indicante che la prima parola è stata stampata
    return (i + word_len); // Restituisce l'indice aggiornato
}

int epur_str(char *str)
{
    int i = 0;
    int is_first = 1; // Flag per tracciare se è la prima parola

    i = skip_whitespace(str, i); // Salta eventuali spazi vuoti iniziali
    while (str[i] != '\0') // Finché ci sono ancora caratteri nella stringa
    {
        i = print_word(str, i, &is_first); // Stampa la parola e aggiorna l'indice
        i = skip_whitespace(str, i); // Salta eventuali spazi vuoti dopo la parola
    }
    return (is_first); // Restituisce il flag che indica se è stata stampata almeno una parola
}

int main(int argc, char **argv)
{
    if (argc >= 2) // Verifica se è stato fornito almeno un argomento
    {
        char *str = argv[1]; // Ottieni il secondo argomento come stringa di input
        int i = 0;
        int is_first;

        i = skip_whitespace(str, i); // Salta eventuali spazi vuoti iniziali
        i = i + ft_wordlen(str + i); // Sposta l'indice alla fine della prima parola
        is_first = epur_str(str + i); // Rimuovi gli spazi vuoti iniziali e stampa le parole, aggiorna il flag
        print_word(str, 0, &is_first); // Stampa separatamente la prima parola
    }
	write(1, "\n", 1);

}
