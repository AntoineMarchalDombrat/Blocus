#ifndef GAME_H
#define GAME_H

void create_virtual_board(int board[][10], int taille_grille);
void  selection_case_condamnation(short int taille_grille, int *p_colonne, int *p_ligne, int virtual_board[][10]);
void  selection_case_pion(short int taille_grille, int *p_colonne, int *p_ligne, int virtual_board[][10], int ancienne_ligne, int ancienne_colonne);
void  selection_case_condamnation_bot(short int taille_grille, int *p_colonne, int *p_ligne, int virtual_board[][10]);
void  selection_case_pion_bot(short int taille_grille, int *p_colonne, int *p_ligne, int virtual_board[][10], int ancienne_ligne, int ancienne_colonne);
void remplir_case(int tab[][10], int valeur, int ligne, int colonne);
int pion_bloque(int virtual_board[][10], int ligne, int colonne);
void who_play(int joueur);

#endif /*GAME_H*/