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

void placement_tresors(char matrice[N][M]) {
	int tresx=tresorx(N);
	int tresy=tresory(M);
	if(matrice[tresx][tresy]==' ')
		matrice[tresx][tresy]='o';
	else {
		while(matrice[tresx][tresy]!=' ') {
			tresx=tresorx(N);
			tresy=tresory(M);
		}
		matrice[tresx][tresy]='o';
	}
}
