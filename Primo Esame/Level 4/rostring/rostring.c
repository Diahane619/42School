#include <unistd.h> // inclusione della libreria che contiene la funzione "write"
 int main(int argc, char **argv) // definizione della funzione principale "main", che accetta due argomenti: il numero degli argomenti passati sulla linea di comando e un array di stringhe contenente gli argomenti stessi
{
    int i; // dichiarazione della variabile intera "i"
    int start; // dichiarazione della variabile intera "start"
    int end; // dichiarazione della variabile intera "end"
    int flag; // dichiarazione della variabile intera "flag"
     flag = 0; // inizializzazione della variabile "flag" a 0
     if (argc > 1 && argv[1][0]) // controllo se ci sono almeno 2 argomenti passati sulla linea di comando e se il primo carattere dell'argomento non è vuoto
    {
        i = 0; // inizializzazione della variabile "i" a 0
        while (argv[1][i] == ' ' || argv[1][i] == '\t') // ciclo while che scorre la stringa finché ci sono spazi o tabulazioni all'inizio della stringa
            i++; // aggiornamento della variabile "i"
        start = i; // impostazione della variabile "start" all'indice corrente della stringa, che indica l'inizio della prima parola
        while (argv[1][i] != '\0' && argv[1][i] != ' ' && argv[1][i] != '\t') // ciclo while che scorre la stringa finché non si raggiunge la fine della stringa o si incontra uno spazio o una tabulazione, aggiornando la variabile "i"
            i++; // aggiornamento della variabile "i"
        end = i; // impostazione della variabile "end" all'indice corrente della stringa, che indica la fine della prima parola
        while (argv[1][i] == ' ' || argv[1][i] == '\t') // ciclo while che scorre la stringa finché ci sono spazi o tabulazioni dopo la fine della prima parola, aggiornando la variabile "i"
            i++; // aggiornamento della variabile "i"
        while(argv[1][i]) // ciclo while che scorre la stringa finché ci sono caratteri nella stringa
        {
            while ((argv[1][i] == ' ' && argv[1][i + 1] == ' ') || (argv[1][i] == '\t' && argv[1][i + 1] == '\t')) // ciclo while che controlla se ci sono spazi o tabulazioni multipli tra le parole, aggiornando la variabile "i"
                i++; // aggiornamento della variabile "i"
            if (argv[1][i] == ' ' || argv[1][i] == '\t') // controllo se il carattere corrente è uno spazio o una tabulazione, impostando la variabile "flag" a 1
                flag = 1; // impostazione della variabile "flag" a 1
            write(1, &argv[1][i], 1); // stampa il carattere corrente a video
            i++; // aggiornamento della variabile "i"
        }
        if (flag) // controllo se la variabile "flag" è impostata a 1, stampando uno spazio a video
            write(1, " ", 1); // stampa uno spazio a video
        while (start < end) // ciclo while che stampa le parole nella stringa in ordine inverso, partendo dall'inizio della prima parola fino alla fine della prima parola
        {
            write(1, &argv[1][start], 1); // stampa il carattere corrente a video
            start++; // aggiornamento della variabile "start"
        }
    }
    write(1, "\n", 1); // stampa il carattere di fine riga a video
    return(0); // restituisce 0
}