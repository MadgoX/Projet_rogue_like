#include<stdio.h>
#include "rogue_like.h"

/**
*	Création d'une première pièce en haut à gauche de la map
*/
void creer_piece31(char matrice[C][D]){

	int i, j;
	int x_haut = 5;
	int x_bas = 12;
	int y_gauche = 5;
	int y_droite = 22;
	
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
void creer_piece32(char matrice[C][D]){

	int i, j;
	int x_haut = 8;
	int x_bas = 19;
	int y_gauche = 30;
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
void creer_piece33(char matrice[C][D]){

	int i, j;
	int x_haut = 25;
	int x_bas = 35;
	int y_gauche = 6;
	int y_droite = 31;
	
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
*	Création d'une pièce, en bas à gauche de la map
*/
void creer_piece34(char matrice[C][D]){

	int i, j;
	int x_haut = 43;
	int x_bas = 55;
	int y_gauche = 8;
	int y_droite = 26;
	
	//Creation d'une piece en bas à gauche de la map
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
*	Création d'une pièce, à droite de la map
*/
void creer_piece35(char matrice[C][D]){

	int i, j;
	int x_haut = 28;
	int x_bas = 50;
	int y_gauche = 39;
	int y_droite = 54;
	
	//Creation d'une piece à droite de la map
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
