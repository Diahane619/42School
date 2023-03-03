#include "push_swap.h"

/*swap:
* Scambia i primi 2 elementi di una stack.
* Non fa nulla se c'è solo uno o nessun elemento.
*/
static void	swap(t_stack *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

/* do_sa:
* Scambia i primi 2 elementi della stack a.
* Stampa "sa" sull'output standard.
*/
void	do_sa(t_stack **stack_a)
{
	swap(*stack_a);
	ft_putstr("sa\n");
}

/* do_sb:
* Scambia i primi 2 elementi della stack b.
* Stampa "sb" sull'output standard.
*/
void	do_sb(t_stack **stack_b)
{
	swap(*stack_b);
	ft_putstr("sb\n");
}

/* do_ss:
* Scambia i primi 2 elementi di entrambe le stack
* Stampa "ss" sull'output standard.
*/
void	do_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	ft_putstr("ss\n");
}
