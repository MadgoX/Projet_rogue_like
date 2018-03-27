#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "rogue_like.h"

//Trouve la coordonnee en x du tresor
int tresorx(int longueur) {
	srand(time(NULL));
	int i=0;
	i=rand()%(longueur-2);
	i++;
	return i;
}

//Trouve la coordonnee en y du tresor
int tresory(int largeur) {
	srand(time(NULL));
	int i=0;
	i=rand()%(largeur-2);
	i++;
	return i;
}

/*Ces fonctions cherchent aleatoirement un endroit pour y placer le tresor, c'est a dire une case
vide sans obstacle, representant l'interieur d'une piece*/

//Pour le premier etage
void placement_tresors1(char matrice[N][M]) {
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

//Pour le deuxieme etage
void placement_tresors2(char matrice[O][P]) {
	int tresx=tresorx(O);
	int tresy=tresory(P);
	if(matrice[tresx][tresy]==' ')
		matrice[tresx][tresy]='o';
	else {
		while(matrice[tresx][tresy]!=' ') {
			tresx=tresorx(O);
			tresy=tresory(P);
		}
		matrice[tresx][tresy]='o';
	}
}

//Pour le troisieme etage
void placement_tresors3(char matrice[M][Q]) {
	int tresx=tresorx(M);
	int tresy=tresory(Q);
	if(matrice[tresx][tresy]==' ')
		matrice[tresx][tresy]='o';
	else {
		while(matrice[tresx][tresy]!=' ') {
			tresx=tresorx(M);
			tresy=tresory(Q);
		}
		matrice[tresx][tresy]='o';
	}
}

//La seule difference entre ces trois fonctions est, comme partout, la taille de la matrice.
