#include<stdio.h>
#include<stdlib.h>
#define N 30
#define M 50
#define O 50
#define P 60
#define Q 120

//niveau 1 : 30/50
//niveau 2 : 50/60
//niveau 3 : 50/120


void creer_map(char matrice[N][M]);
void creer_map2(char matrice[O][P]);
void creer_map3(char matrice[M][Q]);

int tresorx(int longueur);
int tresory(int largeur);

int rand_a_b(int a, int b);

void creer_piece(char matrice[N][M], int x_haut, int y_gauche, int min_larg, int max_larg, int min_haut, int max_haut);
void creer_piece2(char matrice[O][P], int x_haut, int y_gauche, int min_larg, int max_larg, int min_haut, int max_haut);
void creer_piece3(char matrice[M][Q], int x_haut, int y_gauche, int min_larg, int max_larg, int min_haut, int max_haut);

/*
void creer_piece1(char matrice[N][M]);
void creer_piece2(char matrice[N][M]);
void creer_piece3(char matrice[N][M]);


void creer_piece21(char matrice[O][P]);
void creer_piece22(char matrice[O][P]);
void creer_piece23(char matrice[O][P]);
void creer_piece24(char matrice[O][P]);

void creer_piece31(char matrice[M][Q]);
void creer_piece32(char matrice[M][Q]);
void creer_piece33(char matrice[M][Q]);
void creer_piece34(char matrice[M][Q]);
void creer_piece35(char matrice[M][Q]);
*/

void affichage_map(char matrice[N][M]);
void affichage_map2(char matrice[O][P]);
void affichage_map3(char matrice[M][Q]);

void placement_tresors(char matrice[N][M]);
void placement_tresors2(char matrice[O][P]);
void placement_tresors3(char matrice[M][Q]);

int main(void);
