#include <unistd.h>
 int main(int argc, char **argv)
{
    int i = 0;
     // verifica se il programma è stato chiamato con un argomento
    if (argc == 2)
    {
        // scorri tutti i caratteri dell'argomento
        while (argv[1][i] != '\0')
        {
            // se il carattere è minuscolo, lo converte in maiuscolo
            if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
                argv[1][i] -= 32;
            // altrimenti, se è maiuscolo, lo converte in minuscolo
            else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
                argv[1][i] += 32;
            // stampa il carattere
            write(1, &argv[1][i], 1);
            // passa al carattere successivo
            i++;    
        }
    }
    // stampa un carattere di nuova linea
    write(1, "\n", 1);
}