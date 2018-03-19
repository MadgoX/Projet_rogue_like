#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 50
#define M 60

//Pieces 1, 2, 3 et 4 du niveau 2
piece_t piece21, piece22, piece23, piece24;

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
void creer_piece2(char matrice[N][M], int x_haut, int y_gauche, int min_larg, int max_larg, int min_haut, int max_haut, int num_piece){
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

		piece21.x_porte1 = piece21.y_porte1 = piece21.position_p1 = NULL;

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

		piece23.x_porte2 = piece23.y_porte2 = piece23.position_p2 = NULL;
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

/* Création de la map du niveau 1 */
void map_niveau2(char map[N][M]){

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
