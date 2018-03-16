#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 50
#define M 60

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

int rand_a_b(int a, int b){

    return rand()%(b-a) +a;

}

/* Fonction de création d'une pièce */
void creer_piece(char matrice[N][M], int x_haut, int y_gauche, int min_larg, int max_larg, int min_haut, int max_haut){
	//x_haut et y_gauche sont les coordonnées du coin haut gauche de la pièce

	int i, j;
	int x_bas, y_droite;

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
}

/* Création de la map du niveau 1 */
void map_niveau2(char map[N][M]){

	/* Création de la première pièce */
	creer_piece(map, rand_a_b(3, 8), rand_a_b(3, 8), 5, 15, 7, 11);
	
	/* Création de la deuxième pièce */
	creer_piece(map, rand_a_b(5, 10), rand_a_b(32, 45), 7, 15, 4, 9);
	
	/* Création de la troisième pièce */
	creer_piece(map, rand_a_b(27, 32), rand_a_b(3, 8), 8, 13, 9, 15);
	
	/* Création de la quatrième pièce */
	creer_piece(map, rand_a_b(27, 37), rand_a_b(32, 45), 8, 13, 9, 13);
}

int main(){
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
}
