#include <stdio.h>
#include <stdlib.h>

void concat(char *s1, char *s2) 
{
    while (*s1 != '\0') 
        s1++;
    while (*s2 != '\0') 
	{
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
}

int main() {
    char s1[100], s2[100];
    printf("Inserisci la prima stringa: ");
    scanf("%s", s1);
    printf("Inserisci la seconda stringa: ");
    scanf("%s", s2);
    concat(s1, s2);
    printf("Stringa concatenata: %s\n", s1);
    return 0;
}