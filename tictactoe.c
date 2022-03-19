#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gagnant(char** grille, int a, char* joueur)
{
	int i,j;
	for (i = 0; i < 3; i++)// On vérifie chaque colonne
	{
		j = 0;
		if (grille[i][j] == joueur[a] && grille[i][j+1] == joueur[a] && grille[i][j+2] == joueur[a]) 
		{
			printf("\nLes %c ont gagnés\n\n", joueur[a]);
			return 1;
		}
	}
	for (j = 0; j < 3; j++)//On verifie chaque ligne
	{
		i = 0;
		if(grille[i][j] == joueur[a] && grille[i+1][j] == joueur[a] && grille[i+2][j] == joueur[a])
		{
			printf("\nLes %c ont gagnés\n\n", joueur[a]);
			return 1;
		}
	}
	i = 0; j = 0;
	
	if(grille[i][j] == joueur[a] && grille[i+1][j+1]== joueur[a] && grille[i+2][j+2] == joueur[a])// On vérifie la diagonale de gauche à droite 
	{
		printf("\nLes %c ont gagnés\n\n", joueur[a]);
		return 1;
	}
	i = 2; j = 0;
	
	if(grille[i][j] == joueur[a] && grille[i-1][j+1] == joueur[a] && grille[i-2][j+2] == joueur[a])//On vérifie la diagonale de droite à gauche
	{
		printf("\nLes %c ont gagnés\n\n", joueur[a]);
		return 1;
	}
	return 0;
}

void jeu(char** tab, char* p){
	srand(time(NULL));
	int aleatoire = rand()%2;
	char tour = p[aleatoire];
	int rempli = 0;
	while(rempli != 1)
	{
		int a, b, i, j;
		int verification = 0;
		printf("Où voulez-vous placez le curseur ? ");
		a = rand()%3;
		b = rand()%3;
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				while(tab[a][b] == p[0] || tab[a][b] == p[1])
				{
					a = rand()%3;
					b = rand()%3;
				}
			}
		}
		i = a; j = b;
		printf("Voici i:%d et voici j:%d\n", i,j);
		if (tour == p[0])
		{
			tab[i][j] = tour;
			tour = p[1];
			printf("c'est au tour du joueur 1\n");
		}

		else if (tour == p[1])
		{
			tab[i][j] = tour;
			tour = p[0];
			printf("c'est au tour du joueur 2\n");
		}

		for (i = 0; i < 3; i++) // On affiche le contenu de la grille  
		{
			for (j = 0; j < 3; j++)
			{
				printf("[%c]", tab[i][j]);
			}
			printf("\n");
		}

		if (gagnant(tab, 0, p) == 1)
		{
			rempli = 1;
		}
		else if (gagnant(tab, 1, p) == 1)
		{
			rempli = 1;
		}

		else{
			for (i = 0; i < 3; i++) // On vérifie la grille pour savoir si il y a un gagnant 
			{
				for (j = 0; j < 3; j++)
				{
					if(tab[i][j] != '_')
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
			
		
	}
}

int main(int argc, char const *argv[])
{
	
	char* joueur = malloc(sizeof(char)*2);
	char** grille = malloc(sizeof(char[3][3]));
	
	joueur[0] = 'X', joueur[1] = 'O';
	for (int a = 0; a < 3; a++)
	{
		for (int b = 0; b < 3; b++)
		{
			grille[a][b] = '_';
		}
	}
	jeu(grille, joueur);


	return 0;
}
