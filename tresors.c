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

//Permet d'eviter de placer le tresor dans un endroit autre qu'une piece (mur, emplacement vide...)
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

void placement_tresors2(char matrice[A][B]) {
	int tresx=tresorx(A);
	int tresy=tresory(B);
	if(matrice[tresx][tresy]==' ')
		matrice[tresx][tresy]='o';
	else {
		while(matrice[tresx][tresy]!=' ') {
			tresx=tresorx(A);
			tresy=tresory(B);
		}
		matrice[tresx][tresy]='o';
	}
}

void placement_tresors3(char matrice[C][D]) {
	int tresx=tresorx(C);
	int tresy=tresory(D);
	if(matrice[tresx][tresy]==' ')
		matrice[tresx][tresy]='o';
	else {
		while(matrice[tresx][tresy]!=' ') {
			tresx=tresorx(C);
			tresy=tresory(D);
		}
		matrice[tresx][tresy]='o';
	}
}