#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void affichageTAB(int (*tab)[3])
{
	for(int i=0 ;i < 3; i++)
	{
		for(int j = 0;j < 3; j++)
		{
			printf("[%d]", tab[i][j]);
		}
		printf("\n");
	}
}

int gagnant(int (*tab)[3],int joueur[])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if ((i < 3) && (j == 0))//Vérifie un gagnant à l'horizontale 
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
			if ((i == 0) && (j < 3))//Vérifie un gagnant à la verticale
			{
				if((tab[i][j] == joueur[0]) && (tab[i+1][j] == joueur[0]) && (tab[i+2][j] == joueur[0]))
				{
					return 1;
				}
				if((tab[i][j] == joueur[1]) && (tab[i+1][j] == joueur[1]) && (tab[i+2][j] == joueur[1]))
				{
					return 1;
				}
			}
			if ((i == 0) && (j == 0))//Vérifie un gagnant en diagonale gauche-droite
			{
				if((tab[i][j] == joueur[0]) && (tab[i+1][j+1] == joueur[0]) && (tab[i+2][j+2] == joueur[0]))
				{
					return 1;
				}
				else if((tab[i][j] == joueur[1]) && (tab[i+1][j+2] == joueur[1]) && (tab[i+2][j+2] == joueur[1]))
				{
					return 1;
				}
			}
			if ((i == 2) && (j == 0))//Vérifie un gagnant en diagonale droite-gauche
			{
				if((tab[i][j] == joueur[0]) && (tab[i-1][j+1] == joueur[0]) && (tab[i-2][j+2] == joueur[0]))
				{
					return 1;
				}
				else if((tab[i][j] == joueur[1]) && (tab[i-1][j+1] == joueur[1]) && (tab[i-2][j+2] == joueur[1]))
				{
					return 1;
				}
			}
		}
	}
	return 0;
}
void Presentation_J1vsJ2()
{
	srand(time(NULL));
	int grille[3][3]={0};
	int joueur[2]={1,2};
	int i = 0; int j = 0;int x; int a;
	int compris = 0; int fini = 0; int nul=0;
	printf("Bonjour\nBienvenue dans le mode J1 VS J2\n");
	while(compris != 1)
	{
		printf("Le principe est simple, Vous devez taper les coordonnées de la case que vous voulez choisir puis appuyez sur entrer\nExemple: 1.3 correspond à la troisième colonne de la première ligne\n\nEt n'oubliez pas le '.' entre les chiffres\n");
		printf("Si vous avez tous compris tapez 1 : ");
		scanf("%d", &compris);
		printf("\n");
	}

	printf("Bien commençons\n");
	a = rand()%2;
	x = joueur[a];
	printf("C'est le joueur %d qui commence\n", x);

	while(fini != 1)
	{
		if (x == joueur[0])
		{
			printf("Où voulez-vous placez votre pion?\n");
			scanf("%d.%d", &i, &j);
			printf("\nVoici i: %d, j: %d\n", i,j);
			if((i >= 4) || (j >= 4))
			{
				while ((i >= 4) || (j >= 4))
				{
					printf("Votre saisie n'est pas bonne, veuillez réesayer\n");
					scanf("%d.%d\n", &i, &j);
				}
			}
			i = i-1; j = j-1;

			while(grille[i][j] != 0)
			{
				printf("Cette case est déja prise, Veuillez saisir une autre case\n");
				scanf("%d.%d\n", &i, &j);
			}
			grille[i][j] = x;
			affichage(grille);
			if(win(grille,joueur) == 1)
			{
				printf("Le joueur %d à gagner\n", x);
				fini = 1;
			}
			else
			{
				printf("C'est au tour du J2 de jouer\n");
				x = joueur[1];
			}
		}
		else if (x == joueur[1])
		{
			printf("Où voulez-vous placez votre pion?\n");
			scanf("%d.%d", &i, &j);
			printf("\nVoici i: %d, j: %d\n", i,j);
			if((i >= 4) || (j >= 4))
			{
				while ((i >= 4) || (j >= 4))
				{
					printf("Votre saisie n'est pas bonne, veuillez réesayer\n");
					scanf("%d.%d\n", &i, &j);
				}
			}
			i = i-1; j = j-1;

			while(grille[i][j] != 0)
			{
				printf("Cette case est déja prise, Veuillez saisir une autre case\n");
				scanf("%d.%d\n", &i, &j);
			}
			grille[i][j] = x;
			affichage(grille);
			if(win(grille,joueur) == 1)
			{
				printf("Le joueur %d à gagner\n", x);
				fini = 1;
			}
			else
			{
				printf("C'est au tour du J1 de jouer\n");
				x = joueur[0];
			}
			
		}
		for (int a = 0; a < 3; a++)
		{
			for (int b = 0; b < 3; b++)
			{
				if (grille[a][b] != 0)
				{
					nul += 1;
				}
			}
		}
		if (nul == 9)
		{
			printf("Il y a égalité\n");
			fini =1;
		}
		else
		{
			nul = 0;
		}
	}
}