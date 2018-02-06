#include<stdio.h>
#include"create_map.h"

void creer_piece1(char matrice[N][M]){

	/*Appel de la fonction qui créer le tour de la map*/
	creer_map(matrice);

	int i, j;
	
	/*Creation d'une piece en haut à gauche de la map*/
	for(i = 4; i < 12; i++){
		for(j = 5; j < 15; j++){
			matrice[i][j] = ' ';
		}
	}

	/*Mur de gauche de la pièce*/
	for(i = 4; i < 12; i++){
		j = 4;
		matrice[i][j] = '|';
	}

	/*Mur de droite de la pièce*/
	for(i =  4; i < 12; i++){
		j = 15;
		matrice[i][j] = '|';
	}

	/*Angles des pièces*/
	matrice[3][4] = '+';
	matrice[3][15] = '+';
	matrice[12][4] = '+';
	matrice[12][15] = '+';

	/*Mur du haut de la pièce*/
	for(j = 5; j < 15; j++){
		i = 3;
		matrice[i][j] = '-';
	}

	/*Mur du bas de la pièce*/
	for(j = 5; j < 15; j++){
		i = 12;
		matrice[i][j] = '-';
	}
}

void creer_piece2(char matrice[N][M]){

	int i, j;
	
	/*Creation d'une piece en haut à droite de la map*/
	for(i = 5; i < 13; i++){
		for(j = 25; j < 40; j++){
			matrice[i][j] = ' ';
		}
	}

	//Mur de gauche de la pièce
	for(i = 5; i < 13; i++){
		j = 24;
		matrice[i][j] = '|';
	}

	//Mur de droite de la pièce
	for(i =  5; i < 13; i++){
		j = 40;
		matrice[i][j] = '|';
	}

	//Angles des pièces
	matrice[4][24] = '+';
	matrice[4][40] = '+';
	matrice[13][24] = '+';
	matrice[13][40] = '+';

	//Mur du haut de la pièce
	for(j = 25; j < 40; j++){
		i = 4;
		matrice[i][j] = '-';
	}

	//Mur du bas de la pièce
	for(j = 25; j < 40; j++){
		i = 13;
		matrice[i][j] = '-';
	}
}

void creer_piece3(char matrice[N][M]){

	int i, j;
	
	/*Creation d'une piece en bas de la map*/
	for(i = 18; i < 25; i++){
		for(j = 10; j < 44; j++){
			matrice[i][j] = ' ';
		}
	}

	//Mur de gauche de la pièce
	for(i = 18; i < 25; i++){
		j = 9;
		matrice[i][j] = '|';
	}

	//Mur de droite de la pièce
	for(i =  18; i < 25; i++){
		j = 44;
		matrice[i][j] = '|';
	}

	//Angles des pièces
	matrice[17][9] = '+';
	matrice[17][44] = '+';
	matrice[25][9] = '+';
	matrice[25][44] = '+';

	//Mur du haut de la pièce
	for(j = 10; j < 44; j++){
		i = 17;
		matrice[i][j] = '-';
	}

	//Mur du bas de la pièce
	for(j = 10; j < 44; j++){
		i = 25;
		matrice[i][j] = '-';
	}
}

int main(){
	int i, j;
	char map[N][M];
	creer_piece1(map);
	creer_piece2(map);
	creer_piece3(map);

	//Affichage de la map
	for(i = 0; i < N; i++){
		for(j = 0; j < M; j++){
			printf("%c",map[i][j]);
		}
		printf("\n");
	}
}