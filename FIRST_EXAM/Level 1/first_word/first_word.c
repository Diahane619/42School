#include <unistd.h>
 int main (int argc, char **argv)
{
    int i = 0; // inizializza la variabile i a 0
     if (argc == 2) // controlla se il programma è stato chiamato con un argomento
    {
        while (argv[1][i] == 32 || argv[1][i] == 9) // salta tutti gli spazi e i tab all'inizio della parola
            i++;
        while ((argv[1][i] != 32 && argv[1][i] != 9) && argv[1][i]) // scorre tutti i caratteri della parola fino al primo spazio o tab
        {
            write(1, &argv[1][i], 1); // stampa il carattere corrente
            i++; // passa al carattere successivo
        }
    }
    write(1, "\n", 1); // stampa un carattere di nuova linea
}
