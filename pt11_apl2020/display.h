#ifndef DISPLAY_H
#define DISPLAY_H

void Ecran1(void);
void Ecran2(int taille_grille);
void tracer_grille(int nb_case);
void afficher_menu(int *p_nb_joueur, int *p_taille_grille);
void afficher_menu_fin(short int winner, int bloque);
void afficher_partie (int virtual_board[][10], int taille_grille);

#endif /*DISPLAY_H*/