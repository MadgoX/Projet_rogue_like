/*!
*
*	\file main.c
*	\brief Fonction main du projet
*	\author Lucien BOUYEURE, Romane BUON, Yann PAULMERY
*	\version 0.1
*
*/
#include <stdlib.h>
#include <stdio.h>
#include<time.h>
#include <ncurses.h>
#include <unistd.h>
#include "rogue_like.h"

/*!
*	
*	\fn rand_a_b(int a, int b)
*	\brief Fonction de génération d'un nombre aléatoire.
*	\param a Borne inférieure de l'intevalle dans lequel le nombre aléatoire doit être généré.
*	\param b Borne supérieure de l'intevalle dans lequel le nombre aléatoire doit être généré.
*
*/
int rand_a_b(int a, int b){

    return rand()%(b-a) +a;

}

void afficher_matrice(char matrice[O][P]){
	for (int i = 0; i < O; i++)
	{
		for (int j = 0; j < P; j++)
		{
			printf("%c", matrice[i][j]);
		}
		printf("\n");
	}
}

/*!
*	
*	\fn int main()
*	\brief Fonction main du projet.
*
*/
int main(){
	system("resize -s 40 90");		// Redimensionne la taille du terminal
	initscr();              		// Initialise la structure WINDOW et autres paramètres
	
	//Matrices qui contiendront les maps avec toutes les pieces et les tresors
	char map1[N][M];
	char map2[O][P];
	char map3[M][Q];
	
//NIVEAU 1
	creer_map1(map1);				//Creation de la matrice et de ses bordures

	map_niveau1(map1);				//Creation des pieces

	placement_tresor1(map1, piece13);		//Placement des tresors

	affichage_map1(map1);			//Affichage de la map
	
	jeu1(map1);						//Lancement de la partie
	clear();
	refresh();

//NIVEAU 2
	creer_map2(map2);				//Creation de la matrice et de ses bordures
	
	map_niveau2(map2);				//Creation des pieces
//afficher_matrice(map2);
	
	placement_tresor2(map2, piece24);		//Placement des tresors

	affichage_map2(map2);			//Affichage de la map
	
	jeu2(map2);						//Lancement de la partie
	clear();
	refresh();


//NIVEAU 3
	creer_map3(map3);				//Creation de la matrice et de ses bordures
	
	map_niveau3(map3);				//Creation des pieces
		
	placement_tresor3(map3, piece35);		//Placement des tresors

	affichage_map3(map3);			//Affichage de la map
	
	jeu3(map3);						//Lancement de la partie
	
	endwin();               		// Restaure les paramètres par défaut du terminal
	system("resize -s 25 75");		// Redimensionne la taille du terminal
}
