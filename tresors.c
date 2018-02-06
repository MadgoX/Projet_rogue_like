#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "rogue_like.h"

int tresorx(int longueur) {
	srand(time(NULL));
	int i=0;
	i=rand()%(longueur-2);
	i++;
	return i;
}

int tresory(int largeur) {
	srand(time(NULL));
	int i=0;
	i=rand()%(largeur-2);
	i++;
	return i;
}
//
