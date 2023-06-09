/* La funzione "ft_list_size" prende in input un puntatore alla testa di una lista "begin_list" 
e restituisce la dimensione della lista */
#include "ft_list.h"
 int	ft_list_size(t_list *begin_list)
{
	// Se la lista è vuota, restituiamo 0
	if (begin_list == 0)
		return (0);
	// Altrimenti, restituiamo 1 più la dimensione della lista che inizia dal secondo elemento
	else
		return (1 + ft_list_size(begin_list->next));
}