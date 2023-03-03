#include "push_swap.h"

/* get_position:
* Assegna una posizione a ciascun elemento di uno stack dall'alto verso il basso
* in ordine crescente.
* Esempio Stack:
* Valore: 3 0 9 1
* INDICE: [3] [1] [4] [2]
* Posizione: <0> <1> <2> <3>
* Questo viene utilizzato per calcolare il costo di spostamento di un certo numero a
* una certa posizione.Se l'esempio sopra è stack B, costerebbe
* Niente (0) per spingere il primo elemento a impilare a.Tuttavia, se vogliamo
* spingere il valore più alto, 9, che è in terza posizione, costerebbe 2 extra
* si muove per portare quel 9 in cima a B prima di spingerlo per impilare A.
*/
static void	get_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

/* get_lowest_index_position:
* Ottiene la posizione corrente dell'elemento con l'indice più basso
* all'interno di uno stack.
*/
int	get_lowest_index_position(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = *stack;
	lowest_index = INT_MAX;
	get_position(stack);
	lowest_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

/* get_target:
* Scegli la migliore posizione target nello stack A per l'indice dato di
* Un elemento in stack B. Prima controlla se l'indice dell'elemento B può
* essere posizionato da qualche parte tra gli elementi in stack a, controllando se
* C'è un elemento nello stack A con un indice più grande.In caso contrario, trova il
* Elemento con l'indice più piccolo in A e lo assegna come posizione target.
*	--- Esempio:
* Target_pos inizia da int_max
* B indice: 3
* A contiene indici: 9 4 2 1 0
* 9> 3 && 9 <int_max: target_pos aggiornato a 9
* 4> 3 && 4 <9: target POS aggiornato a 4
* 2 <3 && 2 <4: nessun aggiornamento!
* Quindi target_pos deve essere la posizione dell'indice 4, poiché lo è
* L'indice più vicino.
*	--- Esempio:
* Target_pos inizia da int_max
* B indice: 20
* A contiene indici: 16 4 3
* 16 <20: nessun aggiornamento!target_pos = int_max
* 4 <20: nessun aggiornamento!target_pos = int_max
* 3 <20: nessun aggiornamento!target_pos = int_max
* ... Target_pos rimane a Int Max, devi cambiare strategie.
* 16 <20: target_pos aggiornato a 20
* 4 <20: target_pos aggiornato a 4
* 3 <20: target_pos aggiornato a 3
* Quindi target_pos deve essere la posizione dell'indice 3, poiché è
* La "fine" dello stack.*/
static int	get_target(t_stack **a, int b_idx,
								int target_idx, int target_pos)
{
	t_stack	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index > b_idx && tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (target_idx != INT_MAX)
		return (target_pos);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (target_pos);
}

/* get_target_position:
* Assegna una posizione target in stack A a ciascun elemento di stack A.
* La posizione target è il punto in cui è necessario che l'elemento in B
* arrivare per essere ordinato correttamente.Questa posizione lo farà
* essere utilizzato per calcolare il costo di spostamento di ciascun elemento a
* La sua posizione target in Stack A.
*/
void	get_target_position(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	int		target_pos;

	tmp_b = *b;
	get_position(a);
	get_position(b);
	target_pos = 0;
	while (tmp_b)
	{
		target_pos = get_target(a, tmp_b->index, INT_MAX, target_pos);
		tmp_b->target_pos = target_pos;
		tmp_b = tmp_b->next;
	}
}
