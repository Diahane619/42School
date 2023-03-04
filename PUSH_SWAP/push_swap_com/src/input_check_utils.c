#include "push_swap.h"

/* is_digit:
* Verifica se il carattere è una cifra.
* Restituisce: 1 se il carattere è una cifra, 0 in caso contrario.*/
int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/* is_sign:
* Verifica se il carattere è un segno numerico, + o -.
* Restituisce: 1 se il carattere è un segno, 0 in caso contrario.*/
int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

/* nbstr_cmp:
* Confronta due stringhe di cifre per verificare se sono uguali o meno.
* Se una delle stringhe inizia con un segno '+', viene ignorata e il resto
* della stringa numerica viene controllata.
* Questo è così +123 == 123 ma -123! = 123.
* Restituisce: 0 se le stringhe corrispondono, un altro valore in caso contrario.*/
int	nbstr_cmp(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}
