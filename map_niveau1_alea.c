#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 30
#define M 50

/*
*	Créer 3 types de pièces :
*		- de petite taille
*		- de moyenne taille
*		- de grande taille
*/

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

/*int rand_a_b(int a, int b){

    return rand()%(b-a) +a;

}*/

/*
*	Fonction qui génère un nombre aléatoire
*	Paramètres :
*		- a et b : bornes entre lesquelles le nombre aléatoire sera généré
*		- tab : tableau contenant tous les nombres aléatoires générés précédement
*		- nb_val : nombre de valeurs utiles dans le tableau
*/
int alea_a_b(int a, int b, int tab[20]){
    printf("Debut de la fonction rand_a_b.\n");

	int nb = rand()%(b-a) +a;						//génération d'un nombre aléatoire
	int i;

	printf("Parcours du tableau.\n");
	//Parcours du tableau tant qu'on n'en sort pas ou que l'on ne trouve pas la valeur de nb
    for(i = 0; i < 20 || tab[i] != 0 || tab[i] != nb; i++);
	/*{
		if(tab[i] == nb){
			break;
		}
	}*/
	printf("Fin du for de rand_a_b.\n");

	if(tab[i] == nb){
		printf("Appel récursif de rand_a_b.\n");
		nb = alea_a_b(a, b, tab);
	}
	else if(tab[i] == 0){
		printf("Dans rand_a_b : placement du nombre aléatoire dans le tableau.\n");
		tab[i] = nb;
		printf("Dans rand_a_b : nombre aléatoire placé dans le tableau.\n");
		return nb;
	}
}

void creer_piece(char matrice[N][M], int x_haut, int y_gauche, int tab[20]){	//x_haut et y_gauche sont les coordonnées du coin haut gauche de la pièce

	int i, j;
	int x_bas, y_droite;

	srand(time(NULL)); 										// initialisation de rand

	x_bas = alea_a_b(x_haut + 4, x_haut + 10, tab);
	y_droite = alea_a_b(y_gauche + 4, y_gauche + 9, tab);
	
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

	/*Appel de la fonction qui créé le tour de la map*/
	creer_map(map);

	creer_piece(map, 3, 4, tab);
	creer_piece(map, 15, 16, tab);

	//Affichage de la map
	for(i = 0; i < N; i++){
		for(j = 0; j < M; j++){
			printf("%c",map[i][j]);
		}
		printf("\n");
	}
}
