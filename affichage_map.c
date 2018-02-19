#include<stdio.h>
#include"rogue_like.h"

void affichage_map1(char matrice[N][M]){
	int i, j;
	
	//Affichage de la map
	for(i = 0; i < N; i++){
		for(j = 0; j < M; j++){
			printf("%c",matrice[i][j]);
		}
		printf("\n");
	}
}

void affichage_map2(char matrice[A][B]){
	int i, j;
	
	//Affichage de la map
	for(i = 0; i < A; i++){
		for(j = 0; j < B; j++){
			printf("%c",matrice[i][j]);
		}
		printf("\n");
	}
}

void affichage_map3(char matrice[C][D]){
	int i, j;
	
	//Affichage de la map
	for(i = 0; i < C; i++){
		for(j = 0; j < D; j++){
			printf("%c",matrice[i][j]);
		}
		printf("\n");
	}
}