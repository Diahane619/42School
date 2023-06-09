#include <unistd.h>
 int main(int argc, char **argv)
{
	// Dichiarazione delle variabili
	int start; // Variabile per l'indice dell'inizio della parola
	int end; // Variabile per l'indice alla fine della stringa
	int i = 0; // Variabile per l'indice della stringa
 	// Controllo se è stato passato un solo argomento
	if(argc == 2)
	{   
		// Calcola la lunghezza della stringa passata come argomento
		while(argv[1][i] != '\0')
			i++;
 		// Scorre la stringa al contrario
		while(i >= 0)
		{
			// Ignora gli spazi alla fine della stringa
			while( argv[1][i] == '\0' || argv[1][i] == ' ' || argv[1][i] == '\t')
				i--;
			end = i;
 			// Trova l'inizio della parola
			while(argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
				i--;
			start = i + 1;
 			// Stampa la parola
			int  flag;
			flag = start;
			while(start <= end)
			{
				write (1, &argv[1][start],1);
				start++;		
			}
 			// Aggiungi uno spazio tra le parole
			if (flag !=0)
			{
				write(1, " ", 1);
			}
		}
	}
 	// Stampa una nuova riga
	write(1, "\n", 1);
}