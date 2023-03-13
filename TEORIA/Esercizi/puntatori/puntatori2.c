#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
	char *stringa = malloc(sizeof(stringa)); 
	short int palindrome = 1;		//1 = stringa palindrome; 2 = stringa non palindrome
	
	printf("Inserire una stringa: ");
	scanf("%s", stringa);     			//legge la stringa da tastiera
	int i = 0;
	int	j = strlen(stringa) - 1;
	/*ciclo di controllo: i parte dalla prima lettera e viene incrementata fino alla metà
	della lunghezza della stringa, j parte dall'ultima lettera e viene decrementata
	fino alla metà della lunghezza della stringa*/
	while (i < (j +  1)/2)
	{
		if(stringa[i] != stringa[j]) //se trova due lettere diverse...
		{
			palindrome = 0;  //assegna 0 a "palindrome"...
			break;          //ed esce dal ciclo
		}
		i++;
		j--;
	}
	if (palindrome) 
		printf("La stringa è palindrome\n");
	else 
		printf("La stringa non è palindrome\n");
}