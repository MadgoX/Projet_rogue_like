/*!
*
*	\file map_niveau3.c
*	\brief Création de la map du niveau 3
*	\author Lucien BOUYEURE, Romane BUON, Yann PAULMERY
*	\version 0.1
*
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "rogue_like.h"

//Pieces 1, 2, 3, 4 et 5 du niveau 2
piece_t piece31, piece32, piece33, piece34, piece35;

/*!
*	
*	\fn void creer_piece3(char matrice[M][Q], int x_haut, int y_gauche, int min_larg, int max_larg, int min_haut, int max_haut, int num_piece)
*	\brief Fonction de création des pièces du niveau 3, avec les portes.
*		\param matrice Matrice contenant la map du niveau 3.
*		\param x_haut Ordonnée de l'angle haut-gauche de la pièce.
*		\param y_gauche Abscisse de l'angle haut-gauche de la piece.
*		\param min_larg Valeur minimale de la largeur de la piece.
*		\param max_larg Valeur maximale de la largeu de la pièce.
*		\param min_haut Valeur minimale de la hauteur de la pièce.
*		\param max_haut Valeur maximale de la hauteur de la piece.
*		\param num_piece Numéro de la zone dans laquelle se trouve la pièce à créer (1, 2, 3, 4 ou 5 car il y a 5 pièces dans le niveau 3).
*
*/
void creer_piece3(char matrice[M][Q], int x_haut, int y_gauche, int min_larg, int max_larg, int min_haut, int max_haut, int num_piece){
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

	//Placement de la porte pour la pièce 1
	if(num_piece == 1){
		x_porte = rand_a_b(x_haut + 1, x_bas - 1);
		matrice[x_porte][y_droite] = 'P';

		//remplissage de la structure piece31
		piece31.x_haut = x_haut;
		piece31.y_gauche = y_gauche;

		piece31.x_porte1 = piece31.y_porte1 = piece31.position_p1 = 0;

		piece31.x_porte2 = x_porte;
		piece31.y_porte2 = y_droite;
		piece31.position_p2 = 'v';
	}

	//Placement de la porte pour la pièce 2
	if(num_piece == 2){
		//Premiere porte
		x_porte = rand_a_b(x_haut + 1, x_bas - 1);
		matrice[x_porte][y_gauche] = 'P';

		piece32.x_porte1 = x_porte;

		//Seconde porte
		x_porte = rand_a_b(x_haut + 1, x_bas - 1);
		matrice[x_porte][y_droite] = 'P';

		//remplissage de la structure piece32
		piece32.x_haut = x_haut;
		piece32.y_gauche = y_gauche;

		piece32.y_porte1 = y_gauche;
		piece32.position_p1 = 'v';

		piece32.x_porte2 = x_porte;
		piece32.y_porte2 = y_droite;
		piece32.position_p2 = 'v';
	}

	//Placement de la porte pour la pièce 3
	if(num_piece == 3){
		//Première porte
		x_porte = rand_a_b(x_haut + 1, x_bas - 1);
		matrice[x_porte][y_gauche] = 'P';
		//Seconde porte
		y_porte = rand_a_b(y_gauche + 1, y_droite - 1);
		matrice[x_bas][y_porte] = 'P';

		//remplissage de la structure piece33
		piece33.x_haut = x_haut;
		piece33.y_gauche = y_gauche;

		piece33.x_porte1 = x_porte;
		piece33.y_porte1 = y_gauche;
		piece33.position_p1 = 'v';

		piece33.x_porte2 = x_bas;
		piece33.y_porte2 = y_porte;
		piece33.position_p2 = 'h';
	}

	//Placement de la porte pour la pièce 4
	if(num_piece == 4){
		x_porte = rand_a_b(x_haut + 1, x_bas - 1);
		matrice[x_porte][y_droite] = 'P';

		//remplissage de la structure piece34
		piece34.x_haut = x_haut;
		piece34.y_gauche = y_gauche;

		piece34.x_porte1 = x_porte;
		piece34.y_porte1 = y_droite;
		piece34.position_p1 = 'v';

		piece34.x_porte2 = piece34.y_porte2 = piece34.position_p2 = 0;
	}

	//Placement de la porte pour la pièce 5
	if(num_piece == 5){
		//Premiere porte
		y_porte = rand_a_b(y_gauche + 1, y_droite - 1);
		matrice[x_haut - 1][y_porte] = 'P';
		//Seconde porte
		x_porte = rand_a_b(x_haut + 1, x_bas - 1);
		matrice[x_porte][y_gauche] = 'P';

		//remplissage de la structure piece35
		piece35.x_haut = x_haut;
		piece35.y_gauche = y_gauche;

		piece35.x_porte1 = x_haut - 1;
		piece35.y_porte1 = y_porte;
		piece35.position_p1 = 'h';

		piece35.x_porte2 = x_porte;
		piece35.y_porte2 = y_gauche;
		piece35.position_p2 = 'v';
	}
}

/*!
*	
*	\fn void map_niveau3(char map[M][Q])
*	\brief Fonction de création de la map du niveau 3.
*	\param matrice Matrice contenant la map du niveau 3.
*
*/
void map_niveau3(char map[M][Q]){

	int x_haut_p1 = rand_a_b(3, 8), y_gauche_p1 = rand_a_b(3, 8);
	int x_haut_p2 = rand_a_b(3, 8), y_gauche_p2 = rand_a_b(42, 47);
	int x_haut_p3 = rand_a_b(3, 8), y_gauche_p3 = rand_a_b(82, 87);
	int x_haut_p4 = rand_a_b(27, 32), y_gauche_p4 = rand_a_b(3, 8);
	int x_haut_p5 = rand_a_b(25, 30), y_gauche_p5 = rand_a_b(62, 67);

	/* Création de la première pièce */
	creer_piece3(map, x_haut_p1, y_gauche_p1, 18, 25, 10, 16, 1);
	
	/* Création de la deuxième pièce */
	creer_piece3(map, x_haut_p2, y_gauche_p2, 10, 15, 8, 13, 2);
	
	/* Création de la troisième pièce */
	creer_piece3(map, x_haut_p3, y_gauche_p3, 18, 25, 10, 16, 3);
	
	/* Création de la quatrième pièce */
	creer_piece3(map, x_haut_p4, y_gauche_p4, 35, 45, 12, 17, 4);

	/* Création de la cinquième pièce */
	creer_piece3(map, x_haut_p5, y_gauche_p5, 34, 44, 13, 18, 5);
}

/*int main(){
	int i, j;
	char map[N][M];

	//Appel de la fonction qui créé le tour de la map
	creer_map(map);

	map_niveau3(map);

	//Affichage de la map
	for(i = 0; i < N; i++){
		for(j = 0; j < M; j++){
			printf("%c",map[i][j]);
		}
		printf("\n");
	}
}*/
