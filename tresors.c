/*!
*
*	\file tresors.c
*	\brief Fichier contenant l'implementation des tresors dans la matrice
*	\author Lucien BOUYEURE, Romane BUON, Yann PAULMERY
*	\version 3
*
*/

#include <stdlib.h>
#include <stdio.h>
#include "rogue_like.h"


/*!
*	
*	\fn placement_tresor1(char matrice[N][M],piece_t piece)
*	\brief Fonction de placement de tresors dans le niveau 1
*	\param matrice[N][M] Matrice principale du jeu
*	\param piece Permet d'obtenir les valeurs de x_haut et y_gauche pour la piece13
*
*/

//NIVEAU 1
void placement_tresor1(char matrice[N][M], piece_t piece) {
	int tresors[N][M]={0};	//On cree une matrice de int que l'on remplira soit de 0 soit d'une valeur k qui s'incrementera a chaque ajout
	int k=1, l=0, i, j;		//Ainsi cette fonction permettra de creer de l'aleatoire de facon optimisee
	for (i=piece.x_haut; i<N; i++) {	//On place le tresor dans la derniere piece de l'etage
		for (j=piece.y_gauche; j<M; j++) {
			if(matrice[i][j]==' ') {
				tresors[i][j]=k;		//On place la valeur numerique a la case et on incremente k
				k++;
			}
		}
	}
	l=rand_a_b(1, k);		//On recherche la case contenant le nombre aleatoire et on y place le tresor
	for(i=0; i<N; i++)
		for(j=0; j<M; j++)
			if(tresors[i][j]==l)
				matrice[i][j]='o';
}

//Les deux autres fonction sont identiques a la premiere, a la difference des tailles de matrice

/*!
*	
*	\fn placement_tresor2(char matrice[O][P],piece_t piece)
*	\brief Fonction de placement de tresors dans le niveau 2
*	\param matrice[N][M] Matrice principale du jeu
*	\param piece Permet d'obtenir les valeurs de x_haut et y_gauche pour la piece24
*
*/

//NIVEAU 2
void placement_tresor2(char matrice[O][P], piece_t piece) {
	int tresors[O][P]={0};
	int k=1, l=0, i, j;
	for (i=piece.x_haut; i<O; i++) {
		for (j=piece.y_gauche; j<P; j++) {
			if(matrice[i][j]==' ') {
				tresors[i][j]=k;
				k++;
			}
		}
	}
	l=rand_a_b(1, k);
	for(i=0; i<O; i++)
		for(j=0; j<P; j++)
			if(tresors[i][j]==l)
				matrice[i][j]='o';
}

/*!
*	
*	\fn placement_tresor3(char matrice[M][Q],piece_t piece)
*	\brief Fonction de placement de tresors dans le niveau 3
*	\param matrice[M][Q] Matrice principale du jeu
*	\param piece Permet d'obtenir les valeurs de x_haut et y_gauche pour la piece35
*
*/

//NIVEAU 3
void placement_tresor3(char matrice[M][Q], piece_t piece) {
	int tresors[M][Q]={0};
	int k=1, l=0, i, j;
	for (i=piece.x_haut; i<M; i++) {
		for (j=piece.y_gauche; j<Q; j++) {
			if(matrice[i][j]==' ') {
				tresors[i][j]=k;
				k++;
			}
		}
	}
	l=rand_a_b(1, k);
	for(i=0; i<M; i++)
		for(j=0; j<Q; j++)
			if(tresors[i][j]==l)
				matrice[i][j]='o';
}
