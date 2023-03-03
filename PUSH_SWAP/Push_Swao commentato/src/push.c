#include "push_swap.h"

/* push:
* Spinge l'elemento superiore dello stack SRC nella parte superiore dello stack DEST.*/
static void	push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

/* do_pa:
* Spinge l'elemento superiore dello stack B nella parte superiore dello stack A.
* Stampa "PA" all'output standard.*/
void	do_pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_putstr("pa\n");
}

/* do_pb:
* Spinge l'elemento superiore dello stack A nella parte superiore dello stack b.
* Stampa "Pb" all'output standard.*/
void	do_pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr("pb\n");
}
