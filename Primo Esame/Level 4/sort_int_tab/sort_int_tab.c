/*
Questa funzione prende un array di interi e la sua dimensione e lo ordina in modo crescente.
*/
 void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i = 0; // variabile per il conteggio degli elementi dell'array
	int	temp; // variabile temporanea per lo scambio di elementi
 	while (i < (size - 1)) // ciclo while per scorrere l'array
	{
		if (tab[i] > tab[i + 1]) // se l'elemento corrente è maggiore del successivo
		{
			temp = tab[i]; // salva l'elemento corrente nella variabile temporanea
			tab[i] = tab[i+ 1]; // sostituisce l'elemento corrente con il successivo
			tab[i + 1] = temp; // sostituisce l'elemento successivo con quello corrente (salvato nella variabile temporanea)
			i = 0; // riparte dal primo elemento dell'array
		}
		else
			i++; // altrimenti passa all'elemento successivo
	}
}