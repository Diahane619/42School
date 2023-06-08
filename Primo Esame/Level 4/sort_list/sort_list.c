#include <stdlib.h>
#include "list.h"
 // Definizione della funzione sort_list che ordina gli elementi di una lista
t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	// Dichiarazione delle variabili necessarie
	int	swap;
	t_list	*tmp;
 	// Inizializzazione della variabile tmp con il valore del puntatore alla testa della lista
	tmp = lst;
 	// Ciclo while che scorre la lista fino alla fine
	while(lst->next != NULL)
	{
		// Se la funzione di comparazione restituisce 0, i due elementi devono essere scambiati
		if (((*cmp)(lst->data, lst->next->data)) == 0)
		{
			// Scambio dei dati dei due nodi
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
 			// Reimpostazione del puntatore alla testa della lista
			lst = tmp;
		}
		else
			// Se la funzione di comparazione restituisce un valore diverso da 0, si passa al nodo successivo
			lst = lst->next;
	}
 	// Reimpostazione del puntatore alla testa della lista
	lst = tmp;
 	// Restituzione del puntatore alla testa della lista
	return (lst);
}