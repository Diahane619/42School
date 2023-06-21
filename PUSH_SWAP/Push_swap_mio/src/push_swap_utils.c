typedef struct s_stack
{
    int *arr;
    int len;
} t_stack;


//Funzione per scambiare i primi due elementi di stacka
void sa(t_stack *stacka)
{
    if (stacka->len > 1) // verifica se ci sono almeno due elementi in stacka
    {
        int temp = stacka->arr[0]; // memorizza il primo elemento in una variabile temporanea
        stacka->arr[0] = stacka->arr[1]; // scambia i primi due elementi
        stacka->arr[1] = temp;
    }
}

//Funzione per scambiare i primi due elementi di stackb
void sb(t_stack *stackb)
{
    if(stackb->len > 1) // verifica se ci sono almeno due elementi in stackb
    {
        int temp = stackb->arr[0]; // memorizza il primo elemento in una variabile temporanea
        stackb->arr[0] = stackb->arr[1]; // scambia i primi due elementi
        stackb->arr[1] = temp;
    }
}

//Funzione per scambiare i primi due elementi di stacka e stackb
void ss(t_stack *stacka, t_stack *stackb)
{
    sa(stacka); // chiama la funzione sa per scambiare i primi due elementi di stacka
    sb(stackb); // chiama la funzione sb per scambiare i primi due elementi di stackb
}

//Funzione per inserire il primo elemento di stackb in cima a stacka
void pa(t_stack *stacka, t_stack *stackb)
{
    if (stackb->len > 0) // verifica se stackb non è vuoto
    {
        int i = stacka->len; // inizia dall'ultimo elemento di stacka
        while (i > 0) // sposta tutti gli elementi di stacka di una posizione a destra
        {
            stacka->arr[i] = stacka->arr[i - 1];
            i--;
        }
        stacka->arr[0] = stackb->arr[0]; // metti il primo elemento di stackb in cima a stacka
        i = 0; // inizia dal primo elemento di stackb
        while (i < stackb->len - 1) // sposta tutti gli elementi di stackb di una posizione a sinistra
        {
            stackb->arr[i] = stackb->arr[i + 1];
            i++;
        }
        stacka->len++; // aumenta la lunghezza di stacka di 1
        stackb->len--; // diminuisci la lunghezza di stackb di 1
    }
}

//Funzione per inserire il primo elemento di stacka in cima a stackb
void pb(t_stack *stacka, t_stack *stackb)
{
    if (stacka->len > 0) // verifica se stacka non è vuoto
    {
        int i = stackb->len; // inizia dall'ultimo elemento di stackb
        while (i > 0) // sposta tutti gli elementi di stackb di una posizione a destra
        {
            stackb->arr[i] = stackb->arr[i - 1];
            i--;
        }
        stackb->arr[0] = stacka->arr[0]; // metti il primo elemento di stacka in cima a stackb
        i = 0; // inizia dal primo elemento di stacka
        while (i < stacka->len - 1) // sposta tutti gli elementi di stacka di una posizione a sinistra
        {
            stacka->arr[i] = stacka->arr[i + 1];
            i++;
        }
        stackb->len++; // aumenta la lunghezza di stackb di 1
        stacka->len--; // diminuisci la lunghezza di stacka di 1
    }
}

//Funzione per ruotare gli elementi di stacka verso l'alto
void ra(t_stack *stacka)
{
    if (stacka->len > 0) // verifica se stacka non è vuoto
    {
        int temp = stacka->arr[0]; // memorizza il primo elemento in una variabile temporanea
        int i = 0; // inizia dal primo elemento di stacka
        while (i < stacka->len - 1) // sposta tutti gli elementi di stacka di una posizione a sinistra
        {
            stacka->arr[i] = stacka->arr[i + 1];
            i++;
        }
        stacka->arr[stacka->len - 1] = temp; // metti l'elemento temporaneo alla fine di stacka
    }
}

//Funzione per ruotare gli elementi di stackb verso l'alto
void rb(t_stack *stackb)
{
    if (stackb->len > 0) // verifica se stackb non è vuoto
    {
        int temp = stackb->arr[0]; // memorizza il primo elemento in una variabile temporanea
        int i = 0; // inizia dal primo elemento di stackb
        while (i < stackb->len - 1) // sposta tutti gli elementi di stackb di una posizione a sinistra
        {
            stackb->arr[i] = stackb->arr[i + 1];
            i++;
        }
        stackb->arr[stackb->len - 1] = temp; // metti l'elemento temporaneo alla fine di stackb
    }
}

//Funzione per ruotare gli elementi di stacka e stackb verso l'alto
void rr(t_stack *stacka, t_stack *stackb)
{
    ra(stacka); // chiama la funzione ra per ruotare gli elementi di stacka verso l'alto
    rb(stackb); // chiama la funzione rb per ruotare gli elementi di stackb verso l'alto
}

//Funzione per ruotare gli elementi di stacka verso il basso
void rra(t_stack *stacka)
{
    if (stacka->len > 0) // verifica se stacka non è vuoto
    {
        int temp = stacka->arr[stacka->len - 1]; // memorizza l'ultimo elemento in una variabile temporanea
        int i = stacka->len - 1; // inizia dall'ultimo elemento di stacka
        while (i > 0) // sposta tutti gli elementi di stacka di una posizione a destra
        {
            stacka->arr[i] = stacka->arr[i - 1];
            i--;
        }
        stacka->arr[0] = temp; // metti l'elemento temporaneo all'inizio di stacka
    }
}

//Funzione per ruotare gli elementi di stacka verso il basso
void rrb(t_stack *stackb)
{
    if (stackb->len > 0) // verifica se stackb non è vuoto
    {
        int temp = stackb->arr[stackb->len - 1]; // memorizza l'ultimo elemento in una variabile temporanea
        int i = stackb->len - 1; // inizia dall'ultimo elemento di stackb
        while (i > 0) // sposta tutti gli elementi di stackb di una posizione a destra
        {
            stackb->arr[i] = stackb->arr[i - 1];
            i--;
        }
        stackb->arr[0] = temp; // metti l'elemento temporaneo all'inEizio di stackb
    }
}

//Funzione per ruotare gli elementi di stacka e stackb verso il basso
void rrr(t_stack *stacka, t_stack *stackb)
{
    rra(stacka); // chiama la funzione rra per ruotare gli elementi di stacka verso il basso
    rrb(stackb); // chiama la funzione rrb per ruotare gli elementi di stackb verso il basso
}
