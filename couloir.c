/*!
*
*	\file main.c
*	\brief Fonction main du projet
*	\author Lucien BOUYEURE, Romane BUON, Yann PAULMERY
*	\version 0.1
*
*/

#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "rogue_like.h"

static
void remplir_matrice_compt1(int compt[N][M]){
	for(int i = 0; i < N; i++){
		for (int j = 0; j < M; j++)
			compt[i][j] = 0;
	}
}

static
void remplir_matrice_compt2(int compt[O][P]){
	for(int i = 0; i < O; i++){
		for (int j = 0; j < P; j++)
			compt[i][j] = 0;
	}
}

static
void remplir_matrice_compt3(int compt[M][Q]){
	for(int i = 0; i < M; i++){
		for (int j = 0; j < Q; j++)
			compt[i][j] = 0;
	}
}

static
void afficher_matrice_int(int matrice[N][M]){
	for(int i = 0; i<N; i++){
		for(int j = 0; j<M; j++){
			printf("%d ", matrice[i][j]);
		}
		printf("\n");
	}
}


void dijkstra1(int compt[N][M], piece_t piece1, piece_t piece2, int x, int y, int val)  //x, y et val doivent être initialisés à 0 lors du premier appel de la fonction, leurs valeurs sera modifée dans la fonction suite à la récursivité.
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
				if (y < piece2.y_porte1){
					dijkstra1(compt, piece1, piece2, x, y + 1, val + 1);	
				}
				dijkstra1(compt, piece1, piece2, x + 1 , y, val + 1);

			}
		}

		if (piece1.position_p2 == 'h' && piece1.y_porte2 > piece2.y_porte1){					//cas où les deux portes sont sur des bords horizontals et que la porte destination est vers la droite
			
			if (val == 0){																		//si nous somme au premier appel de la fonction (donc que val == 0), on modifie les valuers de x et de y pour commencer l'algorithme deux cases en dessous de la porte de la pièce 1 et on met val à 1
				x = piece1.x_porte2 + 2;
				y = piece1.y_porte2;
				val ++;
			}
			
			compt[x][y] = val;																	//dans tous les cas, on inscrit la valeur de la case dans a matrice compt

			if (x < piece2.x_porte1 - 2){
				if (y > piece2.y_porte1)
					dijkstra1(compt, piece1, piece2, x, y - 1, val + 1);	
				dijkstra1(compt, piece1, piece2, x + 1, y, val + 1);

			}
		}


		if (piece1.position_p2 == 'v' && piece1.x_porte2 < piece2.x_porte1){					//cas où les deux portes sont sur des bords horizontals et que la porte destination est vers la droite
			
			if (val == 0){																		//si nous somme au premier appel de la fonction (donc que val == 0), on modifie les valuers de x et de y pour commencer l'algorithme deux cases en dessous de la porte de la pièce 1 et on met val à 1
				x = piece1.x_porte2;
				y = piece1.y_porte2 + 2;
				val ++;
			}
			
			compt[x][y] = val;																	//dans tous les cas, on inscrit la valeur de la case dans a matrice compt

			if (y < piece2.y_porte1 - 2){
				if (x < piece2.x_porte1)
					dijkstra1(compt, piece1, piece2, x + 1, y, val + 1);	
				dijkstra1(compt, piece1, piece2, x, y + 1, val + 1);

			}
		}

		if (piece1.position_p2 == 'v' && piece1.x_porte2 > piece2.x_porte1){					//cas où les deux portes sont sur des bords horizontals et que la porte destination est vers la droite
			
			if (val == 0){																		//si nous somme au premier appel de la fonction (donc que val == 0), on modifie les valuers de x et de y pour commencer l'algorithme deux cases en dessous de la porte de la pièce 1 et on met val à 1
				x = piece1.x_porte2;
				y = piece1.y_porte2 + 2;
				val ++;
			}
			
			compt[x][y] = val;																	//dans tous les cas, on inscrit la valeur de la case dans a matrice compt

			if (y < piece2.y_porte1 - 2){
				if (x > piece2.x_porte1)
					dijkstra1(compt, piece1, piece2, x - 1, y, val + 1);	
				dijkstra1(compt, piece1, piece2, x, y + 1, val + 1);

			}
		}
		if (piece1.position_p2 == 'h' && piece1.y_porte2 == piece2.y_porte1){					//cas où les deux portes sont sur des bords horizontals et que la porte destination est vers la droite
			
			if (val == 0){																		//si nous somme au premier appel de la fonction (donc que val == 0), on modifie les valuers de x et de y pour commencer l'algorithme deux cases en dessous de la porte de la pièce 1 et on met val à 1
				x = piece1.x_porte2 + 2;
				y = piece1.y_porte2;
				val ++;
			}
			
			compt[x][y] = val;																	//dans tous les cas, on inscrit la valeur de la case dans a matrice compt
			while (x < piece2.x_porte1 - 2){
				x++;
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
			while (y < piece2.y_porte1-2){
				y++;
				val ++;
				compt[x][y] = val;
			}
		}

	}
}

void dijkstra2(int compt[O][P], piece_t piece1, piece_t piece2, int x, int y, int val)  //x, y et val doivent être initialisés à 0 lors du premier appel de la fonction, leurs valeurs sera modifée dans la fonction suite à la récursivité.
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
				if (y < piece2.y_porte1){
					dijkstra2(compt, piece1, piece2, x, y + 1, val + 1);	
				}
				dijkstra2(compt, piece1, piece2, x + 1 , y, val + 1);

			}
		}

		if (piece1.position_p2 == 'h' && piece1.y_porte2 > piece2.y_porte1){					//cas où les deux portes sont sur des bords horizontals et que la porte destination est vers la droite
			
			if (val == 0){																		//si nous somme au premier appel de la fonction (donc que val == 0), on modifie les valuers de x et de y pour commencer l'algorithme deux cases en dessous de la porte de la pièce 1 et on met val à 1
				x = piece1.x_porte2 + 2;
				y = piece1.y_porte2;
				val ++;
			}
			
			compt[x][y] = val;																	//dans tous les cas, on inscrit la valeur de la case dans a matrice compt

			if (x < piece2.x_porte1 - 2){
				if (y > piece2.y_porte1)
					dijkstra2(compt, piece1, piece2, x, y - 1, val + 1);	
				dijkstra2(compt, piece1, piece2, x + 1, y, val + 1);

			}
		}

		if (piece1.position_p2 == 'v' && piece1.x_porte2 < piece2.x_porte1){					//cas où les deux portes sont sur des bords horizontals et que la porte destination est vers la droite
			
			if (val == 0){																		//si nous somme au premier appel de la fonction (donc que val == 0), on modifie les valuers de x et de y pour commencer l'algorithme deux cases en dessous de la porte de la pièce 1 et on met val à 1
				x = piece1.x_porte2;
				y = piece1.y_porte2 + 2;
				val ++;
			}
			
			compt[x][y] = val;																	//dans tous les cas, on inscrit la valeur de la case dans a matrice compt

			if (y < piece2.y_porte1 - 2){
				if (x < piece2.x_porte1)
					dijkstra2(compt, piece1, piece2, x + 1, y, val + 1);	
				dijkstra2(compt, piece1, piece2, x, y + 1, val + 1);

			}
		}
		if (piece1.position_p2 == 'v' && piece1.x_porte2 > piece2.x_porte1){					//cas où les deux portes sont sur des bords horizontals et que la porte destination est vers la droite
			
			if (val == 0){																		//si nous somme au premier appel de la fonction (donc que val == 0), on modifie les valuers de x et de y pour commencer l'algorithme deux cases en dessous de la porte de la pièce 1 et on met val à 1
				x = piece1.x_porte2;
				y = piece1.y_porte2 + 2;
				val ++;
			}
			
			compt[x][y] = val;																	//dans tous les cas, on inscrit la valeur de la case dans a matrice compt

			if (y < piece2.y_porte1 - 2){
				if (x > piece2.x_porte1)
					dijkstra2(compt, piece1, piece2, x - 1, y, val + 1);	
				dijkstra2(compt, piece1, piece2, x, y + 1, val + 1);

			}
		}
		if (piece1.position_p2 == 'h' && piece1.y_porte2 == piece2.y_porte1){					//cas où les deux portes sont sur des bords horizontals et que la porte destination est vers la droite
			
			if (val == 0){																		//si nous somme au premier appel de la fonction (donc que val == 0), on modifie les valuers de x et de y pour commencer l'algorithme deux cases en dessous de la porte de la pièce 1 et on met val à 1
				x = piece1.x_porte2 + 2;
				y = piece1.y_porte2;
				val ++;
			}
			
			compt[x][y] = val;																	//dans tous les cas, on inscrit la valeur de la case dans a matrice compt
			while (x < piece2.x_porte1 - 2){
				x++;
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
			while (y < piece2.y_porte1-2){
				y++;
				val ++;
				compt[x][y] = val;
			}
		}

	}
}

void dijkstra3(int compt[M][Q], piece_t piece1, piece_t piece2, int x, int y, int val)  //x, y et val doivent être initialisés à 0 lors du premier appel de la fonction, leurs valeurs sera modifée dans la fonction suite à la récursivité.
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
				if (y < piece2.y_porte1){
					dijkstra3(compt, piece1, piece2, x, y + 1, val + 1);	
				}
				dijkstra3(compt, piece1, piece2, x + 1 , y, val + 1);

			}
		}

		if (piece1.position_p2 == 'h' && piece1.y_porte2 > piece2.y_porte1){					//cas où les deux portes sont sur des bords horizontals et que la porte destination est vers la droite
			
			if (val == 0){																		//si nous somme au premier appel de la fonction (donc que val == 0), on modifie les valuers de x et de y pour commencer l'algorithme deux cases en dessous de la porte de la pièce 1 et on met val à 1
				x = piece1.x_porte2 + 2;
				y = piece1.y_porte2;
				val ++;
			}
			
			compt[x][y] = val;																	//dans tous les cas, on inscrit la valeur de la case dans a matrice compt

			if (x < piece2.x_porte1 - 2){
				if (y > piece2.y_porte1)
					dijkstra3(compt, piece1, piece2, x, y - 1, val + 1);	
				dijkstra3(compt, piece1, piece2, x + 1, y, val + 1);

			}
		}


		if (piece1.position_p2 == 'v' && piece1.x_porte2 < piece2.x_porte1){					//cas où les deux portes sont sur des bords horizontals et que la porte destination est vers la droite
			
			if (val == 0){																		//si nous somme au premier appel de la fonction (donc que val == 0), on modifie les valuers de x et de y pour commencer l'algorithme deux cases en dessous de la porte de la pièce 1 et on met val à 1
				x = piece1.x_porte2;
				y = piece1.y_porte2 + 2;
				val ++;
			}
			
			compt[x][y] = val;																	//dans tous les cas, on inscrit la valeur de la case dans a matrice compt

			if (y < piece2.y_porte1 - 2){
				if (x < piece2.x_porte1)
					dijkstra3(compt, piece1, piece2, x + 1, y, val + 1);	
				dijkstra3(compt, piece1, piece2, x, y + 1, val + 1);

			}
		}

		if (piece1.position_p2 == 'v' && piece1.x_porte2 > piece2.x_porte1){					//cas où les deux portes sont sur des bords horizontals et que la porte destination est vers la droite
			
			if (val == 0){																		//si nous somme au premier appel de la fonction (donc que val == 0), on modifie les valuers de x et de y pour commencer l'algorithme deux cases en dessous de la porte de la pièce 1 et on met val à 1
				x = piece1.x_porte2;
				y = piece1.y_porte2 + 2;
				val ++;
			}
			
			compt[x][y] = val;																	//dans tous les cas, on inscrit la valeur de la case dans a matrice compt

			if (y < piece2.y_porte1 - 2){
				if (x > piece2.x_porte1)
					dijkstra3(compt, piece1, piece2, x - 1, y, val + 1);	
				dijkstra3(compt, piece1, piece2, x, y + 1, val + 1);

			}
		}

		if (piece1.position_p2 == 'h' && piece1.y_porte2 == piece2.y_porte1){					//cas où les deux portes sont sur des bords horizontals et que la porte destination est vers la droite
			
			if (val == 0){																		//si nous somme au premier appel de la fonction (donc que val == 0), on modifie les valuers de x et de y pour commencer l'algorithme deux cases en dessous de la porte de la pièce 1 et on met val à 1
				x = piece1.x_porte2 + 2;
				y = piece1.y_porte2;
				val ++;
			}
			
			compt[x][y] = val;																	//dans tous les cas, on inscrit la valeur de la case dans a matrice compt
			while (x < piece2.x_porte1 - 2){
				x++;
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
			while (y < piece2.y_porte1-2){
				y++;
				val ++;
				compt[x][y] = val;
			}
		}

	}
}

void couloir1(char matrice[N][M], piece_t piece1, piece_t piece2)
{	
	int compt[N][M];
	remplir_matrice_compt1(compt);

	int x1 = piece1.x_porte2;
	int y1= piece1.y_porte2;
	char pos1 = piece1.position_p2;

	int x2 = piece2.x_porte1;
	int y2 = piece2.y_porte1;
	char pos2 = piece2.position_p1;
	int x, y, x_fin, y_fin;

	int alea;
	int val = 1;
	char orient_prec;

	dijkstra1(compt, piece1, piece2, 0, 0, 0);

	if (pos1 == 'h'){
		x = x1 + 2;
		y = y1;
		x_fin = x2 - 2;
		y_fin = y2;
		orient_prec = 'v';
		matrice[x1][y1-1] = '+';
		matrice[x2][y2+1] = '+';
		matrice[x2][y2-1] = '+';
		matrice[x1+1][y1+1] = '+';
		matrice[x1+1][y1-1] = '+';
		matrice[x2-1][y2+1] = '+';
		matrice[x2-1][y2-1] = '+';

		matrice[x1+1][y1] = ' ';
		matrice[x2-1][y2] = ' ';
	}

	else{
		x = x1;
		y = y1 + 2;
		x_fin = x2;
		y_fin = y2 - 2;
		orient_prec = 'h';
		matrice[x1+1][y1] = '+';
		matrice[x1-1][y1] = '+';
		matrice[x2+1][y2] = '+';
		matrice[x2-1][y2] = '+';
		matrice[x1+1][y1+1] = '+';
		matrice[x1-1][y1+1] = '+';
		matrice[x2+1][y2-1] = '+';
		matrice[x2-1][y2-1] = '+';

		matrice[x1][y1+1] = ' ';
		matrice[x2][y2-1] = ' ';
	}
	
	matrice[x][y] = ' ';
	matrice[x_fin][y_fin] = ' ';
	
	while ((x != x_fin) || (y != y_fin)){
		alea = rand_a_b(0,10);
		if (x1 < x2 && y1 < y2){
			if (alea %2 == 0){
				if (compt[x][y+1] == val + 1){
					if (orient_prec == 'v'){
						matrice[x][y-1] = '+';
						matrice[x+1][y] = '+';
						matrice[x+1][y-1] = '+';
					}
					else{
						matrice[x-1][y] = '+';
						matrice[x+1][y] = '+';
					}
					y++;
					orient_prec = 'h';
				}

				else{												//cas où on arrive a la limite et que le nombre aléatoire ne permet pas de continuer
					if (compt[x+1][y] == val + 1){
						if (orient_prec == 'h'){
							matrice[x][y+1] = '+';
							matrice[x-1][y] = '+';
							matrice[x-1][y+1] = '+';

						}
						else{
							matrice[x][y+1] = '+';
							matrice[x][y-1] = '+';
						}
						x++;
					}
					orient_prec = 'v';
				}
			}

			else{
				if (compt[x+1][y] == val + 1){
					if (orient_prec == 'h'){
						matrice[x][y+1] = '+';
						matrice[x-1][y] = '+';
						matrice[x-1][y+1] = '+';
					}
					else{
						matrice[x][y+1] = '+';
						matrice[x][y-1] = '+';
					}
					x++;
					orient_prec = 'v';

				}

				else{												//cas où on arrive a la limite et que le nombre aléatoire ne permet pas de continuer
					if (compt[x][y+1] == val + 1){
						if (orient_prec == 'v'){
							matrice[x][y-1] = '+';
							matrice[x+1][y] = '+';
							matrice[x+1][y-1] = '+';
						}
						else{
							matrice[x-1][y] = '+';
							matrice[x+1][y] = '+';
						}
						y++;
					}
					orient_prec = 'h';
				}
			}
		}
		else if (x1 > x2 && y1 < y2){
			if (alea %2 == 0){
				if (compt[x][y+1] == val + 1){
					if (orient_prec == 'v'){
						matrice[x][y-1] = '+';
						matrice[x-1][y] = '+';
						matrice[x-1][y-1] = '+';
					}
					else{
						matrice[x-1][y] = '+';
						matrice[x+1][y] = '+';
					}
					y++;
					orient_prec = 'h';
				}

				else{												//cas où on arrive a la limite et que le nombre aléatoire ne permet pas de continuer
					if (compt[x-1][y] == val + 1){
						if (orient_prec == 'h'){
							matrice[x+1][y] = '+';
							matrice[x][y+1] = '+';
							matrice[x+1][y+1] = '+';
						}
						else{
							matrice[x][y-1] = '+';
							matrice[x][y+1] = '+';
						}
						x--;
					}
					orient_prec = 'v';
				}
			}

			else{
				if (compt[x-1][y] == val + 1){
					if (orient_prec == 'h'){
						matrice[x+1][y] = '+';
						matrice[x][y+1] = '+';
						matrice[x+1][y+1] = '+';
					}
					else{
						matrice[x][y-1] = '+';
						matrice[x][y+1] = '+';
					}
					x--;
					orient_prec = 'v';
				}

				else{												//cas où on arrive a la limite et que le nombre aléatoire ne permet pas de continuer
					if (compt[x][y+1] == val + 1){
						if (orient_prec == 'v'){
							matrice[x][y-1] = '+';
							matrice[x-1][y] = '+';
							matrice[x-1][y-1] = '+';
						}
						else{
							matrice[x-1][y] = '+';
							matrice[x+1][y] = '+';
						}
						y++;
					}
					orient_prec = 'h';
				}
			}
		}

		else if (x1 < x2 && y1 > y2){
			if (alea %2 == 0){
				if (compt[x][y-1] == val + 1){
					if (orient_prec == 'v'){
						matrice[x][y+1] = '+';
						matrice[x+1][y] = '+';
						matrice[x+1][y+1] = '+';
					}
					else{
						matrice[x-1][y] = '+';
						matrice[x+1][y] = '+';
					}
					y--;
					orient_prec = 'h';
				}

				else{												//cas où on arrive a la limite et que le nombre aléatoire ne permet pas de continuer
					if (compt[x+1][y] == val + 1){
						if (orient_prec == 'h'){
							matrice[x-1][y] = '+';
							matrice[x][y-1] = '+';
							matrice[x-1][y-1] = '+';
						}
						else{
							matrice[x][y-1] = '+';
							matrice[x][y+1] = '+';
						}
						x++;
					}
					orient_prec = 'v';
				}
			}

			else{
				if (compt[x+1][y] == val + 1){
					if (orient_prec == 'h'){
						matrice[x-1][y] = '+';
						matrice[x][y-1] = '+';
						matrice[x-1][y-1] = '+';
					}
					else{
						matrice[x][y-1] = '+';
						matrice[x][y+1] = '+';
					}
					x++;
					orient_prec = 'v';
				}

				else{												//cas où on arrive a la limite et que le nombre aléatoire ne permet pas de continuer
					if (compt[x][y-1] == val + 1){
						if (orient_prec == 'v'){
							matrice[x][y+1] = '+';
							matrice[x+1][y] = '+';
							matrice[x+1][y+1] = '+';
						}
						else{
							matrice[x-1][y] = '+';
							matrice[x+1][y] = '+';
						}
						y--;
					}
					orient_prec = 'h';
				}
			}
		}
		matrice[x][y] = ' ';

		val++;		
	}
}


void couloir2(char matrice[O][P], piece_t piece1, piece_t piece2)
{	
	int compt[O][P];
	remplir_matrice_compt2(compt);

	int x1 = piece1.x_porte2;
	int y1= piece1.y_porte2;
	char pos1 = piece1.position_p2;

	int x2 = piece2.x_porte1;
	int y2 = piece2.y_porte1;
	char pos2 = piece2.position_p1;
	int x, y, x_fin, y_fin;

	int alea;
	int val = 1;
	char orient_prec;

	dijkstra2(compt, piece1, piece2, 0, 0, 0);

	if (pos1 == 'h'){
		x = x1 + 2;
		y = y1;
		x_fin = x2 - 2;
		y_fin = y2;
		orient_prec = 'v';
		matrice[x1][y1-1] = '+';
		matrice[x2][y2+1] = '+';
		matrice[x2][y2-1] = '+';
		matrice[x1+1][y1+1] = '+';
		matrice[x1+1][y1-1] = '+';
		matrice[x2-1][y2+1] = '+';
		matrice[x2-1][y2-1] = '+';

		matrice[x1+1][y1] = ' ';
		matrice[x2-1][y2] = ' ';
	}

	else{
		x = x1;
		y = y1 + 2;
		x_fin = x2;
		y_fin = y2 - 2;
		orient_prec = 'h';
		matrice[x1+1][y1] = '+';
		matrice[x1-1][y1] = '+';
		matrice[x2+1][y2] = '+';
		matrice[x2-1][y2] = '+';
		matrice[x1+1][y1+1] = '+';
		matrice[x1-1][y1+1] = '+';
		matrice[x2+1][y2-1] = '+';
		matrice[x2-1][y2-1] = '+';

		matrice[x1][y1+1] = ' ';
		matrice[x2][y2-1] = ' ';
	}
	
	matrice[x][y] = ' ';
	matrice[x_fin][y_fin] = ' ';
	
	while ((x != x_fin) || (y != y_fin)){
		alea = rand_a_b(0,10);
		if (x1 < x2 && y1 < y2){
			if (alea %2 == 0){
				if (compt[x][y+1] == val + 1){
					if (orient_prec == 'v'){
						matrice[x][y-1] = '+';
						matrice[x+1][y] = '+';
						matrice[x+1][y-1] = '+';
					}
					else{
						matrice[x-1][y] = '+';
						matrice[x+1][y] = '+';
					}
					y++;
					orient_prec = 'h';
				}

				else{												//cas où on arrive a la limite et que le nombre aléatoire ne permet pas de continuer
					if (compt[x+1][y] == val + 1){
						if (orient_prec == 'h'){
							matrice[x][y+1] = '+';
							matrice[x-1][y] = '+';
							matrice[x-1][y+1] = '+';

						}
						else{
							matrice[x][y+1] = '+';
							matrice[x][y-1] = '+';
						}
						x++;
					}
					orient_prec = 'v';
				}
			}

			else{
				if (compt[x+1][y] == val + 1){
					if (orient_prec == 'h'){
						matrice[x][y+1] = '+';
						matrice[x-1][y] = '+';
						matrice[x-1][y+1] = '+';
					}
					else{
						matrice[x][y+1] = '+';
						matrice[x][y-1] = '+';
					}
					x++;
					orient_prec = 'v';

				}

				else{												//cas où on arrive a la limite et que le nombre aléatoire ne permet pas de continuer
					if (compt[x][y+1] == val + 1){
						if (orient_prec == 'v'){
							matrice[x][y-1] = '+';
							matrice[x+1][y] = '+';
							matrice[x+1][y-1] = '+';
						}
						else{
							matrice[x-1][y] = '+';
							matrice[x+1][y] = '+';
						}
						y++;
					}
					orient_prec = 'h';
				}
			}
		}
		else if (x1 > x2 && y1 < y2){
			if (alea %2 == 0){
				if (compt[x][y+1] == val + 1){
					if (orient_prec == 'v'){
						matrice[x][y-1] = '+';
						matrice[x-1][y] = '+';
						matrice[x-1][y-1] = '+';
					}
					else{
						matrice[x-1][y] = '+';
						matrice[x+1][y] = '+';
					}
					y++;
					orient_prec = 'h';
				}

				else{												//cas où on arrive a la limite et que le nombre aléatoire ne permet pas de continuer
					if (compt[x-1][y] == val + 1){
						if (orient_prec == 'h'){
							matrice[x+1][y] = '+';
							matrice[x][y+1] = '+';
							matrice[x+1][y+1] = '+';
						}
						else{
							matrice[x][y-1] = '+';
							matrice[x][y+1] = '+';
						}
						x--;
					}
					orient_prec = 'v';
				}
			}

			else{
				if (compt[x-1][y] == val + 1){
					if (orient_prec == 'h'){
						matrice[x+1][y] = '+';
						matrice[x][y+1] = '+';
						matrice[x+1][y+1] = '+';
					}
					else{
						matrice[x][y-1] = '+';
						matrice[x][y+1] = '+';
					}
					x--;
					orient_prec = 'v';
				}

				else{												//cas où on arrive a la limite et que le nombre aléatoire ne permet pas de continuer
					if (compt[x][y+1] == val + 1){
						if (orient_prec == 'v'){
							matrice[x][y-1] = '+';
							matrice[x-1][y] = '+';
							matrice[x-1][y-1] = '+';
						}
						else{
							matrice[x-1][y] = '+';
							matrice[x+1][y] = '+';
						}
						y++;
					}
					orient_prec = 'h';
				}
			}
		}

		else if (x1 < x2 && y1 > y2){
			if (alea %2 == 0){
				if (compt[x][y-1] == val + 1){
					if (orient_prec == 'v'){
						matrice[x][y+1] = '+';
						matrice[x+1][y] = '+';
						matrice[x+1][y+1] = '+';
					}
					else{
						matrice[x-1][y] = '+';
						matrice[x+1][y] = '+';
					}
					y--;
					orient_prec = 'h';
				}

				else{												//cas où on arrive a la limite et que le nombre aléatoire ne permet pas de continuer
					if (compt[x+1][y] == val + 1){
						if (orient_prec == 'h'){
							matrice[x-1][y] = '+';
							matrice[x][y-1] = '+';
							matrice[x-1][y-1] = '+';
						}
						else{
							matrice[x][y-1] = '+';
							matrice[x][y+1] = '+';
						}
						x++;
					}
					orient_prec = 'v';
				}
			}

			else{
				if (compt[x+1][y] == val + 1){
					if (orient_prec == 'h'){
						matrice[x-1][y] = '+';
						matrice[x][y-1] = '+';
						matrice[x-1][y-1] = '+';
					}
					else{
						matrice[x][y-1] = '+';
						matrice[x][y+1] = '+';
					}
					x++;
					orient_prec = 'v';
				}

				else{												//cas où on arrive a la limite et que le nombre aléatoire ne permet pas de continuer
					if (compt[x][y-1] == val + 1){
						if (orient_prec == 'v'){
							matrice[x][y+1] = '+';
							matrice[x+1][y] = '+';
							matrice[x+1][y+1] = '+';
						}
						else{
							matrice[x-1][y] = '+';
							matrice[x+1][y] = '+';
						}
						y--;
					}
					orient_prec = 'h';
				}
			}
		}
		matrice[x][y] = ' ';

		val++;		
	}
}


void couloir3(char matrice[M][Q], piece_t piece1, piece_t piece2)
{	
	int compt[M][Q];
	remplir_matrice_compt3(compt);

	int x1 = piece1.x_porte2;
	int y1= piece1.y_porte2;
	char pos1 = piece1.position_p2;

	int x2 = piece2.x_porte1;
	int y2 = piece2.y_porte1;
	char pos2 = piece2.position_p1;
	int x, y, x_fin, y_fin;

	int alea;
	int val = 1;
	char orient_prec;

	dijkstra3(compt, piece1, piece2, 0, 0, 0);

	if (pos1 == 'h'){
		x = x1 + 2;
		y = y1;
		x_fin = x2 - 2;
		y_fin = y2;
		orient_prec = 'v';
		matrice[x1][y1-1] = '+';
		matrice[x2][y2+1] = '+';
		matrice[x2][y2-1] = '+';
		matrice[x1+1][y1+1] = '+';
		matrice[x1+1][y1-1] = '+';
		matrice[x2-1][y2+1] = '+';
		matrice[x2-1][y2-1] = '+';

		matrice[x1+1][y1] = ' ';
		matrice[x2-1][y2] = ' ';
	}

	else{
		x = x1;
		y = y1 + 2;
		x_fin = x2;
		y_fin = y2 - 2;
		orient_prec = 'h';
		matrice[x1+1][y1] = '+';
		matrice[x1-1][y1] = '+';
		matrice[x2+1][y2] = '+';
		matrice[x2-1][y2] = '+';
		matrice[x1+1][y1+1] = '+';
		matrice[x1-1][y1+1] = '+';
		matrice[x2+1][y2-1] = '+';
		matrice[x2-1][y2-1] = '+';

		matrice[x1][y1+1] = ' ';
		matrice[x2][y2-1] = ' ';
	}
	
	matrice[x][y] = ' ';
	matrice[x_fin][y_fin] = ' ';
	
	while ((x != x_fin) || (y != y_fin)){
		alea = rand_a_b(0,10);
		if (x1 < x2 && y1 < y2){
			if (alea %2 == 0){
				if (compt[x][y+1] == val + 1){
					if (orient_prec == 'v'){
						matrice[x][y-1] = '+';
						matrice[x+1][y] = '+';
						matrice[x+1][y-1] = '+';
					}
					else{
						matrice[x-1][y] = '+';
						matrice[x+1][y] = '+';
					}
					y++;
					orient_prec = 'h';
				}

				else{												//cas où on arrive a la limite et que le nombre aléatoire ne permet pas de continuer
					if (compt[x+1][y] == val + 1){
						if (orient_prec == 'h'){
							matrice[x][y+1] = '+';
							matrice[x-1][y] = '+';
							matrice[x-1][y+1] = '+';

						}
						else{
							matrice[x][y+1] = '+';
							matrice[x][y-1] = '+';
						}
						x++;
					}
					orient_prec = 'v';
				}
			}

			else{
				if (compt[x+1][y] == val + 1){
					if (orient_prec == 'h'){
						matrice[x][y+1] = '+';
						matrice[x-1][y] = '+';
						matrice[x-1][y+1] = '+';
					}
					else{
						matrice[x][y+1] = '+';
						matrice[x][y-1] = '+';
					}
					x++;
					orient_prec = 'v';

				}

				else{												//cas où on arrive a la limite et que le nombre aléatoire ne permet pas de continuer
					if (compt[x][y+1] == val + 1){
						if (orient_prec == 'v'){
							matrice[x][y-1] = '+';
							matrice[x+1][y] = '+';
							matrice[x+1][y-1] = '+';
						}
						else{
							matrice[x-1][y] = '+';
							matrice[x+1][y] = '+';
						}
						y++;
					}
					orient_prec = 'h';
				}
			}
		}
		else if (x1 > x2 && y1 < y2){
			if (alea %2 == 0){
				if (compt[x][y+1] == val + 1){
					if (orient_prec == 'v'){
						matrice[x][y-1] = '+';
						matrice[x-1][y] = '+';
						matrice[x-1][y-1] = '+';
					}
					else{
						matrice[x-1][y] = '+';
						matrice[x+1][y] = '+';
					}
					y++;
					orient_prec = 'h';
				}

				else{												//cas où on arrive a la limite et que le nombre aléatoire ne permet pas de continuer
					if (compt[x-1][y] == val + 1){
						if (orient_prec == 'h'){
							matrice[x+1][y] = '+';
							matrice[x][y+1] = '+';
							matrice[x+1][y+1] = '+';
						}
						else{
							matrice[x][y-1] = '+';
							matrice[x][y+1] = '+';
						}
						x--;
					}
					orient_prec = 'v';
				}
			}

			else{
				if (compt[x-1][y] == val + 1){
					if (orient_prec == 'h'){
						matrice[x+1][y] = '+';
						matrice[x][y+1] = '+';
						matrice[x+1][y+1] = '+';
					}
					else{
						matrice[x][y-1] = '+';
						matrice[x][y+1] = '+';
					}
					x--;
					orient_prec = 'v';
				}

				else{												//cas où on arrive a la limite et que le nombre aléatoire ne permet pas de continuer
					if (compt[x][y+1] == val + 1){
						if (orient_prec == 'v'){
							matrice[x][y-1] = '+';
							matrice[x-1][y] = '+';
							matrice[x-1][y-1] = '+';
						}
						else{
							matrice[x-1][y] = '+';
							matrice[x+1][y] = '+';
						}
						y++;
					}
					orient_prec = 'h';
				}
			}
		}

		else if (x1 < x2 && y1 > y2){
			if (alea %2 == 0){
				if (compt[x][y-1] == val + 1){
					if (orient_prec == 'v'){
						matrice[x][y+1] = '+';
						matrice[x+1][y] = '+';
						matrice[x+1][y+1] = '+';
					}
					else{
						matrice[x-1][y] = '+';
						matrice[x+1][y] = '+';
					}
					y--;
					orient_prec = 'h';
				}

				else{												//cas où on arrive a la limite et que le nombre aléatoire ne permet pas de continuer
					if (compt[x+1][y] == val + 1){
						if (orient_prec == 'h'){
							matrice[x-1][y] = '+';
							matrice[x][y-1] = '+';
							matrice[x-1][y-1] = '+';
						}
						else{
							matrice[x][y-1] = '+';
							matrice[x][y+1] = '+';
						}
						x++;
					}
					orient_prec = 'v';
				}
			}

			else{
				if (compt[x+1][y] == val + 1){
					if (orient_prec == 'h'){
						matrice[x-1][y] = '+';
						matrice[x][y-1] = '+';
						matrice[x-1][y-1] = '+';
					}
					else{
						matrice[x][y-1] = '+';
						matrice[x][y+1] = '+';
					}
					x++;
					orient_prec = 'v';
				}

				else{												//cas où on arrive a la limite et que le nombre aléatoire ne permet pas de continuer
					if (compt[x][y-1] == val + 1){
						if (orient_prec == 'v'){
							matrice[x][y+1] = '+';
							matrice[x+1][y] = '+';
							matrice[x+1][y+1] = '+';
						}
						else{
							matrice[x-1][y] = '+';
							matrice[x+1][y] = '+';
						}
						y--;
					}
					orient_prec = 'h';
				}
			}
		}
		matrice[x][y] = ' ';

		val++;		
	}
}

/*int main(){

	piece_t piece1;
	piece_t piece2;
	
	int x1 = piece1.x_porte2 = 3;
	int y1= piece1.y_porte2 = 45;
	char pos1 = piece1.position_p2 = 'h';

	int x2 = piece2.x_porte1 = 25;
	int y2 = piece2.y_porte1 = 9;
	char pos2 = piece2.position_p1 = 'h';
	int x, y, x_fin, y_fin;

	srand(time(NULL));

	char matrice[N][M];


	int compt[N][M];
	creer_map(matrice, piece1, piece2);
	remplir_matrice(compt);

	couloir(compt, matrice, piece1, piece2);

	afficher_matrice(matrice);
	//afficher_matrice_int(compt);

}*/