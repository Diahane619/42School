#include "push_swap.h"

/* push_all_save_three:
* Spinge tutti gli elementi di Stack A in Stack B, tranne gli ultimi.
* Spinge prima i valori più piccoli, quindi i valori più grandi con cui aiutare
* Efficienza di smistamento.*/
static void	push_all_save_three(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = get_stack_size(*stack_a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			do_pb(stack_a, stack_b);
			pushed++;
		}
		else
			do_ra(stack_a);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		do_pb(stack_a, stack_b);
		pushed++;
	}
}

/* shift_stack:
* Dopo che la maggior parte della pila è stata ordinata, sposta lo stack a fino al più basso
* Il valore è in cima.Se si trova nella metà inferiore dello stack, retromarcia
* Ruotalo in posizione, altrimenti ruotare fino a quando non è nella parte superiore della stack.*/
static void	shift_stack(t_stack **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = get_stack_size(*stack_a);
	lowest_pos = get_lowest_index_position(stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			do_rra(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			do_ra(stack_a);
			lowest_pos--;
		}
	}
}

/* sort:
* Algoritmo di ordinamento per uno stack più grande di 3.
* Spingi tutto tranne 3 numeri per impilare B.
* Ordina i 3 numeri lasciati in Stack A.
* Calcola la mossa più conveniente.
* Spostare gli elementi fino a quando lo stack A è in ordine.*/
void	sort(t_stack **stack_a, t_stack **stack_b)
{
	push_all_save_three(stack_a, stack_b);
	tiny_sort(stack_a);
	while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		shift_stack(stack_a);
}
