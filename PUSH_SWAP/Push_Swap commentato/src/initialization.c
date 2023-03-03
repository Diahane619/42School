#include "push_swap.h"

/* fill_stack_values:
* Riempie stack_a dei valori forniti.
* Se i valori sono fuori dall'intervallo intero, stampe ed errori ed esce dal programma.
*/
t_stack	*fill_stack_values(int ac, char **av)
{
	t_stack		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 1;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit_error(&stack_a, NULL);
		if (i == 1)
			stack_a = stack_new((int)nb);
		else
			stack_add_bottom(&stack_a, stack_new((int)nb));
		i++;
	}
	return (stack_a);
}

/* assign_index:
* Assegna un indice a ciascun valore in stack a.Questo è un modo conveniente per ordinare
* Lo stack perché gli indici possono essere controllati e confrontati anziché i valori effettivi,
* che può o meno essere adiacente l'uno all'altro.
* ex.Valori: -3 0 9 2
* indici: [1] [2] [4] [3]
* Gli indici sono assegnati dal più alto (stack_size) al più basso (1).*/
void	assign_index(t_stack *stack_a, int stack_size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value;

	while (--stack_size > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}
