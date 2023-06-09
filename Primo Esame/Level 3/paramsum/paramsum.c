/* La funzione "ft_putnbr" prende in input un numero intero "n" e stampa il suo valore sullo standard output. */
#include <unistd.h>
void	ft_putnbr(int n)
{
	char digit;
	// Se "n" è maggiore o uguale a 10, richiamiamo la funzione "ft_putnbr" con "n/10" per stampare 
	// le cifre a sinistra di quella delle unità
	if (n >= 10)
		ft_putnbr(n / 10);
	// Convertiamo l'ultima cifra di "n" in un carattere e la stampiamo sullo standard output
	digit = (n % 10) + '0';
	write(1, &digit, 1);
}
 int	main(int argc, char **argv)
{
	// Ignoriamo l'argomento "argv"
	(void)argv;
	// Stampiamo il numero di argomenti passati al programma (meno 1, poiché il primo argomento è il nome del programma stesso)
	ft_putnbr(argc - 1);
	// Stampiamo un carattere di nuova linea sullo standard output e restituiamo 0
	write(1, "\n", 1);
	return (0);
}