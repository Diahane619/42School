#include "push_swap.h"

/* rev_rotate:
Questo codice imposta una nuova testa su una pila (*stack). 
Prende l'elemento finale della pila (tail) e l'elemento precedente 
alla fine della pila (before_tail).
Poi imposta la nuova testa della pila al punto finale della pila (tail) 
e associa il punto precendete alla fine (before_tail) a NULL.
*/
static void	rev_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;
	t_stack	*before_tail;

	tail = get_stack_bottom(*stack);
	before_tail = get_stack_before_bottom(*stack);
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	before_tail->next = NULL;
}

/* do_rra:
*	Prende l'ultimo elemento della stack "a" e lo sposta in cima.
*	STampa "rra".
*/
void	do_rra(t_stack **stack_a)
{
	rev_rotate(stack_a);
	ft_putstr("rra\n");
}

/* do_rrb:
*	Prende l'ultimo elemento della stack "b" e lo sposta in cima.
*	St xczzzampa "rrb".
*/
void	do_rrb(t_stack **stack_b)
{
	rev_rotate(stack_b);
	ft_putstr("rrb\n");
}

/* do_rrr:
*	Prende l'ultimo elemento di entrambe le stack e lo posiziona in cima.
*	Stampa "rrr"
*/
void	do_rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_putstr("rrr\n");
}
