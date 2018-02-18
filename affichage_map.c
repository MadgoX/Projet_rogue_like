#include<stdio.h>
#include"rogue_like.h"

void affichage_map(char matrice[N][M]){
	int i, j;
	
	//Affichage de la map
	for(i = 0; i < N; i++){
		for(j = 0; j < M; j++){
			printf("%c",map[i][j]);
		}
		printf("\n");
	}
}