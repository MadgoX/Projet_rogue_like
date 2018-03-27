/*!
*
*	\file main.c
*	\brief Fonction main du projet
*	\author Lucien BOUYEURE, Romane BUON, Yann PAULMERY
*	\version 0.1
*
*/
#include <stdlib.h>
#include <stdio.h>
#include "rogue_like.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

/*!
*	
*	\fn rand_a_b(int a, int b)
*	\brief Fonction de génération d'un nombre aléatoire.
*	\param a Borne inférieure de l'intevalle dans lequel le nombre aléatoire doit être généré.
*	\param b Borne supérieure de l'intevalle dans lequel le nombre aléatoire doit être généré.
*
*/
int rand_a_b(int a, int b){

    return rand()%(b-a) +a;

}

/*!
*	
*	\fn int main()
*	\brief Fonction main du projet.
*
*/
int main() {
	SDL_Window * fenetre=NULL;
	SDL_Renderer * renderer=NULL;
	TTF_Font * police=NULL;
	SDL_Color couleurBlanche = {255, 255, 255};
	SDL_Surface * texte = NULL;
	SDL_Rect txtDestRect;

	if(SDL_Init(SDL_INIT_VIDEO) != 0) {
		fprintf(stderr, "Erreur lors de l'initialisation de la SDL : %s\n", SDL_GetError());
		SDL_Quit();
		return -1;
	}

	if(TTF_Init () ==  -1) {
		fprintf(stderr , "Erreur d’initialisation  de  TTF_Init : %s\n", TTF_GetError ());
		exit(EXIT_FAILURE );
	}

	fenetre = SDL_CreateWindow("Rogue Like", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	if(!fenetre) {
		fprintf(stderr, "Erreur a la creation de la fenetre : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
	if(renderer == NULL) {
		fprintf(stderr, "Erreur a la creation du renderer\n");
		exit(EXIT_FAILURE);
	}

	if((police=TTF_OpenFont("arial.ttf", 12))==NULL) {
		fprintf(stderr, "Erreur chargement police\n");
		exit(EXIT_FAILURE);
	}
	
	texte = TTF_RenderUTF8_Solid(police, "Hello World", couleurBlanche);
	if(!texte) {
		fprintf(stderr, "Erreur chargement texte\n");
		exit(EXIT_FAILURE);
	}

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_Texture *texte_tex = SDL_CreateTextureFromSurface(renderer, texte);
	if(!texte_tex) {
		fprintf(stderr, "Erreur a la creation du rendu du texte\n");
		exit(EXIT_FAILURE);
	}

	SDL_FreeSurface(texte);
	txtDestRect.x = txtDestRect.y = 10;
	SDL_QueryTexture(texte_tex, NULL, NULL, &(txtDestRect.w), &(txtDestRect.h));

	if(fenetre) {
		int running=1;
		while(running) {
			SDL_Event e;
			while(SDL_PollEvent(&e)) {
				switch(e.type) {
					case SDL_QUIT: running=0;
					break;
					case SDL_WINDOWEVENT:
						switch(e.window.event) {
							case SDL_WINDOWEVENT_EXPOSED:
							case SDL_WINDOWEVENT_SIZE_CHANGED:
							case SDL_WINDOWEVENT_RESIZED:
							case SDL_WINDOWEVENT_SHOWN:

				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
				SDL_RenderClear(renderer);
				
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
				SDL_RenderCopy(renderer, texte_tex, NULL, &txtDestRect);
			
				SDL_RenderPresent(renderer);

							break;
						}
					break;
				}
			}
		}
	}
	else {
		fprintf(stderr, "Erreur de creation de la fenetre: %s\n", SDL_GetError());
	}
    
	int niv;
	printf("Entrez le numéro du niveau : ");
	scanf("%i", &niv);

	if(niv == 1){
		//Creation de la map avec toutes les pieces et les tresors
		char map[N][M];

		//On cree d'abord la matrice et ses bordures
		creer_map(map);

		//On cree ensuite les pieces
		map_niveau1(map);

		//Et enfin on place les tresors
		placement_tresors1(map);

		//Affichage de la map
		affichage_map1(map);
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
	TTF_CloseFont(police);
	TTF_Quit();
	SDL_Quit();
	return 0;
}
