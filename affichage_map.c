/*!
*
*	\file affichage_map.c
*	\brief Affichage des maps
*	\author Lucien BOUYEURE, Romane BUON, Yann PAULMERY
*	\version 0.1
*
*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ncurses.h>
#include <unistd.h>
#include "rogue_like.h"

/*!
*	
*	\fn void affichage_map1(char matrice[N][M])
*	\brief Afichage de la map du niveau 1.
*	\param matrice Matrice contenant la map du niveau 1.
*
*/
void affichage_map1(char matrice[N][M]){
	int i, j;
	
	//Affichage de la map
	for(i = 0; i < N; i++){
		for(j = 0; j < M; j++){
			printw("%c",matrice[i][j]);
		}
		printw("\n");
	}
}

/*!
*
*	\fn void affichage_map2(char matrice[O][P])
*	\brief Affichage de la matice du niveau 2.
*	\param matrice Matrice contenant la map du niveau 2.
*
*/
void affichage_map2(char matrice[O][P]){
	int i, j;
	
	//Affichage de la map
	for(i = 0; i < O; i++){
		for(j = 0; j < P; j++){
			printw("%c",matrice[i][j]);
		}
		printw("\n");
	}
}

/*!
*
*	\fn void affichage_map3(char matrice[M][Q])
*	\brief Affichage de la matice du niveau 3.
*	\param matrice Matrice contenant la map du niveau 3.
*
*/
void affichage_map3(char matrice[M][Q]){
	int i, j;
	
	//Affichage de la map
	for(i = 0; i < M; i++){
		for(j = 0; j < Q; j++){
			printw("%c",matrice[i][j]);
		}
		printw("\n");
	}
}