#include <stdlib.h>
#include "ft_list.h"
 // Definizione della funzione ft_list_foreach
void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	// Dichiarazione di un puntatore alla struttura t_list
	t_list *list_ptr;
 	// Inizializzazione del puntatore alla testa della lista
	list_ptr = begin_list;
 	// Ciclo while per scorrere la lista
	while (list_ptr)
	{
		// Chiamata alla funzione f passando come parametro il dato della lista corrente
		(*f)(list_ptr->data);
 		// Spostamento del puntatore alla lista successiva
		list_ptr = list_ptr->next;
	}
}
 //La funzione ft_list_foreach prende come argomenti un puntatore alla testa della lista (begin_list) e un puntatore a una funzione (f) 
 //che ha come parametro un puntatore a void. 
 //La funzione scorre la lista partendo dalla testa e chiama la funzione f per ogni elemento della lista, passando come parametro il dato contenuto in ogni nodo.