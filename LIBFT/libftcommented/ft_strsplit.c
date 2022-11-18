/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:21:25 by pbie              #+#    #+#             */
/*   Updated: 2022/11/03 15:51:20 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Questa funzione allocherà memoria e restituirà una tabella di stringhe "nuova" (all
 * terminato da un '\0', anche la tabella) come risultato della divisione di
 * la stringa data dal carattere dato c. Se l'allocazione della memoria non riesce
 * in qualsiasi punto la funzione restituirà NULL. E l'esempio di questa funzione è
 * ft_strsplit("*ciao*compagni***studenti*", '*'). Questo dovrebbe restituire una tabella
 * che divide la stringa int ["hello", "fellow", "students"]. Questa funzione
 * deve essere fatto in tre parti.

/* La prima funzione che abbiamo è una funzione di conteggio delle parole. 
 * Lo facciamo perché dobbiamo capire quante stringhe inseriremo nella nostra
 * tabella che deve essere restituita dalla funzione ft_strsplit. Vogliamo questo
 * per allocare memoria nella tabella.*/

static int			ft_cntwrd(char const *s, char c)
{
/*Iniziamo creando due variabili. Il primo è un unsigned int i che
* useremo per muoverci attraverso la stringa che è stata data a ft_strsplit.
* Usiamo unsigned nel caso in cui otteniamo una stringa estremmente lunga. 
* creamo anche una variabile cntr che useremo per contare le parole in
* stringa e quindi lo restituiremo. NOTA: questa funzione restituisce uno statico
* int. Una variabile statica per aggirare senza utilizzare variabili globali. 
* Una variabile statica mantiene il suo valore tra le invocazioni. Le
* usiamo per i casi in cui una funzione deve mantenere uno stato intermedio. 
* Impostiamo entrambe le nostre variabili su 0 e iniziamo la nostra funzione.*/
	unsigned int	i;
	int				cntr;

	i = 0;
	cntr = 0;
/*Entriamo nel nostro ciclo while e lo facciamo in loop fintanto che non abbiamo 
* raggiunto la fine della stringa data. All'interno del nostro ciclo 
* abbiamo un altro ciclo while: fintanto che la posizione dell'indice in cui 
* ci troviamo ha lo stesso valore del nostro parametro c vogliamo spostarci oltre. 
* Questo è lo stesso carattere c che la funzione ft_strsplit dividerà nella stringa. 
* Quindi vogliamo saltare quel carattere finché non troviamo la nostra prima vera 
* parola. Se, quando il nostro ciclo while ha finito di passare c caratteri e non abbiamo raggiunto 
* la fine della stringa aumentiamo il nostro contatore di parole.
* Sappiamo che abbiamo qualcosa che non è il carattere contenuto 
* dalla variabile c e vogliamo dividerlo dalla stringa. Passiamo quindi a un altro 
* ciclo while che passerà su tutto i caratteri nella nostra 
* parola finché non troviamo un'altra istanza di carattere detenuto dalla variabile
* c. Se ne troviamo uno e non abbiamo raggiunto la fine della nostra stringa 
* iniziamo di nuovo il ciclo e continuiamo fino a quando non siamo
* arrivati alla fine, contando tutte le parole lungo il percorso. Noi allora
* restituiamo la variabile cntr che ci dirà quante parole esistono nel nostro
* corda.*/
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			cntr++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (cntr);
}
/* Questa è una variazione della funzione ft_strdup che abbiamo precedentemente 
realizzato. Secondo il manuale, la funzione ft_strdup alloca memoria sufficiente 
per una copia della stringa data, esegue la copia e restituisce un puntatore ad esso. 
La funzione ft_strndup copia un numero massimo di caratteri (size_t n) dalla stringa 
data alla stringa copiata.*/
static char			*ft_strndup(const char *s, size_t n)
{

/*Iniziamo creando una variabile stringa a cui allocheremo memoria e che restituiremo 
come risultato di questa funzione. Allochiamo la memoria per questa stringa utilizzando 
il parametro n di questa funzione. Otteniamo questo parametro dalla nostra funzione 
ft_strsplit. È la lunghezza di una delle parole che abbiamo suddiviso in una tabella. 
Aggiungiamo 1 a questo parametro nella funzione malloc per garantire spazio fino a 
'\0'. Ora controlliamo: se l'allocazione non riesce lo restituisce NULL. 
Se l'allocazione è riuscita, allora vogliamo mettere la nostra parola nella nostra 
stringa fresca str. Lo facciamo usando la nostra funzione precedentemente fatta, ovvero
ft_strncpy. Diamo a ft_strncpy la nostra memoria allocata "fresca" str, il parametro 
string s (che è preso da ft_strsplit, inserito nella funzione ft_strndup che indica
la prima parola che vogliamo posizionare all'interno di str) e il parametro size_t n. 
Quindi ci assicuriamo di aggiungere un carattere di termine alla fine della nostra 
nuova stringa e poi restituamo str. */
	char			*str;

	str = (char *)malloc(sizeof(char) * n + 1);
	if (str == NULL)
		return (NULL);
	str = ft_strncpy(str, s, n);
	str[n] = '\0';
	return (str);
}
/*Adesso siamo pronti a creare la funzione ft_strsplit*/
char				**ft_strsplit(char const *s, char c)
{
/*Iniziamo creando tre variabili contatore. Useremo questi tre variabili per 
individuare le posizioni dell'indice all'interno della nostra stringa di parametri s. 
Creamo anche una variabile char **tab. Questa variabile è la nostra tabella che 
manterrà le nostre stringhe divise. Impostiamo le variabili i e k su 0 e quindi 
allochiamo memoria per la nostra tabella. Qui è dove usiamo la nostra funzione contatore
ft_cntwrd, per capire quanto spazio dobbiamo allocare per la nostra tabella. 
Se l'allocazione fallisce, restituiamo un NULL.*/
	int				i;
	int				j;
	int				k;
	char			**tab;

	i = 0;
	k = 0;
	tab = (char **)malloc(sizeof(char *) * (ft_cntwrd(s, c)) + 1);
	if (tab == NULL)
		return (NULL);
/*Ora entriamo nel nostro ciclo per dividere la nostra stringa. Il nostro ciclo 
principale la farà continua finché non abbiamo raggiunto la fine della nostra stringa 
di parametri. All'interno abbiamo un altro loop per passare su tutto il parametro c di
caratteri esistenti. Questo si fermerà quando raggiungeremo il nostro primo non c di 
carattere. Quindi impostiamo la nostra variabile j uguale al valore di i in questo punto 
della nostra funzione. j sarà usato per puntare alla posizione iniziale dell'indice 
della nostra prima parola all'interno della nostra stringa s. 
Continuiamo quindi a muoverci attraverso la stringa s fintanto che non incontriamo 
il nostro parametro c carattere. Una volta fatto, passiamo alla nostra istruzione if. 
Se i è maggiore di j (se c'è una parola che vogliamo) posizioneremo quella parola 
nella nostra posizione di indice della tabella 0 (che è attualmente il valore di k). 
Lo facciamo usando la funzione ft_strndup e gli diamo due parametri; 
La nostra stringa di parametri s (ma nella posizione di indice di j, l'inizio della parola 
che vogliamo) e la dimensione/lunghezza della parola che troviamo sottraendo il valore di
j dal valore di i (l'inizio e la fine della nostra parola). 
Quindi incrementiamo k per passare a posizione successiva nella nostra tabella. 
Ripetiamo il ciclo principale while fino a raggiungere la fine della nostra stringa 
di parametri s. Concludiamo aggiungendo una terminazione NULL nella nostra scheda 
tabella. Quindi restituiamo il nostro tavolo finito.*/
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{
			tab[k] = ft_strndup(s + j, i - j);
			k++;
		}
	}
	tab[k] = NULL;
	return (tab);
}
