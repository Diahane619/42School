 /* Questa funzione prende in input una matrice di caratteri "tab",
 le dimensioni della matrice "size", le coordinate di un punto di partenza "cur" e un carattere "to_fill".
 La funzione utilizza l'algoritmo di flood fill per riempire di un carattere specifico tutte le celle adiacenti 
 al punto di partenza che hanno lo stesso carattere di partenza. */
 typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;
 /* Definiamo una struttura "t_point" che rappresenta un punto nella matrice, con coordinate x e y */
 void	fill(char **tab, t_point size, t_point cur, char to_fill)
{
	// Se le coordinate del punto corrente sono fuori dalla matrice
	// o il carattere nella cella non corrisponde a quello di partenza, usciamo dalla funzione
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] != to_fill)
		return;
 	// Altrimenti, impostiamo il carattere della cella corrente a "F" (per indicare che è stata visitata)
	tab[cur.y][cur.x] = 'F';
 	// Richiamiamo la funzione "fill" per tutte le celle adiacenti al punto corrente
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}
 /* Questa funzione richiama la funzione "fill" passando come punto di partenza il punto "begin" e 
 come carattere di partenza il carattere nella cella di "begin" */
 void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}