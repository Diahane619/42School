#include "push_swap.h"

/* arg_is_number:
* Controlla se l'argomento è un numero.+1 1 e -1 sono tutti numeri validi.
* Restituzione: 1 Se l'argomento è un numero, 0 in caso contrario.*/
static int	arg_is_number(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]) && av[i + 1] != '\0')
		i++;
	while (av[i] && is_digit(av[i]))
		i++;
	if (av[i] != '\0' && !is_digit(av[i]))
		return (0);
	return (1);
}

/* have_duplicates:
* Verifica se l'elenco degli argomenti ha numeri duplicati.
* Restituisce: 1 se viene trovato un duplicato, 0 se non ce ne sono.*/
static int	have_duplicates(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if (j != i && nbstr_cmp(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/* arg_is_zero:
* Controlla l'argomento è un 0 per evitare 0 +0 -0 duplicati
* e 0 0000 +000 -00000000.
* Restituire: 1 se l'argomento è uno zero, 0 se contiene
* Qualsiasi altra cosa che uno zero.*/
static int	arg_is_zero(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]))
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

/* is_correct_input:
* Verifica se gli argomenti indicati sono tutti numeri, senza duplicati.
* Restituzione: 1 Se gli argomenti sono validi, 0 in caso contrario.*/
int	is_correct_input(char **av)
{
	int	i;
	int	nb_zeros;

	nb_zeros = 0;
	i = 1;
	while (av[i])
	{
		if (!arg_is_number(av[i]))
			return (0);
		nb_zeros += arg_is_zero(av[i]);
		i++;
	}
	if (nb_zeros > 1)
		return (0);
	if (have_duplicates(av))
		return (0);
	return (1);
}
