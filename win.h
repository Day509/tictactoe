#include <stdio.h>

void affichageTAB(char** tab)
{
	for(int i=0 ;i < 3; i++)
	{
		for(int j = 0;j < 3; j++)
		{
			printf("[%c]", tab[i][j]);
		}
		printf("\n");
	}
}

int gagnant(char** grille, int a, char* joueur)
{
	int i,j;
	for (i = 0; i < 3; i++)// On vérifie chaque colonne
	{
		j = 0;
		if (grille[i][j] == joueur[a] && grille[i][j+1] == joueur[a] && grille[i][j+2] == joueur[a]) 
		{
			printf("\nLes %c ont gagnes\n\n", joueur[a]);
			return 1;
		}
	}
	for (j = 0; j < 3; j++)//On verifie chaque ligne
	{
		i = 0;
		if(grille[i][j] == joueur[a] && grille[i+1][j] == joueur[a] && grille[i+2][j] == joueur[a])
		{
			printf("\nLes %c ont gagnes\n\n", joueur[a]);
			return 1;
		}
	}
	i = 0; j = 0;
	
	if(grille[i][j] == joueur[a] && grille[i+1][j+1]== joueur[a] && grille[i+2][j+2] == joueur[a])// On vérifie la diagonale de gauche à droite 
	{
		printf("\nLes %c ont gagnes\n\n", joueur[a]);
		return 1;
	}
	i = 2; j = 0;
	
	if(grille[i][j] == joueur[a] && grille[i-1][j+1] == joueur[a] && grille[i-2][j+2] == joueur[a])//On vérifie la diagonale de droite à gauche
	{
		printf("\nLes %c ont gagnes\n\n", joueur[a]);
		return 1;
	}
	return 0;
}