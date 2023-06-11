#include <stdlib.h>
#include <stdio.h> 
 /* Questa funzione copia i primi n caratteri della stringa s2 nella stringa s1 */
char *ft_strncpy(char *s1, char *s2, int n)
{
	// inizializza un contatore a -1 per inserire il primo carattere di s2 nell'arrey[0] invece che nell'arrey[1]
	int i = -1;
 	// copia i primi n caratteri di s2 in s1
	while (++i < n && s2[i])
		s1[i] = s2[i];
 	// aggiunge il carattere terminatore alla fine di s1
	s1[i] = '\0';
 	// restituisce s1
	return (s1);
}
 /* Questa funzione divide una stringa in sottostringhe separate da spazi, tabulazioni o newline */
char	**ft_split(char *str)
{
	// inizializza i contatori a 0
	int i = 0;
	int j = 0;
	int k = 0;
	int wc = 0;
 	// conta il numero di sottostringhe separate da spazi, tabulazioni o newline
	while (str[i])
	{
		// salta gli spazi, le tabulazioni e le newline
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
 		// se il carattere corrente non è uno spazio, una tabulazione o una newline, incrementa il contatore di parole
		if (str[i])
			wc++;
 		// salta la parola corrente
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
	}
 	// alloca un array di puntatori a char di dimensione wc + 1
	char **out = (char **)malloc(sizeof(char *) * (wc + 1));
 	// inizializza i contatori a 0
	i = 0;
 	// divide la stringa str in sottostringhe separate da spazi, tabulazioni o newline
	while (str[i])
	{
		// salta gli spazi, le tabulazioni e le newline
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
 		// salva l'indice del primo carattere della parola corrente
		j = i;
 		// salta la parola corrente
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
 		// se la sottostringa ha una lunghezza maggiore di 0, alloca un array di char della sua lunghezza + 1 e copia la sottostringa al suo interno
		if (i > j)
		{
			out[k] = (char *)malloc(sizeof(char) * ((i - j) + 1));
			ft_strncpy(out[k++], &str[j], i - j);
		}
	}
 	// aggiunge un puntatore nullo all'ultimo elemento dell'array di puntatori a char
	out[k] = NULL;
 	// restituisce l'array di puntatori a char
	return (out);
}