#include <stdlib.h>
#include <stdio.h>
#include "rogue_like.h"

int rand_a_b(int a, int b){

    return rand()%(b-a) +a;

}

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
		creer_piece(map);
		
		//Et enfin on place les tresors
		placement_tresors(map);

		//Affichage de la map
		affichage_map(map);
	}
	else if(niv == 2){
		//Creation de la map avec toutes les pieces et les tresors
		char map[O][P];
		
		//On cree d'abord la matrice et ses bordures
		creer_map2(map);
		
		//On cree ensuite les pieces
		creer_piece2(map);
		
		//Et enfin on place les tresors
		placement_tresors2(map);

		//Affichage de la map
		affichage_map2(map);
	}
	else if(niv == 3){
		//Creation de la map avec toutes les pieces et les tresors
		char map[M][Q];
		
		//On cree d'abord la matrice et ses bordures
		creer_map3(map);
		
		//On cree ensuite les pieces
		creer_piece3(map);
			
		//Et enfin on place les tresors
		placement_tresors3(map);

		//Affichage de la map
		affichage_map3(map);
	}
	
	return 0;
}
