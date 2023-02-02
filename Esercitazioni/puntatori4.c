#include <stdio.h>

int main() 
{
    char str[11];
    int i, flag = 0;

    printf("Inserisci la stringa: ");
    scanf("%s", str);
	i = 0; 
    while (i < 10) 
	{
        if (str[i] == 'A') 
		{
            flag = 1;
            break;
        }
		i++;
    }

    if (flag) 
        printf("Contiene la 'A' nei primi 10 caratteri\n"); 
	else
        printf("Non contiene la 'A' nei primi 10 caratteri.\n");
    return 0;
}