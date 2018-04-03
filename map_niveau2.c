/*!
*
*	\file map_niveau2.c
*	\brief Création de la map du niveau 2
*	\author Lucien BOUYEURE, Romane BUON, Yann PAULMERY
*	\version 0.1
*
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <ncurses.h>
#include <unistd.h>
#include "rogue_like.h"

/*!
*	
*	\fn void creer_piece2(char matrice[O][P], int x_haut, int y_gauche, int min_larg, int max_larg, int min_haut, int max_haut, int num_piece)
*	\brief Fonction de création des pièces du niveau 2, avec les portes.
*		\param matrice Matrice contenant la map du niveau 2.
*		\param x_haut Ordonnée de l'angle haut-gauche de la pièce.
*		\param y_gauche Abscisse de l'angle haut-gauche de la piece.
*		\param min_larg Valeur minimale de la largeur de la piece.
*		\param max_larg Valeur maximale de la largeu de la pièce.
*		\param min_haut Valeur minimale de la hauteur de la pièce.
*		\param max_haut Valeur maximale de la hauteur de la piece.
*		\param num_piece Numéro de la zone dans laquelle se trouve la pièce à créer (1, 2, 3 ou 4 car il y a 4 pièces dans le niveau 2).
*
*/
void creer_piece2(char matrice[O][P], int x_haut, int y_gauche, int min_larg, int max_larg, int min_haut, int max_haut, int num_piece){
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

		//remplissage de la structure piece12
		piece21.x_haut = x_haut;
		piece21.y_gauche = y_gauche;

		piece21.x_porte1 = piece21.y_porte1 = piece21.position_p1 = 0;

		piece21.x_porte2 = x_porte;
		piece21.y_porte2 = y_droite;
		piece21.position_p2 = 'v';
	}

	//Placement de la porte pour la pièce 2
	if(num_piece == 2){
		//Première porte
		x_porte = rand_a_b(x_haut + 1, x_bas - 1);
		matrice[x_porte][y_gauche] = 'P';
		//Seconde porte
		y_porte = rand_a_b(y_gauche + 1, y_droite - 1);
		matrice[x_bas][y_porte] = 'P';

		//remplissage de la structure piece22
		piece22.x_haut = x_haut;
		piece22.y_gauche = y_gauche;

		piece22.x_porte1 = x_porte;
		piece22.y_porte1 = y_gauche;
		piece22.position_p1 = 'v';

		piece22.x_porte2 = x_bas;
		piece22.y_porte2 = y_porte;
		piece22.position_p2 = 'h';
	}

	//Placement de la porte pour la pièce 3
	if(num_piece == 3){
		x_porte = rand_a_b(x_haut + 1, x_bas - 1);
		matrice[x_porte][y_droite] = 'P';

		//remplissage de la structure piece23
		piece23.x_haut = x_haut;
		piece23.y_gauche = y_gauche;

		piece23.x_porte1 = x_porte;
		piece23.y_porte1 = y_droite;
		piece23.position_p1 = 'v';

		piece23.x_porte2 = piece23.y_porte2 = piece23.position_p2 = 0;
	}

	//Placement de la porte pour la pièce 4
	if(num_piece == 4){
		//Premiere porte
		y_porte = rand_a_b(y_gauche + 1, y_droite - 1);
		matrice[x_haut - 1][y_porte] = 'P';
		//Seconde porte
		x_porte = rand_a_b(x_haut + 1, x_bas - 1);
		matrice[x_porte][y_gauche] = 'P';

		//remplissage de la structure piece24
		piece24.x_haut = x_haut;
		piece24.y_gauche = y_gauche;

		piece24.x_porte1 = x_haut - 1;
		piece24.y_porte1 = y_porte;
		piece24.position_p1 = 'h';

		piece24.x_porte2 = x_porte;
		piece24.y_porte2 = y_gauche;
		piece24.position_p2 = 'v';
	}
}

/*!
*	
*	\fn void map_niveau2(char map[O][P])
*	\brief Fonction de création de la map du niveau 2.
*	\param matrice Matrice contenant la map du niveau 2.
*
*/
void map_niveau2(char map[O][P]){

	int x_haut_p1 = rand_a_b(3, 8), y_gauche_p1 = rand_a_b(3, 8);
	int x_haut_p2 = rand_a_b(5, 10), y_gauche_p2 = rand_a_b(32, 45);
	int x_haut_p3 = rand_a_b(27, 32), y_gauche_p3 = rand_a_b(3, 8);
	int x_haut_p4 = rand_a_b(27, 37), y_gauche_p4 = rand_a_b(32, 45);

	/* Création de la première pièce */
	creer_piece2(map, x_haut_p1, y_gauche_p1, 5, 15, 7, 11, 1);
	
	/* Création de la deuxième pièce */
	creer_piece2(map, x_haut_p2, y_gauche_p2, 7, 15, 4, 9, 2);
	
	/* Création de la troisième pièce */
	creer_piece2(map, x_haut_p3, y_gauche_p3, 8, 13, 9, 15, 3);
	
	/* Création de la quatrième pièce */
	creer_piece2(map, x_haut_p4, y_gauche_p4, 8, 13, 9, 13, 4);

	couloir2(map, piece21, piece22);
	couloir2(map, piece22, piece23);
	couloir2(map, piece23, piece24);
}

/*int main(){
	int i, j;
	char map[N][M];

	//Appel de la fonction qui créé le tour de la map
	creer_map(map);

	map_niveau2(map);

	//Affichage de la map
	for(i = 0; i < N; i++){
		for(j = 0; j < M; j++){
			printf("%c",map[i][j]);
		}
		printf("\n");
	}
}*/
