#include <unistd.h>
/* Questa funzione "is_prime" prende in input un intero "num" e restituisce 1 se il numero è primo, 0 altrimenti. */
int is_prime(int num)
{
	// Inizializziamo l'indice "i" a 3
	int i = 3;
 	// Se il numero è minore o uguale a 1, restituiamo 0 (non è primo)
	if (num <= 1)
		return (0);
	// Se il numero è pari e maggiore di 2, restituiamo 0 (non è primo)
	if (num % 2 == 0 && num > 2)
		return (0);
	// Altrimenti, verifichiamo se il numero è divisibile per qualche numero dispari fino alla sua metà
	while (i < (num / 2))
	{
		if (num % i == 0)
			return 0;
		i += 2;
	}
	// Se non è divisibile da nessun numero dispari fino alla sua metà, restituiamo 1 (il numero è primo)
	return 1;
}
 /* La funzione "main" prende in input il numero di argomenti passati alla riga di comando "argc" e un array di stringhe "argv" contenente gli argomenti. La funzione calcola la somma di tutti i numeri primi minori o uguali al numero passato come argomento. */
int main(int argc, char *argv[])
{
	// Inizializziamo la variabile "sum" a 0 e otteniamo il numero passato come argomento tramite la funzione "ft_atoi"
	int sum = 0;
	int nb = ft_atoi(argv[1]);
 	// Se è stato passato un solo argomento, calcoliamo la somma dei numeri primi minori o uguali al numero passato
	if (argc == 2)
	{
		// Scandiamo tutti i numeri da "nb" a 1 e, se il numero è primo, aggiungiamo il suo valore alla somma
		while (nb > 0)
			if (is_prime(nb--))
				sum += (nb + 1);
		// Stampiamo la somma dei numeri primi
		ft_putnbr(sum);
	}
	// Se non è stato passato un solo argomento, stampiamo 0
	if (argc != 2)
		ft_putnbr(0);
	// Stampiamo un carattere di nuova linea e usciamo dalla funzione
	write(1, "\n", 1);
	return (0);
}