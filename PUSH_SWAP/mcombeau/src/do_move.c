/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:26:29 by mcombeau          #+#    #+#             */
/*   Updated: 2023/03/03 13:51:36 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* do_rev_rotate_both:
* Il retro ruota sia impilare A e B fino a quando uno di essi è in posizione.
* Il costo dato è negativo poiché entrambe le posizioni sono nella metà inferiore
* dei loro rispettivi stack.Il costo è aumentato come sono le pile
* ruotato, quando uno raggiunge 0, lo stack è stato ruotato il più possibile
* e la posizione massima è corretta.
*/
static void	do_rev_rotate_both(t_stack **a, t_stack **b,
												int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		do_rrr(a, b);
	}
}

/* do_rotate_both:
* Ruota sia lo stack A che B fino a quando uno di essi è in posizione.
* Il costo dato è positivo poiché entrambe le posizioni sono nella metà superiore
* dei loro rispettivi stack.Il costo è ridotto come sono le pile
* ruotato, quando uno raggiunge 0, lo stack è stato ruotato il più possibile
* e la posizione massima è corretta.*/
static void	do_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		do_rr(a, b);
	}
}

/* do_rotate_a:
* Ruota lo stack A fino a quando non è in posizione.Se il costo è negativo,
* Lo stack sarà ruotato inverso, se è positivo, lo sarà
* ruotato.*/
static void	do_rotate_a(t_stack **a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			do_ra(a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			do_rra(a);
			(*cost)++;
		}
	}
}

/* do_rotate_b:
* Ruota lo stack B fino a quando non è in posizione.Se il costo è negativo,
* Lo stack sarà ruotato inverso, se è positivo, lo sarà
* ruotato.
*/
static void	do_rotate_b(t_stack **b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			do_rb(b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			do_rrb(b);
			(*cost)++;
		}
	}
}

/* do_move:
* Sceglie quale muoversi da fare per ottenere l'elemento stack B al corretto
* posizione in stack A.
* Se i costi di spostamento dello stack A e B in posizione corrispondono (ovvero entrambi negativi
* di entrambi i positivi), entrambi saranno ruotati o inversi ruotati contemporaneamente.
* Potrebbero anche essere ruotati separatamente, prima di spingere finalmente l'elemento B in alto
* All'alto stack A.
*/
void	do_move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rev_rotate_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rotate_both(a, b, &cost_a, &cost_b);
	do_rotate_a(a, &cost_a);
	do_rotate_b(b, &cost_b);
	do_pa(a, b);
}
