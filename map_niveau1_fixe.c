#include<stdio.h>
#include"rogue_like.h"

/**
*	Création d'une première pièce, en haut à gauche de la map
*/
void creer_piece1(char matrice[N][M]){

	int i, j;
	int x_haut = 4;
	int x_bas = 12;
	int y_gauche = 5;
	int y_droite = 15;
	
	/*Creation d'une piece en haut à gauche de la map*/
	for(i = x_haut; i < x_bas; i++){
		for(j = y_gauche; j < y_droite; j++){
			matrice[i][j] = ' ';
		}
	}

	/*Mur de gauche de la pièce*/
	for(i = x_haut; i < x_bas; i++){
		j = y_gauche-1;
		matrice[i][j] = '|';
	}

	/*Mur de droite de la pièce*/
	for(i =  x_haut; i < x_bas; i++){
		j = y_droite;
		matrice[i][j] = '|';
	}

	/*Angles des pièces*/
	matrice[x_haut-1][y_gauche-1] = '+';
	matrice[x_haut-1][y_droite] = '+';
	matrice[x_bas][y_gauche-1] = '+';
	matrice[x_bas][y_droite] = '+';

	/*Mur du haut de la pièce*/
	for(j = y_gauche; j < y_droite; j++){
		i = x_haut-1;
		matrice[i][j] = '-';
	}

	/*Mur du bas de la pièce*/
	for(j = y_gauche; j < y_droite; j++){
		i = x_bas;
		matrice[i][j] = '-';
	}
}

/**
*	Création d'une seconde pièce, en haut à droite de la map
*/
void creer_piece2(char matrice[N][M]){

	int i, j;
	int x_haut = 5;
	int x_bas = 13;
	int y_gauche = 25;
	int y_droite = 40;
	
	/*Creation d'une piece en haut à droite de la map*/
	for(i = x_haut; i < x_bas; i++){
		for(j = y_gauche; j < y_droite; j++){
			matrice[i][j] = ' ';
		}
	}

	//Mur de gauche de la pièce
	for(i = x_haut; i < x_bas; i++){
		j = y_gauche-1;
		matrice[i][j] = '|';
	}

	//Mur de droite de la pièce
	for(i =  x_haut; i < x_bas; i++){
		j = y_droite;
		matrice[i][j] = '|';
	}

	//Angles des pièces
	matrice[x_haut-1][y_gauche-1] = '+';
	matrice[x_haut-1][y_droite] = '+';
	matrice[x_bas][y_gauche-1] = '+';
	matrice[x_bas][y_droite] = '+';

	//Mur du haut de la pièce
	for(j = y_gauche; j < y_droite; j++){
		i = x_haut-1;
		matrice[i][j] = '-';
	}

	//Mur du bas de la pièce
	for(j = y_gauche; j < y_droite; j++){
		i = x_bas;
		matrice[i][j] = '-';
	}
}

/**
*	Création d'une troisième pièce, dans le bas de la map
*/
void creer_piece3(char matrice[N][M]){

	int i, j;
	int x_haut = 18;
	int x_bas = 25;
	int y_gauche = 10;
	int y_droite = 44;
	
	/*Creation d'une piece en haut à droite de la map*/
	for(i = x_haut; i < x_bas; i++){
		for(j = y_gauche; j < y_droite; j++){
			matrice[i][j] = ' ';
		}
	}

	//Mur de gauche de la pièce
	for(i = x_haut; i < x_bas; i++){
		j = y_gauche-1;
		matrice[i][j] = '|';
	}

	//Mur de droite de la pièce
	for(i =  x_haut; i < x_bas; i++){
		j = y_droite;
		matrice[i][j] = '|';
	}

	//Angles des pièces
	matrice[x_haut-1][y_gauche-1] = '+';
	matrice[x_haut-1][y_droite] = '+';
	matrice[x_bas][y_gauche-1] = '+';
	matrice[x_bas][y_droite] = '+';

	//Mur du haut de la pièce
	for(j = y_gauche; j < y_droite; j++){
		i = x_haut-1;
		matrice[i][j] = '-';
	}

	//Mur du bas de la pièce
	for(j = y_gauche; j < y_droite; j++){
		i = x_bas;
		matrice[i][j] = '-';
	}
}
