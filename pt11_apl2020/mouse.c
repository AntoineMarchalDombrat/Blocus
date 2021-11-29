#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <string.h>
#include "mouse.h"

/* affecte certaines valeurs aux variables taille_grille et nb_joueur en fonction des coordonnées du click de l'utilisateur */
void selection_menu(int x, int y, int *p_nb_joueur, int *p_taille_grille, short int *p_etat){

	if (x > 323 && x < 445 && y>190 && y <235){
		*p_nb_joueur=1;
	}

	else if (x > 625 && x < 763 && y>190 && y<235) {
		*p_nb_joueur=2;
	}

	if (y< 380 && y>350){

		if(x<289 && x>250){
			*p_taille_grille=3;

		} else if(x<383 && x>335){
			*p_taille_grille=4;

		}else if(x<470 && x>426){
			*p_taille_grille=5;

		}else if(x<561 && x>517){
			*p_taille_grille=6;

		}else if(x<651 && x>607){
			*p_taille_grille=7;

		}else if(x<741 && x>697){
			*p_taille_grille=8;

		}else if(x<832 && x>788){
			*p_taille_grille=9;
		}

	} else if(x<714 && x>294 && y>446 && y<563){
		*p_etat=2;
	}	
}
/* Verifie si l'utilisateur a cliqué sur le bouton Exit. Si c'est la cas, elle change la valeur de la v
ariable exit et de *p_etat afin de sortir des boucles et pour accéder à la fin du programme */
short int fermer(short int exit, short int *p_etat) {
	SourisPosition();
	if (989<_X && _X<1054 && 141<_Y && _Y<196) {
		exit=1;
		*p_etat=0;		
	}	
	return exit;
}
/* affecte 1 à etat lorsque les coordonnées du click correspondent au bouton "play again" */
void selection_menu_fin (int x, int y, short int* p_etat){
	if(x<699 && x>369 && y>430 && y<573){
		*p_etat=1;
	}
}