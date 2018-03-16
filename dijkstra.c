#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#define N 30
#define M 50

int rand_a_b(int a, int b)
{
	return rand()%(b-a) +a;
}

void creer_map(char matrice[N][M])
{

	int i, j;
	int x = rand_a_b(1,N-1);
	int y = rand_a_b(1,M-1);
	int x2 = rand_a_b(1,N-1);
	int y2 = rand_a_b(1,M-1);

	for(i=0; i<N; i++){
		for(j=0; j<M; j++){
			matrice[i][j]=' ';
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

	matrice[x][y] = 'p';
	matrice[x2][y2] = 'p';
}

void remplir_matrice(int matrice[N][M]){
	for(int i = 0; i<N; i++){
		for(int j = 0; j<M; j++){
			matrice[i][j] = 0;
		}
	}
}

void afficher_matrice(char matrice[N][M]){
	for(int i = 0; i<N; i++){
		for(int j = 0; j<M; j++){
			printf("%c ", matrice[i][j]);
		}
		printf("\n");
	}
}

void afficher_matrice_int(int matrice[N][M]){
	for(int i = 0; i<N; i++){
		for(int j = 0; j<M; j++){
			printf("%d ", matrice[i][j]);
		}
		printf("\n");
	}
}

int dijkstra(int compt[N][M], char matrice[N][M])
{
	int x, y, nb_portes = 0, i, j;

	remplir_matrice(compt);

	
	

	printf("%d    %d   \n", x, y);


	

	afficher_matrice_int(compt);

}

int main(){
	srand(time(NULL));
	char matrice[N][M];
	int compt[N][M];
	creer_map(matrice);
	dijkstra(compt, matrice);
	afficher_matrice(matrice);
}