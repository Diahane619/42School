/* La funzione "to_lower" prende in input un carattere "c" e lo converte in minuscolo se è maiuscolo */
char	to_lower(char c)
{
	// Se il carattere è maiuscolo, lo convertiamo in minuscolo e lo restituiamo
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	// Altrimenti restituiamo il carattere originale
	return (c);
}
 /* La funzione "get_digit" prende in input un carattere "c" e la base "digits_in_base" 
 e restituisce il valore numerico corrispondente */
int get_digit(char c, int digits_in_base)
{
	int max_digit;
	// Calcoliamo il massimo valore numerico rappresentabile nella base "digits_in_base"
	if (digits_in_base <= 10)
		max_digit = digits_in_base + '0';
	else
		max_digit = digits_in_base - 10 + 'a';
 	// Se il carattere è un numero valido nella base "digits_in_base", restituiamo il valore numerico corrispondente
	if (c >= '0' && c <= '9' && c <= max_digit)
		return (c - '0');
	// Se il carattere è una lettera minuscola valida nella base "digits_in_base", restituiamo il valore numerico corrispondente
	else if (c >= 'a' && c <= 'f' && c <= max_digit)
		return (10 + c - 'a');
	// Altrimenti restituiamo "-1" per segnalare un errore
	else
		return (-1);
}
 /* La funzione "ft_atoi_base" prende in input una stringa "str" e la base "str_base" 
 e restituisce il corrispondente valore numerico */
int ft_atoi_base(const char *str, int str_base)
{
	// Inizializziamo il risultato a 0, il segno a 1 e il valore del primo carattere della stringa "str" a "digit"
	int result = 0;
	int sign = 1;
	int digit;
 	// Se il primo carattere della stringa è "-", impostiamo il segno a -1 e passiamo al carattere successivo
	if (*str == '-')
	{
		sign = -1;
		++str;
	}
 	// Finché il carattere corrente è un numero valido nella base "str_base", calcoliamo il valore numerico corrispondente
	// e lo aggiungiamo al risultato
	while ((digit = get_digit(to_lower(*str), str_base)) >= 0)
	{
		result = result * str_base;
		result = result + (digit * sign);
		++str;
	}
	// Restituiamo il risultato
	return (result);
}