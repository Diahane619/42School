/* Questo programma prende in input una stringa "argv[1]" e sostituisce ogni sequenza di spazi e tabulazioni con tre spazi. */
#include <unistd.h>
/* Includiamo la libreria "unistd.h" per poter utilizzare la funzione "write" */
int main(int argc, char const *argv[])
{
    // Dichiarazione delle variabili "i" e "flag"
    int i;
    int flag;
     // Se è stato passato un solo argomento, eseguiamo il programma
    if (argc == 2)
    {
        // Inizializziamo "i" a 0
        i = 0;
        // Scandiamo tutti gli spazi e le tabulazioni iniziali
        while (argv[1][i] == ' ' || argv[1][i] == '\t')
            i++;
        // Scandiamo tutti i caratteri della stringa "argv[1]"
        while (argv[1][i])
        {
            // Se il carattere corrente è uno spazio o una tabulazione, impostiamo il flag "flag" a 1
            if (argv[1][i] == ' ' || argv[1][i] == '\t')
                flag = 1;
            // Se il carattere corrente non è uno spazio o una tabulazione
            if (!(argv[1][i] == ' ' || argv[1][i] == '\t'))
            {
                // Se il flag "flag" è impostato a 1, scriviamo tre spazi
                if (flag)
                    write(1, "   ", 3);
                // Impostiamo il flag "flag" a 0
                flag = 0;
                // Scriviamo il carattere corrente
                write(1, &argv[1][i], 1);
            }
            // Passiamo al carattere successivo
            i++;
        }
    }
    // Scriviamo un carattere di nuova linea e usciamo dalla funzione
    write(1, "\n", 1);
    return (0);
}