#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NUMPUNTI 4

struct punto
{
    float x;
    float y;
};

int main()
{
    struct punto punti[NUMPUNTI];
    int i, j;
    float perimetro;
    float distmin, d;

    for (i = 0; i < NUMPUNTI; i++)
    {
        printf("Punto %d, coordinate x e y (separate da spazio): ", i);
        scanf("%f%f", &punti[i].x, &punti[i].y);
    }

    /* calcolo lunghezza del perimetro */
    perimetro = 0.0;
    for (i = 0; i < NUMPUNTI; i++)
    {
        j = (i + 1)%NUMPUNTI; /* vale i+1 per tutti i valori di i tranne 
                               l'ultimo per cui vale 0 */
        perimetro += sqrt((punti[i].x-punti[j].x)*(punti[i].x-punti[j].x) +
                           (punti[i].y-punti[j].y)*(punti[i].y-punti[j].y));
    }
    printf("Lunghezza perimetro: %f\n", perimetro);

    /* calcolo distanza minima tra due due punti qualsiasi del percorso */
    distmin = sqrt((punti[0].x-punti[1].x)*(punti[0].x-punti[1].x) +
                    (punti[0].y-punti[1].y)*(punti[0].y-punti[1].y));
    for (i = 0; i < NUMPUNTI-1; i++)
        for (j=i+1; j < NUMPUNTI; j++)
        {
            d = sqrt((punti[i].x-punti[j].x)*(punti[i].x-punti[j].x) +
                      (punti[i].y-punti[j].y)*(punti[i].y-punti[j].y));
            if (d<distmin)
                distmin = d;
        }
    printf("Distanza minima tra i punti: %f\n", distmin);

    return EXIT_SUCCESS;
}