#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct struct_punti
{
	int	x;
	int	y;
} punti[4];

int main()
{
	int i = 0;
	while(i < 4)
	{
		scanf("%d", &punti[i].x);
		scanf("%d", &punti[i].y);
		i++;
	}
	
	int j = 0;
	int xmax;
	int xmin;
	int	ymin;
	int ymax;
	int m;
	int n;
	int h;
	while(j < 4)
	{
		if (punti[j].x >= punti[j + 1].x)
			xmax = punti[j].x;
		m = 0;
		if (punti[m].x <= punti[m + 1].x)
			xmin = punti[m].x;
		n = 0;
		if (punti[n].y <= punti[n + 1].y)
			ymin = punti[m].y;
		h = 0;
		if (punti[h].y >= punti[h + 1].y)
			ymax = punti[j].y;
		j++;
		m++;
		n++;
		h++;
	}
	while(++i < 4)
	{
		if(punti[i].x = xmax)
			j = punti[i].x;
		if(punti[i].x = xmin)
			m = punti[i].x;
		if(punti[i].x = ymin)
			n = punti[i].x;
		if(punti[i].x = ymax)
			h = punti[i].x;
	}

}
