#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <string.h>
#include "game.h"

/* rempli les cases du tableau  bidimensionnel(virtual_board) avec des 1 sur les bordures et des 0 sur le reste */
void create_virtual_board(int board[][10], int taille_grille){
	short int nb_clef = taille_grille + 2;
	short int i, j;

	for (i = 0; i < nb_clef; i++){
		for (j = 0; j < nb_clef; j++){
			if (j == 0 || j == nb_clef - 1 || i == 0 || i == nb_clef - 1){
				board[i][j] = 5;
			}
			else{
				board[i][j] = 0;
			}
		}
	}
}

/*affecte aux variables ligne et colonne  la ligne et la colonne de la première case vide selectionnée par l'utilisateur */
void selection_case_condamnation(short int taille_grille, int *p_colonne, int *p_ligne, int virtual_board[][10]){
	short int dans_grille = 0;
	short int valeur_case = 1;
	int longueur_case = 500 / taille_grille;
	while (!dans_grille || valeur_case != 0){
		dans_grille = 0;
		valeur_case = 1;
		if (SourisCliquee()){

			if (_X > 300 && _X < 800 && _Y > 50 && _Y < 550){
				dans_grille = 1;
				*p_colonne = ((_X - 300) / longueur_case) + 1;
				*p_ligne = taille_grille - (((_Y - 50) / longueur_case));
				valeur_case = virtual_board[*p_ligne][*p_colonne];
			}
		}
	}
}
/* affecte aux variables ligne et colonne la ligne et la colonne de la première case vide autour du pion du joueur selectionnée par l'utilisateur*/
void selection_case_pion(short int taille_grille, int *p_colonne, int *p_ligne, int virtual_board[][10], int ancienne_ligne, int ancienne_colonne){
	short int dans_grille = 0;
	short int valeur_case = 1;
	short int case_a_cote = 1;
	short int ecart_ligne;
	short int ecart_colonne;

	int longueur_case = 500 / taille_grille;
	while (!dans_grille || valeur_case != 0 || case_a_cote){
		dans_grille = 0;
		valeur_case = 1;
		case_a_cote = 1;

		if (SourisCliquee()){

			if (_X > 300 && _X < 800 && _Y > 50 && _Y < 550){
				dans_grille = 1;
				*p_colonne = ((_X - 300) / longueur_case) + 1;
				*p_ligne = taille_grille - (((_Y - 50) / longueur_case));
				valeur_case = virtual_board[*p_ligne][*p_colonne];
				ecart_ligne = ancienne_ligne - *p_ligne;
				ecart_colonne = ancienne_colonne - *p_colonne;
				if (ecart_colonne >= -1 && ecart_colonne <= 1 && ecart_ligne >= -1 && ecart_ligne <= 1 && (ecart_ligne != 0 || ecart_colonne != 0))	{
					case_a_cote = 0;
				}
			}
		}
	}
	virtual_board[ancienne_ligne][ancienne_colonne] = 0;
}

/* affecte aux variables ligne et colonne  la ligne et la colonne d'une case vide */
void selection_case_condamnation_bot(short int taille_grille, int *p_colonne, int *p_ligne, int virtual_board[][10]){

	short int valeur_case;

	*p_ligne = 1;
	*p_colonne = 1;
	valeur_case = virtual_board[*p_ligne][*p_colonne];
	while (valeur_case != 0){

		if (*p_colonne <= taille_grille){ 
			*p_colonne = *p_colonne + 1;
		}
		else {
		 	*p_colonne = 1;
			*p_ligne = *p_ligne + 1;
		}

		valeur_case = virtual_board[*p_ligne][*p_colonne];
	}
}
/* affecte aux variables ligne et colonne la ligne et la colonne d'une case vide à proximité du pion du robot */
void selection_case_pion_bot(short int taille_grille, int *p_colonne, int *p_ligne, int virtual_board[][10], int ancienne_ligne, int ancienne_colonne){

	short int valeur_case = 1;
	short int case_a_cote = 1;
	short int ecart_ligne;
	short int ecart_colonne;
	*p_ligne = 1;
	*p_colonne = 1;

	while (valeur_case != 0 || case_a_cote){

		valeur_case = 1;
		case_a_cote = 1;

		if (*p_colonne <= taille_grille){
		 *p_colonne = *p_colonne + 1;
		}
		else{
			*p_colonne = 1;
			*p_ligne = *p_ligne + 1;
		}

		valeur_case = virtual_board[*p_ligne][*p_colonne];
		ecart_ligne = ancienne_ligne - *p_ligne;
		ecart_colonne = ancienne_colonne - *p_colonne;
		if (ecart_colonne >= -1 && ecart_colonne <= 1 && ecart_ligne >= -1 && ecart_ligne <= 1 && (ecart_ligne != 0 || ecart_colonne != 0)){
			case_a_cote = 0;
		}
	}
	virtual_board[ancienne_ligne][ancienne_colonne] = 0;
}

/* affecte valeur à la case de la matrice "virtual_board" de coordonnées ligne et colonne*/
void remplir_case(int tab[][10], int valeur, int ligne, int colonne){
	tab[ligne][colonne] = valeur;
}

/* renvoie 1 si toutes les cases autour de la case de coordonnées (ligne, colonne) ne sont pas vides */
int pion_bloque(int virtual_board[][10], int ligne, int colonne){
	int i;
	int j;
	int compteur = 0;
	for (i = ligne - 1; i < ligne + 2; i++){

		for (j = colonne - 1; j < colonne + 2; j++)	{
			if (virtual_board[i][j] == 0){
				compteur++;
			}
		}
	}

	if (compteur == 0){
		return 1;
	}
	else{
		return 0;
	}
}

/* affiche le nom du joueur qui doit jouer */
void who_play(int joueur){
	couleur c;

	ChoisirEcran(2);

	if (joueur == 1){
		c = CouleurParComposante(205, 92, 92);
		ChoisirCouleurDessin(c);
		EcrireTexte(40, 40, "Au tour de l'Indien", 2);
	}
	else{
		c = CouleurParComposante(76, 112, 67);
		ChoisirCouleurDessin(c);
		EcrireTexte(40, 40, "Au tour du Cowboy", 2);
	}

	CopierZone(2, 0, 0, 0, 1067, 600, 0, 0);

}