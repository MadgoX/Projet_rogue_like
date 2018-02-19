#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define N 30
#define M 50

#define A 50
#define B 60

#define C 50
#define D 120

void creer_map1(char matrice[N][M]);
void creer_map2(char matrice[A][B]);
void creer_map3(char matrice[C][D]);

int tresorx(int longueur);
int tresory(int largeur);

void creer_piece1(char matrice[N][M]);
void creer_piece2(char matrice[N][M]);
void creer_piece3(char matrice[N][M]);

void creer_piece21(char matrice[A][B]);
void creer_piece22(char matrice[A][B]);
void creer_piece23(char matrice[A][B]);
void creer_piece24(char matrice[A][B]);

void creer_piece31(char matrice[C][D]);
void creer_piece32(char matrice[C][D]);
void creer_piece33(char matrice[C][D]);
void creer_piece34(char matrice[C][D]);
void creer_piece35(char matrice[C][D]);

void affichage_map1(char matrice[N][M]);
void affichage_map2(char matrice[A][B]);
void affichage_map3(char matrice[C][D]);

void placement_tresors1(char matrice[N][M]);
void placement_tresors2(char matrice[A][B]);
void placement_tresors3(char matrice[C][D]);

int main(void);
