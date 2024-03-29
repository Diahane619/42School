#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

struct struct_punti
{
	int	x;
	int	y;;
};

int main()
{
	struct struct_punti punti[4];
	int i = 0;
	while(i < 4)
	{
		printf("Punto %d, coordinate x e y (separate da spazio): ", i);
		scanf("%d%d", &punti[i].x, &punti[i].y);
		i++;
	}
	int j = 0;
	int	perimetro = 0;
	i = 0;
    while (i < 4)
    {
        j = (i + 1) % 4;
        perimetro += sqrt((punti[i].x-punti[j].x)*(punti[i].x-punti[j].x) +
                           (punti[i].y-punti[j].y)*(punti[i].y-punti[j].y));
		i++;
	}
    printf("Lunghezza perimetro: %d\n", perimetro);

	int distmin = sqrt( (punti[0].x-punti[1].x)*(punti[0].x-punti[1].x) +
                    (punti[0].y-punti[1].y)*(punti[0].y-punti[1].y) );
    int d = 0;
	i = 0;
	while (i < 4)
    {
		j = i + 1;
		while (j < 4)
        {
            d = sqrt( (punti[i].x-punti[j].x)*(punti[i].x-punti[j].x) +
                      (punti[i].y-punti[j].y)*(punti[i].y-punti[j].y) );
            if (d < distmin)
                distmin = d;
		 	j++;
        }
		i++;
	}
    printf("Distanza minima tra i punti: %d\n", distmin);
	
	return EXIT_SUCCESS;
}