#include <stdlib.h>
#include <stdio.h>
#include "rogue_like.h"
#include <SDL2/SDL.h>

int main() {
    // Notre fenêtre
    SDL_Window* fenetre;

    // Initialisation de la SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Erreur lors de l'initialisation de la SDL : %s\n", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    // Création de la fenêtre
    fenetre = SDL_CreateWindow("Test SDL 2.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    
	int niv;
	printf("Entrez le numéro du niveau : ");
	scanf("%i", &niv);

	if(niv == 1){
		//Creation de la map avec toutes les pieces et les tresors
		char map[N][M];
		printf("1\n");
		//On cree d'abord la matrice et ses bordures
		creer_map(map);
printf("2\n");
		//On cree ensuite les pieces
		map_niveau1(map);
	printf("3\n");
		//Et enfin on place les tresors
		placement_tresors(map);
printf("4\n");
		//Affichage de la map
		affichage_map(map);
	}
	else if(niv == 2){
		//Creation de la map avec toutes les pieces et les tresors
		char map[O][P];
	
		//On cree d'abord la matrice et ses bordures
		creer_map2(map);
	
		//On cree ensuite les pieces
		map_niveau2(map);
	
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
		map_niveau3(map);
		
		//Et enfin on place les tresors
		placement_tresors3(map);

		//Affichage de la map
		affichage_map3(map);
	}
	SDL_DestroyWindow(fenetre);
	SDL_Quit();
	return 0;
}
