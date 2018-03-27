#include <stdio.h>
#include <stdlib.h>
#include<time.h>


#define N 30
#define M 50

typedef struct piece_s{
	int x_haut;
	int y_gauche;
	int x_porte1;
	int y_porte1;
	char position_p1;			//vaut h (si la porte est sur le coté haut ou bas de la piece) ou v (si la porte est sur le coté droit ou gauche de la piece)
	int x_porte2;
	int y_porte2;
	char position_p2;			//vaut h (si la porte est sur le coté haut ou bas de la piece) ou v (si la porte est sur le coté droit ou gauche de la piece)
} piece_t;


int rand_a_b(int a, int b)
{
	return rand()%(b-a) +a;
}

void creer_map(char matrice[N][M], int * x, int * y, int * x2, int * y2)
{

	int i, j;

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

	matrice[*x][*y] = 'p';
	matrice[*x2][*y2] = 'p';
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

/*int dijkstra_rec(int compt[N][M], char matrice[N][M], int x, int y){
	
}*/

void dijkstra(int compt[N][M], piece_t piece1, piece_t piece2, int x, int y, int val)  //x, y et val doivent être initialisés à 0 lors du premier appel de la fonction, leurs valeurs sera modifée dans la fonction suite à la récursivité.
{
	if (compt[x][y] == 0){
		if (piece1.position_p2 == 'h' && piece1.y_porte2 < piece2.y_porte1){					//cas où les deux portes sont sur des bords horizontals et que la porte destination est vers la droite

			if (val == 0){																		//si nous somme au premier appel de la fonction (donc que val == 0), on modifie les valuers de x et de y pour commencer l'algorithme deux cases en dessous de la porte de la pièce 1 et on met val à 1
				x = piece1.x_porte2 + 2;
				y = piece1.y_porte2;
				val ++;
			}
			
			compt[x][y] = val;																	//dans tous les cas, on inscrit la valeur de la case dans a matrice compt

			if (x < piece2.x_porte1 - 2){
				if (y > piece2.y_porte1)
					dijkstra(compt, piece1, piece2, x, y - 1, val + 1);	
				dijkstra(compt, piece1, piece2, x + 1 , y, val + 1);

			}
		}
/*---------------------------------------------------------------------*/
		if (piece1.position_p2 == 'h' && piece1.y_porte2 > piece2.y_porte1){					//cas où les deux portes sont sur des bords horizontals et que la porte destination est vers la droite
			
			if (val == 0){																		//si nous somme au premier appel de la fonction (donc que val == 0), on modifie les valuers de x et de y pour commencer l'algorithme deux cases en dessous de la porte de la pièce 1 et on met val à 1
				x = piece1.x_porte2 + 2;
				y = piece1.y_porte2;
				val ++;
			}
			
			compt[x][y] = val;																	//dans tous les cas, on inscrit la valeur de la case dans a matrice compt

			if (x < piece2.x_porte1 - 2){
				if (y < piece2.y_porte1)
					dijkstra(compt, piece1, piece2, x, y + 1, val + 1);	
				dijkstra(compt, piece1, piece2, x + 1, y, val + 1);

			}
		}
/*---------------------------------------------------------------------*/

		if (piece1.position_p2 == 'v' && piece1.x_porte2 < piece2.x_porte1){					//cas où les deux portes sont sur des bords horizontals et que la porte destination est vers la droite
			
			if (val == 0){																		//si nous somme au premier appel de la fonction (donc que val == 0), on modifie les valuers de x et de y pour commencer l'algorithme deux cases en dessous de la porte de la pièce 1 et on met val à 1
				x = piece1.x_porte2;
				y = piece1.y_porte2 + 2;
				val ++;
			}
			
			compt[x][y] = val;																	//dans tous les cas, on inscrit la valeur de la case dans a matrice compt

			if (y < piece2.y_porte1 - 2){
				if (x > piece2.x_porte1)
					dijkstra(compt, piece1, piece2, x - 1, y, val + 1);	
				dijkstra(compt, piece1, piece2, x, y + 1, val + 1);

			}
		}
/*---------------------------------------------------------------------*/
		if (piece1.position_p2 == 'v' && piece1.x_porte2 > piece2.x_porte1){					//cas où les deux portes sont sur des bords horizontals et que la porte destination est vers la droite
			
			if (val == 0){																		//si nous somme au premier appel de la fonction (donc que val == 0), on modifie les valuers de x et de y pour commencer l'algorithme deux cases en dessous de la porte de la pièce 1 et on met val à 1
				x = piece1.x_porte2;
				y = piece1.y_porte2 + 2;
				val ++;
			}
			
			compt[x][y] = val;																	//dans tous les cas, on inscrit la valeur de la case dans a matrice compt

			if (y < piece2.y_porte1 - 2){
				if (x < piece2.x_porte1)
					dijkstra(compt, piece1, piece2, x + 1, y, val + 1);	
				dijkstra(compt, piece1, piece2, x, y + 1, val + 1);

			}
		}
/*---------------------------------------------------------------------*/
		if (piece1.position_p2 == 'h' && piece1.y_porte2 == piece2.y_porte1){					//cas où les deux portes sont sur des bords horizontals et que la porte destination est vers la droite
			
			if (val == 0){																		//si nous somme au premier appel de la fonction (donc que val == 0), on modifie les valuers de x et de y pour commencer l'algorithme deux cases en dessous de la porte de la pièce 1 et on met val à 1
				x = piece1.x_porte2 + 2;
				y = piece1.y_porte2;
				val ++;
			}
			
			compt[x][y] = val;																	//dans tous les cas, on inscrit la valeur de la case dans a matrice compt
			while (y < piece2.y_porte1 - 2){
				y++;
				val ++;
				compt[x][y] = val;
			}
			
		}

		if (piece1.position_p2 == 'v' && piece1.x_porte2 == piece2.x_porte1){					//cas où les deux portes sont sur des bords horizontals et que la porte destination est vers la droite	
			
			if (val == 0){																		//si nous somme au premier appel de la fonction (donc que val == 0), on modifie les valuers de x et de y pour commencer l'algorithme deux cases en dessous de la porte de la pièce 1 et on met val à 1
				x = piece1.x_porte2;
				y = piece1.y_porte2 + 2;
				val ++;
			}
			
			compt[x][y] = val;																	//dans tous les cas, on inscrit la valeur de la case dans a matrice compt
			while (x < piece2.x_porte1-2){
				x++;
				val ++;
				compt[x][y] = val;
			}
		}

	}

}

void choisir_case(int compt, int *x, int *y){
	int alea = rand();
	if (alea % 2 == 2){
		*x = *x +1;
	}
	else {
		*y = *y +1;
	}
}

void couloir(int compt, char matrice, int x, int y, int x2, int y2){							//x = piece1.x_porte2; y = piece1.y_porte2; x2 = piece2.x_porte1; y2 = piece2.y_porte1;
	
	int alea;
	if (piece1.poisition_p2 == 'h'){
		alea = rand();
		x = x + 2;
		x2 = x2 -2;
		while (x < x2){
			if (alea % 2 == 2){


		}
	}
		
}

int main(){
	srand(time(NULL));

	
	char matrice[N][M];
	int compt[N][M];
	creer_map(matrice, x, y, x2, y2);
	/*remplir_matrice(compt);
	dijkstra(compt);
	afficher_matrice(matrice);
	afficher_matrice_int(compt);*/
}