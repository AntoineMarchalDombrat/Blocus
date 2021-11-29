#ifndef MOUSE_H
#define MOUSE_H

void selection_menu(int x, int y, int *p_nb_joueur, int *p_taille_grille, short int *p_etat);
short int fermer(short int exit, short int *p_etat);
void selection_menu_fin (int x, int y, short int* p_etat);

#endif /*MOUSE_H*/