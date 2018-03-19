#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include"rogue_like.h"

#define N 30
#define M 50

int rand_a_b(int a, int b)
{
	return rand()%(b-a) +a;
}


int 0


int choisir_porte_x(int x_hg, int x_hd, int x_bg, int x_bd)
{
	int x;
	int test=rand(); //variable permettant de choisir si on utilise le bord haut ou le brod bas
	srand(time(NULL)); // initialisation de rand
	if (test%2 == 0)
	{
		x = rand_a_b(x_hg, x_hd);
		printf("OK fonction porte x\n");
		return x;
		printf("OK fonction porte x 2\n");
	}
	else
	{	
		x = rand_a_b(x_bg, x_bd);
		printf("OK fonction porte x\n");
		return x;
		printf("OK fonction porte x 2\n");
	}
}

int choisir_porte_y(int y_hg, int y_bg, int y_hd, int y_bd)
{
	int test=rand(); //variable permettant de choisir si on utilise le bord haut ou le brod bas
	srand(time(NULL)); // initialisation de rand
	if (test%2 == 0)
	{
		return rand_a_b(y_hg, y_bg);
	}
	else
	{
		return rand_a_b(y_hd, y_bd);
	}
}




void placement_porte(char map[N][M])
{
	int i, j;
	int compt = 0;
	int x_hg; int x_hd; int x_bg; int x_bd; int y_hg; int y_bg; int y_hd; int y_bd;
printf("OK\n");
	creer_piece1(map);
printf("OK debut for\n");
	for(i = 1; i < N-1; i++){
		for(j = 1; j < M-1; j++){
			if(map[i][j] == '+')
			{
				if(compt == 0)
				{
					compt++;
					x_hg = j;
					y_hg = i;
				}
				
				else if(compt == 1)
				{
					compt++;
					x_hd = j;
					y_hd = i;
				}
				else if(compt == 2)
				{
					compt++;
					x_bg = j;
					y_bg = i;
				}
				else if(compt == 3)
				{
					compt++;
					x_bd = j;
					y_bd = i;
				}
				printf("%d\n",compt);
			}
		}
	}
	
	srand(time(NULL)); // initialisation de rand
	int test2, test3;	
	if (test%2 == 0)
	{
		test2 = rand_a_b(y_hg, y_bg);
		test3 = x_hg;
	}
	else
	{
		test2 = rand_a_b(y_hd, y_bd);
		test3 = x_hd;
	}
/*
printf("OK\n");
	srand(time(NULL));
printf("OK\n"); // initialisation de rand
	int test = choisir_porte_x(x_hg,x_hd,x_bg,x_bd);
printf("OK\n");
	printf("Porte x : %i\n",test);
	int test2 = choisir_porte_y(y_hg,y_bg,y_hd,y_bd);
	printf("Porte y : %i\n",test2);
	
	
	creer_piece2(map);
	creer_piece3(map);*/

	//Affichage de la map
	for(i = 0; i < N; i++){
		for(j = 0; j < M; j++){
			
			if(i == test2 && j == test3)
			{
				map[i][j]='P';
				 printf("%c",map[i][j]);
			}
			else
				printf("%c",map[i][j]);		
		}
		printf("\n");
	}
}