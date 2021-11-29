#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <string.h>
#include "display.h"
#include "game.h"
#include "mouse.h"

int main(int argc, char *argv[]){
  short int exit = 0;
  short int etat = 1;
  short int *p_etat = &etat;
  int nb_joueur = 2;
  int taille_grille = 5;
  int *p_nb_joueur = &nb_joueur;
  int *p_taille_grille = &taille_grille;
  int ligne_j1;
  int colonne_j1;
  int ligne_j2;
  int colonne_j2;
  short int winner = 0;

  int virtual_board[10][10];
  int ligne;
  int colonne;
  int *p_ligne = &ligne;
  int *p_colonne = &colonne;

  int a_qui_de_jouer;
  int bloque;

  InitialiserGraphique();
  CreerFenetre(10, 10, 1067, 600);

  /*La fenêtre reste ouverte tant que le joueur ne clique pas sur exit*/
  while (!exit){
    /*Menu*/
    while (etat == 1){
      afficher_menu(p_nb_joueur, p_taille_grille);
      if (SourisCliquee()){
        selection_menu(_X, _Y, p_nb_joueur, p_taille_grille, p_etat);
        afficher_menu(p_nb_joueur, p_taille_grille);
        exit = fermer(exit, p_etat);
      }
    }
    /*Jeu*/

    a_qui_de_jouer = 1;
    bloque = 0;
    winner = 0;

    while (etat == 2){
      create_virtual_board(virtual_board, taille_grille);
      Ecran2(taille_grille);
      selection_case_condamnation(taille_grille, p_colonne, p_ligne, virtual_board);
      remplir_case(virtual_board, 1, ligne, colonne);
      afficher_partie(virtual_board, taille_grille);
      ligne_j1 = ligne;
      colonne_j1 = colonne;

      if (nb_joueur == 2){

        selection_case_condamnation(taille_grille, p_colonne, p_ligne, virtual_board);
        remplir_case(virtual_board, 2, ligne, colonne);
        afficher_partie(virtual_board, taille_grille);
        ligne_j2 = ligne;
        colonne_j2 = colonne;

        while (bloque == 0){

          if (a_qui_de_jouer == 1){

            who_play(a_qui_de_jouer);
            selection_case_pion(taille_grille, p_colonne, p_ligne, virtual_board, ligne_j1, colonne_j1);
            ligne_j1 = ligne;
            colonne_j1 = colonne;
            remplir_case(virtual_board, 1, ligne, colonne);
            afficher_partie(virtual_board, taille_grille);
            selection_case_condamnation(taille_grille, p_colonne, p_ligne, virtual_board);
            remplir_case(virtual_board, 3, ligne, colonne);

            a_qui_de_jouer = 2;
          }
          else if (a_qui_de_jouer == 2){

            who_play(a_qui_de_jouer);
            selection_case_pion(taille_grille, p_colonne, p_ligne, virtual_board, ligne_j2, colonne_j2);
            ligne_j2 = ligne;
            colonne_j2 = colonne;
            remplir_case(virtual_board, 2, ligne, colonne);
            afficher_partie(virtual_board, taille_grille);
            selection_case_condamnation(taille_grille, p_colonne, p_ligne, virtual_board);
            remplir_case(virtual_board, 4, ligne, colonne);

            a_qui_de_jouer = 1;
          }

          afficher_partie(virtual_board, taille_grille);
          bloque = pion_bloque(virtual_board, ligne_j1, colonne_j1);
          if (bloque > 0){
            winner = 1;
          }
          bloque += pion_bloque(virtual_board, ligne_j2, colonne_j2);
          if (bloque > 0){
            if (winner == 0){
              winner = 2;
            }
            etat = 3;
          }
        }
      }
      else if (nb_joueur == 1){

        selection_case_condamnation_bot(taille_grille, p_colonne, p_ligne, virtual_board);
        remplir_case(virtual_board, 2, ligne, colonne);
        afficher_partie(virtual_board, taille_grille);
        ligne_j2 = ligne;
        colonne_j2 = colonne;

        while (bloque == 0){

          if (a_qui_de_jouer == 1){

            selection_case_pion(taille_grille, p_colonne, p_ligne, virtual_board, ligne_j1, colonne_j1);
            ligne_j1 = ligne;
            colonne_j1 = colonne;
            remplir_case(virtual_board, 1, ligne, colonne);
            afficher_partie(virtual_board, taille_grille);
            selection_case_condamnation(taille_grille, p_colonne, p_ligne, virtual_board);
            remplir_case(virtual_board, 3, ligne, colonne);

            a_qui_de_jouer = 2;
          }
          else if (a_qui_de_jouer == 2){
            selection_case_pion_bot(taille_grille, p_colonne, p_ligne, virtual_board, ligne_j2, colonne_j2);
            ligne_j2 = ligne;
            colonne_j2 = colonne;
            remplir_case(virtual_board, 2, ligne, colonne);
            afficher_partie(virtual_board, taille_grille);
            selection_case_condamnation_bot(taille_grille, p_colonne, p_ligne, virtual_board);
            remplir_case(virtual_board, 4, ligne, colonne);
            a_qui_de_jouer = 1;
          }

          afficher_partie(virtual_board, taille_grille);

          bloque = pion_bloque(virtual_board, ligne_j2, colonne_j2);
          if (bloque > 0){
            winner = 2;
          }

          bloque += pion_bloque(virtual_board, ligne_j1, colonne_j1);
          if (bloque > 0){
            if (winner == 0){
              winner = 1;
            }
            etat = 3;
          }
        }
      }
    }

    /*Fin de partie*/
    while (etat == 3){
      afficher_menu_fin(winner, bloque);
      if (SourisCliquee()){
        selection_menu_fin(_X, _Y, p_etat);
        exit = fermer(exit, p_etat);
      }
    }
  }

  FermerGraphique();
  return EXIT_SUCCESS;

}