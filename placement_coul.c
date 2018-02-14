#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

int rand_a_b(int a, int b)
{
	return rand()%(b-a) +a;
}


int choisir_porte_x(int x_hg, int x_hd, int x_bg, int x_bd)
{
	int test=rand(); //variable permettant de choisir si on utilise le bord haut ou le brod bas
	srand(time(NULL)); // initialisation de rand
	if (test%2 == 0)
	{
		return rand_a_b(x_hg, x_hd);
	}
	else
	{
		return rand_a_b(x_bg, x_bd);
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
	srand(time(NULL)); // initialisation de rand
	int test = choisir_porte_x(1,3,48,50);
	printf("Porte x : %i\n",test); 
	int test2 = choisir_porte_y(1,3,48,50);
	printf("Porte y : %i\n",test2);
}
