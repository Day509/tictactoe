#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gagnant(int *(tab)[3],int joueur[])
{
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			if ((i < 3) && (j == 0))
			{
				if((tab[i][j] == joueur[0]) && (tab[i][j+1] == joueur[0]) && (tab[i][j+2] == joueur[0]))
				{

					return 1;
				}
				else if((tab[i][j] == joueur[1]) && (tab[i][j+1] == joueur[1]) && (tab[i][j+2] == joueur[1]))
				{

					return 1;
				}
			}
			if ((i == 0) && (j < 3))
			{
				if((tab[i][j] == joueur[1]) && (tab[i+1][j] == joueur[1]) && (tab[i+2][j] == joueur[1]))
				{

					return 1;
				}
			}
			if ((i == 0) && (j == 0))
			{
				if((tab[i][j] == joueur[0]) && (tab[i+1][j] == joueur[0]) && (tab[i+2][j] == joueur[0]))
				{

					return 1;
				}
				else if((tab[i][j] == joueur[1]) && (tab[i+1][j] == joueur[1]) && (tab[i+2][j] == joueur[1]))
				{

					return 1;
				}
			}
			if ((i == 2) && (j == 2))
			{
				if((tab[i][j] == joueur[0]) && (tab[i-1][j-1] == joueur[0]) && (tab[i-2][j-2] == joueur[0]))
				{

					return 1;
				}
				else if((tab[i][j] == joueur[1]) && (tab[i-1][j-1] == joueur[1]) && (tab[i-2][j-2] == joueur[1]))
				{

					return 1;
				}
			}
		}
	}
	return 0;
}



void Presentation_JoueurvsCPU()
{
	int grille[3][3]={0};
	int joueur[2]={1,2};
	int x = joueur[0];
	int compris = 0; fini = 0;
	while(compris != 1){
		printf("Bonjour\nBienvenue dans le mode Joueur VS CPU\n Le principe est simple, Vous devez taper les coordonnées de la case que vous voulez choisir puis appuyez sur entrer\nExemple: 1.3 correspond à la première colonne de la troisième ligne\n");
		printf("Si vous avez tous compris tapez 1 : ");
		scanf("%d", &compris);
		printf("\n");
	}

	printf("Bien commençons\n");

	while(fini !=1)
	{
		if (x == joueur[0])
		{
			/* code */
		}
		printf("Où voulez-vous placez votre pion?\n");

	}
}