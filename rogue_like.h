#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define N 30
#define M 50

void creer_map(char matrice[N][M]);

int tresorx(int longueur);
int tresory(int largeur);

void creer_piece1(char matrice[N][M]);
void creer_piece2(char matrice[N][M]);
void creer_piece3(char matrice[N][M]);

void creer_piece21(char matrice[N][M]);
void creer_piece22(char matrice[N][M]);
void creer_piece23(char matrice[N][M]);
void creer_piece24(char matrice[N][M]);

void creer_piece31(char matrice[N][M]);
void creer_piece32(char matrice[N][M]);
void creer_piece33(char matrice[N][M]);
void creer_piece34(char matrice[N][M]);
void creer_piece35(char matrice[N][M]);

void affichage_map(char matrice[N][M]);

void placement_tresors(char matrice[N][M]);

int main(void);
