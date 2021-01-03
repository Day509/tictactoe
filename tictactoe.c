#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gagnant(char (*grille)[3], int* rempli, int a, char* joueur)
{
	int i,j;
	for (i = 0; i < 3; i++)// On vérifie chaque colonne
	{
		j = 0;
		if (grille[i][j] == joueur[a] && grille[i][j+1] == joueur[a] && grille[i][j+2] == joueur[a]) 
			{
				printf("\nLes %c ont gagnés\n\n", joueur[a]);
				*rempli = 1;
			}
	}
	for (j = 0; j < 3; j++)//On verifie chaque ligne
	{
		i = 0;
		if(grille[i][j] == joueur[a] && grille[i+1][j] == joueur[a] && grille[i+2][j] == joueur[a])
		{
			printf("\nLes %c ont gagnés\n\n", joueur[a]);
			*rempli = 1;
		}
	}
	i = 0; j = 0;
	
		if(grille[i][j] == joueur[a] && grille[i+1][j+1]== joueur[a] && grille[i+2][j+2] == joueur[a])// On vérifie la diagonale de gauche à droite 
		{
			printf("\nLes %c ont gagnés\n\n", joueur[a]);
			*rempli = 1;
		}
	i = 2; j = 0;
	
	if(grille[i][j] == joueur[a] && grille[i-1][j+1] == joueur[a] && grille[i-2][j+2] == joueur[a])//On vérifie la diagonale de droite à gauche
		{
			printf("\nLes %c ont gagnés\n\n", joueur[a]);
			*rempli = 1;
		}
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int i = 0; int j = 0; int a; int b; int aleatoire = rand()%2;
	int rempli = 0; int verification;
	char joueur[2] ={'X','O'};
	int x = joueur[aleatoire];
	char grille[3][3] = 
	{
		{'_','_','_'},
		{'_','_','_'},
		{'_','_','_'}
	};


	while(rempli != 1)
	{
		verification = 0;
		printf("Où voulez-vous placez le curseur ? ");
		a = rand()%3;
		b = rand()%3;
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				while(grille[a][b] == joueur[0] || grille[a][b] == joueur[1])
				{
					a = rand()%3;
					b = rand()%3;
				}
			}
		}
		i = a; j = b;
		printf("Voici i:%d et voici j:%d\n", i,j);
		if (x == joueur[0])
		{
			grille[i][j] = x;
			x = joueur[1];
			printf("c'est au tour du joueur 1\n");
		}

		else if (x == joueur[1])
		{
			grille[i][j] = x;
			x = joueur[0];
			printf("c'est au tour du joueur 2\n");
		}

		for (i = 0; i < 3; i++) // On affiche le contenu de la grille  
		{
			for (j = 0; j < 3; j++)
			{
				printf("[%c]", grille[i][j]);
			}
			printf("\n");
		}

		gagnant(grille,&rempli,0,joueur);
			
		gagnant(grille,&rempli,1,joueur);		
			
		for (i = 0; i < 3; i++) // On vérifie la grille pour savoir si il y a un gagnant 
			{
				for (j = 0; j < 3; j++)
				{
					if(grille[i][j] != '_')
					{
						verification ++;
					}
					if(verification == 9)
					{
						rempli = 1;
					}
				}
			}
	}

	return 0;
}
