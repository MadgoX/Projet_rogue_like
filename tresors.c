#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "rogue_like.h"
a
char tresor(char mat[][], int longueur, int largeur) {
	srand(time(NULL));
	int i=0; int j=0;
	i=rand()%longueur-2; j=rand()%largeur-2;
	i++; j++;
	mat[i][j]='€';
	return mat;
}
