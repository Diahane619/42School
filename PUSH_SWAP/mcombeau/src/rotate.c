#include "push_swap.h"

/* rotate:
* L'elemento superiore dello stack viene inviato in fondo.*/
static void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;

	tmp = *stack;
	*stack = (*stack)->next;
	tail = get_stack_bottom(*stack);
	tmp->next = NULL;
	tail->next = tmp;
}

/* do_ra:
* Invia l'elemento superiore dello stack A sul fondo.
* Stampa "RA" all'output standard.*/
void	do_ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putstr("ra\n");
}

/* do_rb:
* Invia l'elemento superiore dello stack B sul fondo.
* Stampa "RB" all'output standard.*/
void	do_rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putstr("rb\n");
}

/* do_rr:
* Invia l'elemento superiore di entrambi gli stack A e Stack B sul fondo
* dei loro rispettivi stack.
* Stampa "RR" all'output standard.*/
void	do_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr("rr\n");
}
