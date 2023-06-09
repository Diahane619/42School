/* La funzione "lcm" prende in input due numeri interi positivi "a" e "b" e restituisce il 
minimo comune multiplo (LCM) di "a" e "b". */
unsigned int lcm(unsigned int a, unsigned int b)
{
	// Inizializziamo una variabile "n" con il valore di "a" o "b" a seconda di quale sia il maggiore
	unsigned int n;	
	if (a == 0 || b == 0)
		// Se uno dei due numeri è 0, restituiamo 0 (poiché il LCM di 0 e qualsiasi altro numero è 0)
		return (0);
	if (a > b)
		n = a;
	else
		n = b;
	// Finché non troviamo un numero "n" che sia divisibile sia per "a" che per "b"
	while (1)
	{
		if (n % a == 0 && n % b == 0)
			// Restituiamo il valore di "n"
			return (n);
		// Altrimenti, incrementiamo "n" di 1 e riproviamo
		++n;
	}
}