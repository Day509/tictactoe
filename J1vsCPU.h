#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Presentation_JoueurvsCPU(char** grille, char* joueur)
{
	srand(time(NULL));
	int i = 0, j = 0, a = rand()%2;
	char x = joueur[a];
	int compris = 0, fini = 0, nul=0;
	printf("Bonjour\nBienvenue dans le mode Joueur VS CPU\n");
	while(compris != 1)
	{
		printf("Le principe est simple, Vous devez taper les coordonnées de la case que vous voulez choisir puis appuyez sur entrer\nExemple: 1.3 correspond a la troisième colonne de la première ligne\n\nEt n'oubliez pas le '.' entre les chiffres\n");
		printf("Si vous avez tous compris tapez 1 : ");
		scanf("%d", &compris);
		printf("\n");
	}

	printf("C'est parti\n\n");
	a = rand()%2;
	x = joueur[a];
	if (x == 1)
	{
		printf("C'est le joueur %c qui commence\n", x);
	}
	else
	{
		printf("C'est l'ordinateur qui commence\n");
	}
	

	while(fini !=1)
	{
		if (x == joueur[0])
		{
			printf("Ou voulez-vous placez votre pion?\n");
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

			while(grille[i][j] != '_')
			{
				printf("Cette case est déja prise, Veuillez saisir une autre case\n");
				scanf("%d.%d\n", &i, &j);
			}
			grille[i][j] = x;
			if(gagnant(grille, 0, joueur) == 1)
			{
				printf("Le joueur %c a gagner\n", x);
				fini = 1;
			}
			else
			{
				printf("C'est au tour du CPU de jouer\n");
				x = joueur[1];
			}
		}
		else if (x == joueur[1])
		{
			i = rand()%3;
			j = rand()%3;

			while(grille[i][j] != '_')
			{
				i = rand()%3;
				j = rand()%3;
			}

			grille[i][j] = x;
			if(gagnant(grille, 1, joueur) == 1)
			{
				printf("Le joueur %c a gagner\n", x);
				fini = 1;
			}
			else
			{
				printf("C'est au tour du joueur 1 de jouer\n");
				x = joueur[0];
			}
			
		}

		affichageTAB(grille);
		for (int a = 0; a < 3; a++)
		{
			for (int b = 0; b < 3; b++)
			{
				if (grille[a][b] != '_')
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