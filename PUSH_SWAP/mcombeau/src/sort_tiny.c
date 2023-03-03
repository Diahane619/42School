#include "push_swap.h"

/* find_highest_index:
* Restituisce l'indice più alto in uno stack.*/
static int	find_highest_index(t_stack *stack)
{
	int		index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

/* tiny_sort:
* Ordina uno stack di 3 numeri in 2 o meno mosse.L'ordinamento viene eseguito per indice
* piuttosto che valore.Esempio:
* Valori: 0 9 2
* indici: [1] [3] [2]
* Soluzione, 2 mosse:
* RRA:
* Valori: 2 0 9
* indici: [2] [1] [3]
* sa:
* Valori: 0 2 9
* indici: [1] [2] [3]*/
void	tiny_sort(t_stack **stack)
{
	int		highest;

	if (is_sorted(*stack))
		return ;
	highest = find_highest_index(*stack);
	if ((*stack)->index == highest)
		do_ra(stack);
	else if ((*stack)->next->index == highest)
		do_rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		do_sa(stack);
}
