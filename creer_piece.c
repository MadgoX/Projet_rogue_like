#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 30
#define M 50

void creer_map(char matrice[N][M])
{

	int i, j;
	char res;
	
	for(i=0; i<N; i++){
		for(j=0; j<M; j++){
			matrice[i][j]='.';
		}
	}

	i=0;
	for(j=1; j<M-1; j++){
		matrice[i][j]='=';
	}
	
	j=0;
	for(i=1; i<N-1; i++){
		matrice[i][j]='#';
	}

	j=M-1;
	for(i=1; i<N-1; i++){
		matrice[i][j]='#';
	}

	i=N-1;
	for(j=1; j<M-1; j++){
		matrice[i][j]='=';
	}
	
	i=0;
	j=0;
	matrice[i][j]='+';

	i=N-1;
	j=M-1;
	matrice[i][j]='+';
	
	i=N-1;
	j=0;
	matrice[i][j]='+';

	i=0;
	j=M-1;
	matrice[i][j]='+';

}

/*Génère un nombre aléatoire entre a et b*/
int rand_a_b(int a, int b){

    return rand()%(b-a) +a;

}

/* Fonction de création d'une petite pièce */
void creer_piece(char matrice[N][M], int x_haut, int y_gauche, int min, int max){
	//x_haut et y_gauche sont les coordonnées du coin haut gauche de la pièce

	int i, j;
	int x_bas, y_droite;

	// initialisation de rand
	srand(time(NULL));

	x_bas = x_haut + rand_a_b(min, max);
	y_droite = y_gauche + rand_a_b(min, max);
	
	/*Creation d'une piece en haut à gauche de la map*/
	for(i = x_haut; i < x_bas; i++){
		for(j = y_gauche; j < y_droite; j++){
			matrice[i][j] = ' ';
		}
	}

	/*Mur de gauche de la pièce*/
	for(i = x_haut; i < x_bas; i++){
		j = x_haut;
		matrice[i][j] = '|';
	}

	/*Mur de droite de la pièce*/
	for(i =  x_haut; i < x_bas; i++){
		j = y_droite;
		matrice[i][j] = '|';
	}

	/*Angles des pièces*/
	matrice[x_haut-1][x_haut] = '+';
	matrice[x_haut-1][y_droite] = '+';
	matrice[x_bas][x_haut] = '+';
	matrice[x_bas][y_droite] = '+';

	/*Mur du haut de la pièce*/
	for(j = x_haut+1; j < y_droite; j++){
		i = x_haut-1;
		matrice[i][j] = '-';
	}

	/*Mur du bas de la pièce*/
	for(j = x_haut+1; j < y_droite; j++){
		i = x_bas;
		matrice[i][j] = '-';
	}
}

int main(){
	int i, j;
	char map[N][M];
	int tab[20];

	for(i = 0; i < 20; i++){
		tab[i] = 0;
	}

	//Appel de la fonction qui créé le tour de la map
	creer_map(map);

	creer_piece(map, 3, 4, 7, 10);
	creer_piece(map, 15, 16, 10, 12);

	//Affichage de la map
	for(i = 0; i < N; i++){
		for(j = 0; j < M; j++){
			printf("%c",map[i][j]);
		}
		printf("\n");
	}
}