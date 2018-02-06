#include<stdio.h>
#define N 30
#define M 100

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

void creer_piece1(char matrice[N][M]){

	//Appel de la fonction qui créer le tour de la map
	creer_map(matrice);

	int i, j;
	
	//Creation d'une piece en haut à gauche de la map
	for(i = 5; i < 15; i++){
		for(j = 7; j < 25; j++){
			matrice[i][j] = ' ';
		}
	}

	//Mur de gauche de la pièce
	for(i = 5; i < 15; i++){
		j = 6;
		matrice[i][j] = '|';
	}

	//Mur de droite de la pièce
	for(i =  5; i < 15; i++){
		j = 25;
		matrice[i][j] = '|';
	}

	//Angles des pièces
	matrice[4][6] = '+';
	matrice[4][25] = '+';
	matrice[15][6] = '+';
	matrice[15][25] = '+';

	//Mur du haut de la pièce
	for(j = 7; j < 25; j++){
		i = 4;
		matrice[i][j] = '-';
	}

	//Mur du bas de la pièce
	for(j = 7; j < 25; j++){
		i = 15;
		matrice[i][j] = '-';
	}
}

int main(){
	int i, j;
	char map[N][M];
	creer_piece1(map);

	//Affichage de la map
	for(i = 0; i < N; i++){
		for(j = 0; j < M; j++){
			printf("%c",map[i][j]);
		}
		printf("\n");
	}
}