#include <stdlib.h>
#include <stdio.h>
#include "rogue_like.h"

int main() {
	int niv;
	
	printf("Entrez le numéro du niveau : ");
	scanf("%i", &niv);
	
	if(niv == 1){
		//Creation de la map avec toutes les pieces et les tresors
		char map[N][M];
	
		//On cree d'abord la matrice et ses bordures
		creer_map(map);
	
		//On cree ensuite les pieces
		creer_piece1(map);
		creer_piece2(map);
		creer_piece3(map);
	}
	else if(niv == 2){
		//Creation de la map avec toutes les pieces et les tresors
		char map[N+20][M+10];
		
		//On cree d'abord la matrice et ses bordures
		creer_map(map);
		
		//On cree ensuite les pieces
		creer_piece21(map);
		creer_piece22(map);
		creer_piece23(map);
		creer_piece24(map);
	}
	else if(niv == 3){
		//Creation de la map avec toutes les pieces et les tresors
		char map[N+30][M+10];
		
		//On cree d'abord la matrice et ses bordures
		creer_map(map);
		
		//On cree ensuite les pieces
		creer_piece31(map);
		creer_piece32(map);
		creer_piece33(map);
		creer_piece34(map);
		creer_piece35(map);
	}

	//Et enfin on place les tresors
	placement_tresors(map);

	//Affichage de la map
	affichage_map(map);
	
	return 0;
}
