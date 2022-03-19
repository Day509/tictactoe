#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void jeu(char** tab, char* p){
	srand(time(NULL));
	int aleatoire = rand()%2;
	char tour = p[aleatoire];
	int rempli = 0;
	while(rempli != 1)
	{
		int a, b, i, j;
		int verification = 0;
		printf("Ou voulez-vous placez le curseur ? ");
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
