/* 
Questa funzione riceve un argomento in input, lo converte in un intero e lo scompone in fattori primi. 
Se l'argomento è 1, viene stampato direttamente "1". 
In caso contrario, viene eseguita una divisione ripetuta per trovare tutti i fattori primi. 
*/
#include <stdio.h>
#include <stdlib.h>
 int	main(int argc, char *argv[])
{
	int	i; // indice per la divisione ripetuta
	int	number; // numero da scomporre
 	if (argc == 2) // verifica se c'è un argomento in input
	{
		i = 1;
		number = atoi(argv[1]); // converte l'argomento in un intero
		if (number == 1)
			printf("1"); // se il numero è 1, stampa direttamente "1"
		while (number >= ++i) // esegui la divisione ripetuta
		{
			if (number % i == 0) // se i è un fattore di number
			{
				printf("%d", i); // stampa il fattore
				if (number == i)
					break ; // se il fattore è uguale al numero, esce dal ciclo
				printf("*"); // altrimenti stampa l'asterisco per separare i fattori
				number /= i; // divide il numero per il fattore trovato
				i = 1; // resetta l'indice per la divisione ripetuta
			}
		}
	}
	printf("\n"); // stampa a capo alla fine dell'esecuzione
	return (0); // restituisce 0 alla fine dell'esecuzione
}
