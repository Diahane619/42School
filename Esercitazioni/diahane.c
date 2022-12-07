#include <stdio.h>

typedef enum
{
lunedi,
martedi,
mercoledi,
giovedi,
venerdi,
sabato,
domenica
} WEEKDAY;

int main(void)
{
WEEKDAY day = martedi;
printf("%d\n", day);
}
