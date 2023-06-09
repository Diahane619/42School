/* La funzione "ft_range" prende in input due interi "start" e "end" e restituisce un array di interi contenente
 tutti i numeri interi compresi tra "start" e "end", inclusi gli estremi */
#include <stdlib.h>
int *ft_range(int start, int end)
{
	// Inizializziamo un contatore "i" a 0 e calcoliamo la lunghezza dell'array "res"
	int i = 0;
	int len = abs((end - start)) + 1;
	// Allochiamo dinamicamente la memoria per l'array "res"
	int *res = (int *)malloc(sizeof(int) * len);
 	// Finché non abbiamo inserito tutti gli elementi nell'array "res"
	while (i < len)
	{
		// Se "start" è minore di "end", inseriamo "start" nell'array e incrementiamo "start" di 1
		if (start < end)
		{
			res[i] = start;
			start++;
			i++;
		}
		// Altrimenti, inseriamo "start" nell'array e decrementiamo "start" di 1
		else
		{
			res[i] = start;
			start--;
			i++;
		}
	}
	// Restituiamo l'array "res"
    return (res);
}