/*!
*
*	\file partie.c
*	\brief Gérance des parties (déplacements, trésors, etc.)
*	\author Lucien BOUYEURE, Romane BUON, Yann PAULMERY
*	\version 1
*
*/
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <unistd.h>
#include "rogue_like.h"

void jeu1(char map[N][M]){
	int touche;						//touche sur laquelle le joueur appuie
	int x_cour, y_cour;
	int cpt_tresors = 0;			//compteur du nombre de trésors découverts par le joueur
	
	x_cour = piece11.x_haut;
	y_cour = (piece11.y_gauche)+1;

	mvprintw(x_cour, y_cour, "@");	//position du personnage au début de la partie

	keypad(stdscr, TRUE);

	refresh();              		// Rafraîchit la fenêtre courante afin de voir le labyrinthe apparaître
	
	do{
    	touche = getch();                		
		if((touche == KEY_RIGHT) && (map[x_cour][y_cour+1] != '|') && (map[x_cour][y_cour+1] != '+')){
			if(map[x_cour][y_cour+1] == 'o'){
				cpt_tresors++;
			}
			if(map[x_cour][y_cour+1] == 'P'){
				mvprintw(x_cour, y_cour, " ");
				y_cour = y_cour+2;
				mvprintw(x_cour, y_cour, "@");
			}
			else{
				mvprintw(x_cour, y_cour, " ");
				y_cour++;
				mvprintw(x_cour, y_cour, "@");
			}
		}
		else if((touche == KEY_LEFT) && (map[x_cour][y_cour-1] != '|') && (map[x_cour][y_cour-1] != '+')){
			if(map[x_cour][y_cour-1] == 'o'){
				cpt_tresors++;
			}
			if(map[x_cour][y_cour-1] == 'P'){
				mvprintw(x_cour, y_cour, " ");
				y_cour = y_cour-2;
				mvprintw(x_cour, y_cour, "@");
			}
			else{
				mvprintw(x_cour, y_cour, " ");
				y_cour--;
				mvprintw(x_cour, y_cour, "@");
			}
		}
		else if((touche == KEY_DOWN) && (map[x_cour+1][y_cour] != '-') && (map[x_cour+1][y_cour] != '+')){
			if(map[x_cour+1][y_cour] == 'o'){
				cpt_tresors++;
			}
			if(map[x_cour+1][y_cour] == 'P'){
				mvprintw(x_cour, y_cour, " ");
				x_cour = x_cour+2;
				mvprintw(x_cour, y_cour, "@");
			}
			else{
				mvprintw(x_cour, y_cour, " ");
				x_cour++;
				mvprintw(x_cour, y_cour, "@");
			}
		}
		else if((touche == KEY_UP) && (map[x_cour-1][y_cour] != '-') && (map[x_cour-1][y_cour] != '+')){
			if(map[x_cour-1][y_cour] == 'o'){
				cpt_tresors++;
			}
			if(map[x_cour-1][y_cour] == 'P'){
				mvprintw(x_cour, y_cour, " ");
				x_cour = x_cour-2;
				mvprintw(x_cour, y_cour, "@");
			}
			else{
				mvprintw(x_cour, y_cour, " ");
				x_cour--;
				mvprintw(x_cour, y_cour, "@");
			}
		}
		//Si la touche pressée est différente d'une des touches directionnelles, on ne fait rien
		else if((touche == KEY_RIGHT) && (touche == KEY_LEFT) && (touche == KEY_DOWN) && (touche == KEY_UP));
		
		refresh();
		map[piece11.x_haut][(piece11.y_gauche)+1] = 'A';
	}while((map[x_cour][y_cour] != 'A'));
	
	sleep(1);
}

void jeu2(char map[O][P]){
	int touche;						//touche sur laquelle le joueur appuie
	int x_cour, y_cour;
	int cpt_tresors = 0;			//compteur du nombre de trésors découverts par le joueur
	
	x_cour = piece11.x_haut;
	y_cour = (piece11.y_gauche)+1;

	mvprintw(x_cour, y_cour, "@");	//position du personnage au début de la partie

	keypad(stdscr, TRUE);

	refresh();              		// Rafraîchit la fenêtre courante afin de voir le labyrinthe apparaître
	
	do{
    	touche = getch();                		
		if((touche == KEY_RIGHT) && (map[x_cour][y_cour+1] != '|') && (map[x_cour][y_cour+1] != '+')){
			if(map[x_cour][y_cour+1] == 'o'){
				cpt_tresors++;
			}
			if(map[x_cour][y_cour+1] == 'P'){
				mvprintw(x_cour, y_cour, " ");
				y_cour = y_cour+2;
				mvprintw(x_cour, y_cour, "@");
			}
			else{
				mvprintw(x_cour, y_cour, " ");
				y_cour++;
				mvprintw(x_cour, y_cour, "@");
			}
		}
		else if((touche == KEY_LEFT) && (map[x_cour][y_cour-1] != '|') && (map[x_cour][y_cour-1] != '+')){
			if(map[x_cour][y_cour-1] == 'o'){
				cpt_tresors++;
			}
			if(map[x_cour][y_cour-1] == 'P'){
				mvprintw(x_cour, y_cour, " ");
				y_cour = y_cour-2;
				mvprintw(x_cour, y_cour, "@");
			}
			else{
				mvprintw(x_cour, y_cour, " ");
				y_cour--;
				mvprintw(x_cour, y_cour, "@");
			}
		}
		else if((touche == KEY_DOWN) && (map[x_cour+1][y_cour] != '-') && (map[x_cour+1][y_cour] != '+')){
			if(map[x_cour+1][y_cour] == 'o'){
				cpt_tresors++;
			}
			if(map[x_cour+1][y_cour] == 'P'){
				mvprintw(x_cour, y_cour, " ");
				x_cour = x_cour+2;
				mvprintw(x_cour, y_cour, "@");
			}
			else{
				mvprintw(x_cour, y_cour, " ");
				x_cour++;
				mvprintw(x_cour, y_cour, "@");
			}
		}
		else if((touche == KEY_UP) && (map[x_cour-1][y_cour] != '-') && (map[x_cour-1][y_cour] != '+')){
			if(map[x_cour-1][y_cour] == 'o'){
				cpt_tresors++;
			}
			if(map[x_cour-1][y_cour] == 'P'){
				mvprintw(x_cour, y_cour, " ");
				x_cour = x_cour-2;
				mvprintw(x_cour, y_cour, "@");
			}
			else{
				mvprintw(x_cour, y_cour, " ");
				x_cour--;
				mvprintw(x_cour, y_cour, "@");
			}
		}
		//Si la touche pressée est différente d'une des touches directionnelles, on ne fait rien
		else if((touche == KEY_RIGHT) && (touche == KEY_LEFT) && (touche == KEY_DOWN) && (touche == KEY_UP));
		
		refresh();
		map[piece11.x_haut][(piece11.y_gauche)+1] = 'A';
	}while((map[x_cour][y_cour] != 'A'));
	
	sleep(1);
}

void jeu3(char map[M][Q]){
	int touche;						//touche sur laquelle le joueur appuie
	int x_cour, y_cour;
	int cpt_tresors = 0;			//compteur du nombre de trésors découverts par le joueur
	
	x_cour = piece11.x_haut;
	y_cour = (piece11.y_gauche)+1;

	mvprintw(x_cour, y_cour, "@");	//position du personnage au début de la partie

	keypad(stdscr, TRUE);

	refresh();              		// Rafraîchit la fenêtre courante afin de voir le labyrinthe apparaître
	
	do{
    	touche = getch();                		
		if((touche == KEY_RIGHT) && (map[x_cour][y_cour+1] != '|') && (map[x_cour][y_cour+1] != '+')){
			if(map[x_cour][y_cour+1] == 'o'){
				cpt_tresors++;
			}
			if(map[x_cour][y_cour+1] == 'P'){
				mvprintw(x_cour, y_cour, " ");
				y_cour = y_cour+2;
				mvprintw(x_cour, y_cour, "@");
			}
			else{
				mvprintw(x_cour, y_cour, " ");
				y_cour++;
				mvprintw(x_cour, y_cour, "@");
			}
		}
		else if((touche == KEY_LEFT) && (map[x_cour][y_cour-1] != '|') && (map[x_cour][y_cour-1] != '+')){
			if(map[x_cour][y_cour-1] == 'o'){
				cpt_tresors++;
			}
			if(map[x_cour][y_cour-1] == 'P'){
				mvprintw(x_cour, y_cour, " ");
				y_cour = y_cour-2;
				mvprintw(x_cour, y_cour, "@");
			}
			else{
				mvprintw(x_cour, y_cour, " ");
				y_cour--;
				mvprintw(x_cour, y_cour, "@");
			}
		}
		else if((touche == KEY_DOWN) && (map[x_cour+1][y_cour] != '-') && (map[x_cour+1][y_cour] != '+')){
			if(map[x_cour+1][y_cour] == 'o'){
				cpt_tresors++;
			}
			if(map[x_cour+1][y_cour] == 'P'){
				mvprintw(x_cour, y_cour, " ");
				x_cour = x_cour+2;
				mvprintw(x_cour, y_cour, "@");
			}
			else{
				mvprintw(x_cour, y_cour, " ");
				x_cour++;
				mvprintw(x_cour, y_cour, "@");
			}
		}
		else if((touche == KEY_UP) && (map[x_cour-1][y_cour] != '-') && (map[x_cour-1][y_cour] != '+')){
			if(map[x_cour-1][y_cour] == 'o'){
				cpt_tresors++;
			}
			if(map[x_cour-1][y_cour] == 'P'){
				mvprintw(x_cour, y_cour, " ");
				x_cour = x_cour-2;
				mvprintw(x_cour, y_cour, "@");
			}
			else{
				mvprintw(x_cour, y_cour, " ");
				x_cour--;
				mvprintw(x_cour, y_cour, "@");
			}
		}
		//Si la touche pressée est différente d'une des touches directionnelles, on ne fait rien
		else if((touche == KEY_RIGHT) && (touche == KEY_LEFT) && (touche == KEY_DOWN) && (touche == KEY_UP));
		
		refresh();
		map[piece11.x_haut][(piece11.y_gauche)+1] = 'A';
	}while((map[x_cour][y_cour] != 'A'));
	
	sleep(1);
}

