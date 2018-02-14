#include <stdlib.h>
#include <stdio.h>
#include "rogue_like.h"

int main() {
	//Creation de la map avec toutes les pieces et les tresors
	char map[N][M];

	//On cree d'abord la matrice et ses bordures
	creer_map(map);

	//On cree ensuite les pieces
	creer_piece1(map);
	creer_piece2(map);
	creer_piece3(map);
//	creer_piece(map);

	//Et enfin on place les tresors
	placement_tresors(map);

	//Affichage de la map
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			printf("%c",map[i][j]);
		}
		printf("\n");
	}
	return 0;
}
