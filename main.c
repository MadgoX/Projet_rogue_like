#include <stdlib.h>
#include <stdio.h>
#include "rogue_like.h"

int main() {
	int niv;
	//Map du niveau 1
	char map1[N][M];
	//Map du niveau 2
	char map2[A][B];
	//Map du niveau 3
	char map3[C][C];
	
	printf("Entrez le numéro du niveau (1, 2 ou 3) : ");
	scanf("%i", &niv);
	
	if(niv == 1){
		//On cree d'abord la matrice et ses bordures
		creer_map1(map1);
	
		//On cree ensuite les pieces
		creer_piece1(map1);
		creer_piece2(map1);
		creer_piece3(map1);

		//Et enfin on place les tresors
		placement_tresors1(map1);
	}
	else if(niv == 2){
		//On cree d'abord la matrice et ses bordures
		creer_map2(map2);
		
		//On cree ensuite les pieces
		creer_piece21(map2);
		creer_piece22(map2);
		creer_piece23(map2);
		creer_piece24(map2);

		//Et enfin on place les tresors
		placement_tresors2(map2);
	}
	else if(niv == 3){
		//On cree d'abord la matrice et ses bordures
		creer_map3(map3);
		
		//On cree ensuite les pieces
		creer_piece31(map3);
		creer_piece32(map3);
		creer_piece33(map3);
		creer_piece34(map3);
		creer_piece35(map3);

		//Et enfin on place les tresors
		placement_tresors3(map3);
	}

	//Affichage de la map
	if(niv == 1){	
		affichage_map1(map1);
	}
	else if(niv == 2){
		affichage_map2(map2);
	}
	else if(niv == 3){
		affichage_map3(map3);
	}
	
	return 0;
}
