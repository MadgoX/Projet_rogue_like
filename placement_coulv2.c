#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

#define N 30
#define M 50

void creer_map(char matrice[N][M])
{

	int i, j;
	char res;
	
	for(i=0; i<N; i++){
		for(j=0; j<M; j++){
			matrice[i][j]='.';
		}
	}

	i=0;
	for(j=1; j<M-1; j++){
		matrice[i][j]='=';
	}
	
	j=0;
	for(i=1; i<N-1; i++){
		matrice[i][j]='#';
	}

	j=M-1;
	for(i=1; i<N-1; i++){
		matrice[i][j]='#';
	}

	i=N-1;
	for(j=1; j<M-1; j++){
		matrice[i][j]='=';
	}
	
	i=0;
	j=0;
	matrice[i][j]='+';

	i=N-1;
	j=M-1;
	matrice[i][j]='+';
	
	i=N-1;
	j=0;
	matrice[i][j]='+';

	i=0;
	j=M-1;
	matrice[i][j]='+';
}

void creer_piece1(char matrice[N][M]){

	/*Appel de la fonction qui créer le tour de la map*/
	creer_map(matrice);

	int i, j;
	
	/*Creation d'une piece en haut à gauche de la map*/
	for(i = 4; i < 12; i++){
		for(j = 5; j < 15; j++){
			matrice[i][j] = ' ';
		}
	}

	/*Mur de gauche de la pièce*/
	for(i = 4; i < 12; i++){
		j = 4;
		matrice[i][j] = '|';
	}

	/*Mur de droite de la pièce*/
	for(i =  4; i < 12; i++){
		j = 15;
		matrice[i][j] = '|';
	}

	/*Angles des pièces*/
	matrice[3][4] = '+';
	matrice[3][15] = '+';
	matrice[12][4] = '+';
	matrice[12][15] = '+';

	/*Mur du haut de la pièce*/
	for(j = 5; j < 15; j++){
		i = 3;
		matrice[i][j] = '-';
	}

	/*Mur du bas de la pièce*/
	for(j = 5; j < 15; j++){
		i = 12;
		matrice[i][j] = '-';
	}
}

void creer_piece2(char matrice[N][M]){

	int i, j;
	
	/*Creation d'une piece en haut à droite de la map*/
	for(i = 5; i < 13; i++){
		for(j = 25; j < 40; j++){
			matrice[i][j] = ' ';
		}
	}

	//Mur de gauche de la pièce
	for(i = 5; i < 13; i++){
		j = 24;
		matrice[i][j] = '|';
	}

	//Mur de droite de la pièce
	for(i =  5; i < 13; i++){
		j = 40;
		matrice[i][j] = '|';
	}

	//Angles des pièces
	matrice[4][24] = '+';
	matrice[4][40] = '+';
	matrice[13][24] = '+';
	matrice[13][40] = '+';

	//Mur du haut de la pièce
	for(j = 25; j < 40; j++){
		i = 4;
		matrice[i][j] = '-';
	}

	//Mur du bas de la pièce
	for(j = 25; j < 40; j++){
		i = 13;
		matrice[i][j] = '-';
	}
}

void creer_piece3(char matrice[N][M]){

	int i, j;
	
	/*Creation d'une piece en bas de la map*/
	for(i = 18; i < 25; i++){
		for(j = 10; j < 44; j++){
			matrice[i][j] = ' ';
		}
	}

	//Mur de gauche de la pièce
	for(i = 18; i < 25; i++){
		j = 9;
		matrice[i][j] = '|';
	}

	//Mur de droite de la pièce
	for(i =  18; i < 25; i++){
		j = 44;
		matrice[i][j] = '|';
	}

	//Angles des pièces
	matrice[17][9] = '+';
	matrice[17][44] = '+';
	matrice[25][9] = '+';
	matrice[25][44] = '+';

	//Mur du haut de la pièce
	for(j = 10; j < 44; j++){
		i = 17;
		matrice[i][j] = '-';
	}

	//Mur du bas de la pièce
	for(j = 10; j < 44; j++){
		i = 25;
		matrice[i][j] = '-';
	}
}

/*int coins(char matrice[N][M], int *compt)
{
	int i, j;	
	printf("OK\n");
	for(i = 1; i < N-1; i++){
		for(j = 1; j < M-1; j++){
			if(matrice[i][j] == '+')
			{
				printf("\nOK\n");
				if(*compt == 0)
				{
				printf("%d\n",*compt);
					*compt++;
					x_hg = j;
					y_hg = i;
				printf("%d", j);
				}
				
				if(*compt == 1)
				{
					*compt++;
					x_hd = j;
					y_hd = i;
				}
				if(*compt == 2)
				{
					*compt++;
					x_bg = j;
					y_bg = i;
				}
				if(*compt == 3)
				{
					*compt++;
					x_bd = j;
					y_bd = i;
				}
				else return;
			}
		}
	}
}*/

int rand_a_b(int a, int b)
{
	return rand()%(b-a) +a;
}


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




int main()
{
	int i, j;
	int compt = 0;
	char map[N][M];
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
				
				if(compt == 1)
				{
					compt++;
					x_hd = j;
					y_hd = i;
				}
				if(compt == 2)
				{
					compt++;
					x_bg = j;
					y_bg = i;
				}
				if(compt == 3)
				{
					compt++;
					x_bd = j;
					y_bd = i;
				}
				printf("%d\n",compt);
			}
		}
	}
	int test=rand(); //variable permettant de choisir si on utilise le bord haut ou le brod bas
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
			
			if(i == test2 && j == test3) printf("%c",'P');
			printf("%c",map[i][j]);		
		}
		printf("\n");
	}
	return 0;
}