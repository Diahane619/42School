/* La funzione "main" viene eseguita quando si avvia il programma e prende in input due argomenti 
da riga di comando: una stringa "argv[1]" e un'altra stringa "argv[2]". 
La funzione cerca se la stringa "argv[1]" è contenuta nella stringa "argv[2]".
 Se la stringa "argv[1]" è contenuta in "argv[2]", 
 la funzione stampa "1" sullo standard output. Altrimenti, stampa "0". */
#include <unistd.h>
int main(int argc, char **argv)
{
	// Inizializziamo due contatori "i" e "j" a 0
	int i = 0;
	int j = 0;
	// Se ci sono esattamente due argomenti da riga di comando
	if (argc == 3)
	{
		// Finché non abbiamo raggiunto la fine di entrambe le stringhe "argv[1]" e "argv[2]"
		while (argv[2][j] && argv[1][i])
		{
			// Se il carattere corrente in "argv[2]" è uguale al carattere corrente in "argv[1]", incrementiamo "i"
			if (argv[2][j] == argv[1][i])
				i++;
			// Incrementiamo "j" in ogni caso
			j++;
		}
		// Se abbiamo raggiunto la fine di "argv[1]", stampiamo "1" sullo standard output
		if (argv[1][i] == '\0')
			write(1, "1", 1);
		// Altrimenti, stampiamo "0" sullo standard output
		else
			write(1, "0", 1);
	}
	// Alla fine, stampiamo un carattere di nuova linea sullo standard output e restituiamo 0
	write(1, "\n", 1);
	return (0);
}
