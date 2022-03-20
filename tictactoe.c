#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "win.h"
#include "CPUvsCPU.h"
#include "J1vsCPU.h"
#include "J1vsJ2.h"

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
	
	printf("Choissisez votre mode: \n1: CPUvsCPU     2:J1vsCPU     3:J1vsJ2   \nQuel est votre choix: ");
	int mode = 0;
	scanf("%i", &mode);
	
	switch(mode)
	{
		case 1:
			jeu(grille, joueur);
			break;

		case 2:
			Presentation_JoueurvsCPU(grille, joueur);
			break;
			
		case 3:
			Presentation_J1vsJ2(grille, joueur);
			break;

		default:
			break;
	}
	return 0;
}
