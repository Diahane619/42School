#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];

    printf("Inserisci la prima stringa: ");
    scanf("%s", str1);

    printf("Inserisci la seconda stringa: ");
    scanf("%s", str2);

    int str1_len = strlen(str1);
    int str2_len = strlen(str2);

    if (str2_len > str1_len) 
        printf("La seconda stringa non è uguale alla parte terminale della prima.\n"); 
	else {
        int match = 1;
		int i = 0;
        while (i < str2_len) 
		{
            if (str1[str1_len - str2_len + i] != str2[i])
			{
                match = 0;
                break;
            }
			i++;
        }

        if (match) 
            printf("La seconda stringa è uguale alla parte terminale della prima.\n");
		else 
            printf("La seconda stringa non è uguale alla parte terminale della prima.\n");
    }
    return 0;
}