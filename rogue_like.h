/*!
*
*	\file rogue_like.h
*	\brief Fichier contenant les protoypes de toutes les fonctions du programme
*	\author Lucien BOUYEURE, Romane BUON, Yann PAULMERY
*	\version 0.1
*
*/
#include<stdio.h>
#include<stdlib.h>
#include <SDL2/SDL.h>

#define N 30
#define M 50
#define O 50
#define P 60
#define Q 120

//niveau 1 : 30/50
//niveau 2 : 50/60
//niveau 3 : 50/120

/**
*
*	\struct piece_s
*	\brief Structure contenant toutes les informations importantes concernant chacunes des pièces
*
*/
typedef struct piece_s{
	int x_haut;
	int y_gauche;
	int x_porte1;
	int y_porte1;
	char position_p1;			//vaut h (si la porte est sur le coté haut ou bas de la piece) ou v (si la porte est sur le coté droit ou gauche de la piece)
	int x_porte2;
	int y_porte2;
	char position_p2;			//vaut h (si la porte est sur le coté haut ou bas de la piece) ou v (si la porte est sur le coté droit ou gauche de la piece)
} piece_t;

void creer_map1(char matrice[N][M]);
void creer_map2(char matrice[O][P]);
void creer_map3(char matrice[M][Q]);

int tresorx(int longueur);
int tresory(int largeur);

int rand_a_b(int a, int b);

void creer_piece1(char matrice[N][M], int x_haut, int y_gauche, int min_larg, int max_larg, int min_haut, int max_haut, int num_piece);
void creer_piece2(char matrice[O][P], int x_haut, int y_gauche, int min_larg, int max_larg, int min_haut, int max_haut, int num_piece);
void creer_piece3(char matrice[M][Q], int x_haut, int y_gauche, int min_larg, int max_larg, int min_haut, int max_haut, int num_piece);

void map_niveau1(char map[N][M]);
void map_niveau2(char map[O][P]);
void map_niveau3(char map[M][Q]);

void affichage_map1(char matrice[N][M]);
void affichage_map2(char matrice[O][P]);
void affichage_map3(char matrice[M][Q]);

void placement_tresors1(char matrice[N][M]);
void placement_tresors2(char matrice[O][P]);
void placement_tresors3(char matrice[M][Q]);

int main(void);
