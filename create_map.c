#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include"rogue_like.h"


void creer_map1(char matrice[N][M])
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

void creer_map2(char matrice[A][B])
{

	int i, j;
	char res;
	
	for(i=0; i<A; i++){
		for(j=0; j<B; j++){
			matrice[i][j]='.';
		}
	}

	i=0;
	for(j=1; j<B-1; j++){
		matrice[i][j]='=';
	}
	
	j=0;
	for(i=1; i<A-1; i++){
		matrice[i][j]='#';
	}

	j=B-1;
	for(i=1; i<A-1; i++){
		matrice[i][j]='#';
	}

	i=A-1;
	for(j=1; j<B-1; j++){
		matrice[i][j]='=';
	}
	
	i=0;
	j=0;
	matrice[i][j]='+';

	i=A-1;
	j=B-1;
	matrice[i][j]='+';
	
	i=A-1;
	j=0;
	matrice[i][j]='+';

	i=0;
	j=B-1;
	matrice[i][j]='+';

}

void creer_map3(char matrice[C][D])
{

	int i, j;
	char res;
	
	for(i=0; i<C; i++){
		for(j=0; j<D; j++){
			matrice[i][j]='.';
		}
	}

	i=0;
	for(j=1; j<D-1; j++){
		matrice[i][j]='=';
	}
	
	j=0;
	for(i=1; i<C-1; i++){
		matrice[i][j]='#';
	}

	j=D-1;
	for(i=1; i<C-1; i++){
		matrice[i][j]='#';
	}

	i=C-1;
	for(j=1; j<D-1; j++){
		matrice[i][j]='=';
	}
	
	i=0;
	j=0;
	matrice[i][j]='+';

	i=C-1;
	j=D-1;
	matrice[i][j]='+';
	
	i=C-1;
	j=0;
	matrice[i][j]='+';

	i=0;
	j=D-1;
	matrice[i][j]='+';

}