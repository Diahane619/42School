# push_swap

PUSH_SWAP è un progetto di algoritmo scolastico 42 in cui dobbiamo ordinare un determinato elenco di numeri casuali con un insieme limitato di istruzioni, utilizzando il numero più basso possibile di azioni.

## utilizzo

Usa ``make`` per compilare.

Quindi eseguilo con:

shell
./push_swap <numeri>
`` `

I numeri forniti possono essere numeri interi positivi o negativi.Non ci devono essere duplicati.Per esempio :

shell
./push_swap 9 0 -217 2147483647 -2147483648
`` `

Se gli argomenti sono validi, il programma emetterà l'elenco più efficiente di azioni per ordinare l'elenco.

Il programma può essere controllato con il controllo fornito, come questo:

shell
Arg = "3 0 9 2 -1";./push_swap $ arg |./checker $ arg
`` `

Puoi anche semplicemente `` fare test3``` `` `fare test5```,` `` Make Test100`` o `` `Fare test500``` `testare rapidamente il programma con quel numero di valori perordinare.

Puoi visualizzare questo algoritmo PUSH_SWAP in azione con [O-Reo's Push_Swap Visualizer] (https://github.com/o-reo/push_swap_visualizer):

! [Push_swap Visualization di mccombeau] (https://github.com/mcombeau/push_swap/blob/main/subject/push_swap_visualization.gif)

## Regole e classificazione Push_Swap

Al programma è consentito solo due stack con cui funzionare, stack A e stack B. Tutti i numeri vengono inizialmente aggiunti a Stack A e B è vuoto.

Le possibili azioni sono:

* `` `pa``` (spinta a): prendi il primo elemento nella parte superiore di B e mettilo nella parte superiore di A. Non fare nulla se B è vuoto.
* `` `pb``` (push b): prendi il primo elemento nella parte superiore di A e mettilo nella parte superiore di B. Non fare nulla se A è vuoto.
* `` `sa``` (scambia a): scambia i primi 2 elementi nella parte superiore dello stack A. Non fare nulla se c'è solo uno o nessun elemento.
* `` `sb``` (scambio b): scambia i primi 2 elementi nella parte superiore dello stack B. Non fare nulla se c'è solo uno o nessun elemento.
* `` `ss```:` `sa``` e` `` sb``` allo stesso tempo.
* `` `ra``` (ruotare a): spostare tutti gli elementi di stack a up di 1. Il primo elemento diventa l'ultimo.
* `` `rb``` (ruotare b): spostare tutti gli elementi di stack b su di 1. Il primo elemento diventa l'ultimo.
* `` `rr```:` `ra``` e` `` rb``` allo stesso tempo.
* `` `rra``` (Ruota inversa A): sposta tutti gli elementi di stack A down di 1. L'ultimo elemento diventa il primo.
* `` `rrb``` (Ruota inversa B): sposta tutti gli elementi dello stack B verso il basso di 1. L'ultimo elemento diventa il primo.
* `` `rrr``:` `` rra`` e `` `` rrb``` allo stesso tempo.

Il grado dipende da quanto sia efficiente il processo di smistamento del programma.
 
* Ordinamento di 3 valori: non più di 3 azioni.
* Ordinamento di 5 valori: non più di 12 azioni.
* Ordinamento di 100 valori: valutazione da 1 a 5 punti a seconda del numero di azioni:
  * 5 punti per meno di 700 azioni
  * 4 punti per meno di 900
  * 3 punti per meno di 1100
  * 2 punti per meno di 1300
  * 1 punto per meno di 1500
* Ordinamento di 500 valori: valutazione da 1 a 5 punti a seconda del numero di azioni:
  * 5 punti per meno di 5500 azioni
  * 4 punti per meno di 7000
  * 3 punti per meno di 8500
  * 2 punti per meno di 10000
  * 1 punto per meno di 11500

La convalida del progetto richiede almeno 80/100.

---
Realizzato da mcombeau: mccombeau@student.42.fr |LinkedIn: [mccombeau] (https://www.linkedin.com/in/mia-combbeau-86653420b/) |Sito Web: [codequoi.com] (https://www.codequoi.com)