#include<stdio.h>
#include "rogue_like.h"

/**
*	Création d'une première pièce en haut à gauche de la map
*/
void creer_piece21(char matrice[A][B]){

	int i, j;
	int x_haut = 5;
	int x_bas = 15;
	int y_gauche = 7;
	int y_droite = 25;
	
	//Creation d'une piece en haut à gauche de la map
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
*	Création d'une pièce, en haut à droite de la map
*/
void creer_piece22(char matrice[A][B]){

	int i, j;
	int x_haut = 10;
	int x_bas = 25;
	int y_gauche = 35;
	int y_droite = 55;
	
	//Creation d'une piece en haut à droite de la map
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
*	Création d'une pièce, sur la gauche de la map
*/
void creer_piece23(char matrice[A][B]){

	int i, j;
	int x_haut = 22;
	int x_bas = 32;
	int y_gauche = 5;
	int y_droite = 20;
	
	//Creation d'une piece sur la gauche de la map
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
*	Création d'une pièce, en bas de la map
*/
void creer_piece24(char matrice[A][B]){

	int i, j;
	int x_haut = 37;
	int x_bas = 46;
	int y_gauche = 20;
	int y_droite = 53;
	
	//Creation d'une piece en bas de la map
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
