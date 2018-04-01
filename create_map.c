/*!
*
*	\file create_map.c
*	\brief Creation des maps
*	\author Lucien BOUYEURE, Romane BUON, Yann PAULMERY
*	\version 0.1
*
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include"rogue_like.h"

/*!
*
*	\fn void creer_map1(char matrice[N][M])
*	\brief Création de la base de la map du niveau 1.
*	\param matrice Matrice contenant la map du niveau 1.
*
*/

void creer_map1(char matrice[N][M])
{

	int i, j;
	
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

/*!
*
*	\fn void creer_map2(char matrice[O][P])
*	\brief Création de la base de la map du niveau 2.
*	\param matrice Matrice contenant la map du niveau 2.
*
*/

void creer_map2(char matrice[O][P])
{

	int i, j;
	
	for(i=0; i<O; i++){
		for(j=0; j<P; j++){
			matrice[i][j]='.';
		}
	}

	i=0;
	for(j=1; j<P-1; j++){
		matrice[i][j]='=';
	}
	
	j=0;
	for(i=1; i<O-1; i++){
		matrice[i][j]='#';
	}

	j=P-1;
	for(i=1; i<O-1; i++){
		matrice[i][j]='#';
	}

	i=O-1;
	for(j=1; j<P-1; j++){
		matrice[i][j]='=';
	}
	
	i=0;
	j=0;
	matrice[i][j]='+';

	i=O-1;
	j=P-1;
	matrice[i][j]='+';
	
	i=O-1;
	j=0;
	matrice[i][j]='+';

	i=0;
	j=P-1;
	matrice[i][j]='+';

}

/*!
*
*	\fn void creer_map3(char matrice[M][Q])
*	\brief Création de la base de la map du niveau 3.
*	\param matrice Matrice contenant la map du niveau 3.
*
*/

void creer_map3(char matrice[M][Q])
{

	int i, j;
	
	for(i=0; i<M; i++){
		for(j=0; j<Q; j++){
			matrice[i][j]='.';
		}
	}

	i=0;
	for(j=1; j<Q-1; j++){
		matrice[i][j]='=';
	}
	
	j=0;
	for(i=1; i<M-1; i++){
		matrice[i][j]='#';
	}

	j=Q-1;
	for(i=1; i<M-1; i++){
		matrice[i][j]='#';
	}

	i=M-1;
	for(j=1; j<Q-1; j++){
		matrice[i][j]='=';
	}
	
	i=0;
	j=0;
	matrice[i][j]='+';

	i=M-1;
	j=Q-1;
	matrice[i][j]='+';
	
	i=M-1;
	j=0;
	matrice[i][j]='+';

	i=0;
	j=Q-1;
	matrice[i][j]='+';

}
