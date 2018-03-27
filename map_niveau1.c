/*!
*
*	\file map_niveau1.c
*	\brief Création de la map du niveau 1
*	\author Lucien BOUYEURE, Romane BUON, Yann PAULMERY
*	\version 0.1
*
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "rogue_like.h"

//Pieces 1, 2 et 3 du niveau 1
piece_t piece11, piece12, piece13;

/*!
*	
*	\fn void creer_piece1(char matrice[N][M], int x_haut, int y_gauche, int min_larg, int max_larg, int min_haut, int max_haut, int num_piece)
*	\brief Fonction de création des pièces du niveau 1, avec les portes.
*		\param matrice Matrice contenant la map du niveau 1.
*		\param x_haut Ordonnée de l'angle haut-gauche de la pièce.
*		\param y_gauche Abscisse de l'angle haut-gauche de la piece.
*		\param min_larg Valeur minimale de la largeur de la piece.
*		\param max_larg Valeur maximale de la largeu de la pièce.
*		\param min_haut Valeur minimale de la hauteur de la pièce.
*		\param max_haut Valeur maximale de la hauteur de la piece.
*		\param num_piece Numéro de la zone dans laquelle se trouve la pièce à créer (1, 2 ou 3 car il y a 3 pièces dans le niveau 1).
*
*/
void creer_piece1(char matrice[N][M], int x_haut, int y_gauche, int min_larg, int max_larg, int min_haut, int max_haut, int num_piece){
	//x_haut et y_gauche sont les coordonnées du coin haut gauche de la pièce

	int i, j;
	int x_bas, y_droite;
	int x_porte, y_porte;

	// initialisation de rand
	srand(time(NULL));

	x_bas = x_haut + rand_a_b(min_haut, max_haut);
	y_droite = y_gauche + rand_a_b(min_larg, max_larg);
	
	/*Creation d'une piece en haut à gauche de la map*/
	for(i = x_haut; i < x_bas; i++){
		for(j = y_gauche; j < y_droite; j++){
			matrice[i][j] = ' ';
		}
	}

	/*Mur de gauche de la pièce*/
	for(i = x_haut; i < x_bas; i++){
		j = y_gauche;
		matrice[i][j] = '|';
	}

	/*Mur de droite de la pièce*/
	for(i =  x_haut; i < x_bas; i++){
		j = y_droite;
		matrice[i][j] = '|';
	}

	/*Angles des pièces*/
	matrice[x_haut-1][y_gauche] = '+';
	matrice[x_haut-1][y_droite] = '+';
	matrice[x_bas][y_gauche] = '+';
	matrice[x_bas][y_droite] = '+';

	/*Mur du haut de la pièce*/
	for(j = y_gauche+1; j < y_droite; j++){
		i = x_haut-1;
		matrice[i][j] = '-';
	}

	/*Mur du bas de la pièce*/
	for(j = y_gauche+1; j < y_droite; j++){
		i = x_bas;
		matrice[i][j] = '-';
	}

	//Placement de la porte de la piece 1
	if(num_piece == 1){
		x_porte = rand_a_b(x_haut + 1, x_bas - 1);
		matrice[x_porte][y_droite] = 'P';

		//remplissage de la structure piece11
		piece11.x_haut = x_haut;
		piece11.y_gauche = y_gauche;

		piece11.x_porte1 = piece11.y_porte1 = piece11.position_p1 = 0;

		piece11.x_porte2 = x_porte;
		piece11.y_porte2 = y_droite;
		piece11.position_p2 = 'v';
	}

	//Placement de la porte pour la pièce 2
	if(num_piece == 2){
		//Première porte
		x_porte = rand_a_b(x_haut + 1, x_bas - 1);
		matrice[x_porte][y_gauche] = 'P';
		//Seconde porte
		y_porte = rand_a_b(y_gauche + 1, y_droite - 1);
		matrice[x_bas][y_porte] = 'P';

		//remplissage de la structure piece12
		piece12.x_haut = x_haut;
		piece12.y_gauche = y_gauche;

		piece12.x_porte1 = x_porte;
		piece12.y_porte1 = y_gauche;
		piece12.position_p1 = 'v';

		piece12.x_porte2 = x_bas;
		piece12.y_porte2 = y_porte;
		piece12.position_p2 = 'h';
	}

	//Placement de la porte pour la pièce 3
	if(num_piece == 3){
		y_porte = rand_a_b(y_gauche + 1, y_droite - 1);
		matrice[x_haut-1][y_porte] = 'P';

		//remplissage de la structure piece13
		piece13.x_haut = x_haut;
		piece13.y_gauche = y_gauche;

		piece13.x_porte1 = x_haut - 1;
		piece13.y_porte1 = y_porte;
		piece13.position_p1 = 'h';

		piece13.x_porte2 = piece13.y_porte2 = piece13.position_p2 = 0;
	}
}

/*!
*	
*	\fn void map_niveau1(char map[N][M])
*	\brief Fonction de création de la map du niveau 1.
*	\param matrice Matrice contenant la map du niveau 1.
*
*/
void map_niveau1(char map[N][M]){

	int x_haut_p1 = rand_a_b(2, 7), y_gauche_p1 = rand_a_b(2, 12);
	int x_haut_p2 = rand_a_b(2, 7), y_gauche_p2 = rand_a_b(27, 37);
	int x_haut_p3 = rand_a_b(17, 21), y_gauche_p3 = rand_a_b(7, 22);

	/* Création de la première pièce */
	creer_piece1(map, x_haut_p1, y_gauche_p1, 5, 12, 4, 7, 1);

	/* Création de la deuxième pièce */
	creer_piece1(map, x_haut_p2, y_gauche_p2, 5, 12, 4, 7, 2);
	
	/* Création de la troisième pièce */
	creer_piece1(map, x_haut_p3, y_gauche_p3, 19, 25, 4, 7, 3);
}

/*int main(){
	int i, j;
	char map[N][M];

	//Appel de la fonction qui créé le tour de la map
	creer_map(map);

	map_niveau1(map);

	//Affichage de la map
	for(i = 0; i < N; i++){
		for(j = 0; j < M; j++){
			printf("%c",map[i][j]);
		}
		printf("\n");
	}
}*/
