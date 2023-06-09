// Questa funzione rimuove tutti gli elementi dalla lista 'begin_list' che corrispondono al valore di 'data_ref' utilizzando la funzione di confronto 'cmp'.
// Se la lista è vuota o 'begin_list' è NULL, non viene eseguita alcuna operazione.
// La funzione utilizza la ricorsione per scorrere tutti gli elementi della lista e rimuovere quelli corrispondenti.
#include <stdlib.h> // inclusione della libreria standard di C
#include "ft_list.h" // inclusione del file di header che definisce la struttura della lista
 void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)()) // definizione della funzione
{
	if (begin_list == NULL || *begin_list == NULL) // se la lista è vuota o è NULL, si esce dalla funzione
		return;
 	t_list *cur = *begin_list; // si inizializza un puntatore alla testa della lista
 	if (cmp(cur->data, data_ref) == 0) // se il valore del primo elemento corrisponde a quello da rimuovere
	{
		*begin_list = cur->next; // il puntatore alla testa punta all'elemento successivo
		free(cur); // si libera la memoria dell'elemento corrente
		ft_list_remove_if(begin_list, data_ref, cmp); // si richiama la funzione ricorsivamente con il nuovo puntatore alla testa
	}
	cur = *begin_list; // si aggiorna il puntatore al valore della testa della lista
	ft_list_remove_if(&cur->next, data_ref, cmp); // si richiama la funzione ricorsivamente per scorrere gli elementi successivi
}
//---------------------------------------------------------------------
// #include <stdio.h>
// #include <string.h>

// void	print_list(t_list **begin_list)
// {
// 	t_list *cur = *begin_list;
// 	while (cur != 0)
// 	{
// 		printf("%s\n", cur->data);
// 		cur = cur->next;
// 	}
// }

// int		main(void)
// {
// 	char straa[] = "String aa";
// 	t_list *aa = malloc(sizeof(t_list));
// 	aa->next = 0;
// 	aa->data = straa;

// 	char strbb[] = "String bb";
// 	t_list *bb = malloc(sizeof(t_list));
// 	bb->next = 0;
// 	bb->data = strbb;

// 	char strcc[] = "String cc";
// 	t_list *cc = malloc(sizeof(t_list));
// 	cc->next = 0;
// 	cc->data = strcc;

// 	char strdd[] = "String dd";
// 	t_list *dd = malloc(sizeof(t_list));
// 	dd->next = 0;
// 	dd->data = strdd;

// 	aa->next = bb;
// 	bb->next = cc;
// 	cc->next = dd;

// 	t_list **begin_list = &aa;

// 	print_list(begin_list);
// 	printf("----------\n");
// 	ft_list_remove_if(begin_list, straa, strcmp);
// 	print_list(begin_list);
// }
