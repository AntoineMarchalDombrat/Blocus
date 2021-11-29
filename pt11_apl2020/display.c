#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <string.h>
#include "display.h"
/* affiche le fond d'écran du menu */
void Ecran1(void){

	ChoisirEcran(1);
	ChargerImageFond("./Image/Menu_1.png");
	CopierZone(1,0,0,0,1067,600,0,0);
}


/* affiche le fond d'écran de la partie ainsi que la grille de dimension taille_grille */
void Ecran2(int taille_grille){
	ChoisirEcran(2);
	ChargerImageFond("./Image/fond.jpg");
	tracer_grille(taille_grille);
	CopierZone(2,0,0,0,1067,600,0,0);
}


/* trace la grille de dimension taille grille */
void tracer_grille(int nb_case){
	int ligne;
	int colonne;
	int longueur_case = 500/nb_case;
	for (ligne=0; ligne< nb_case ; ligne++) {
		for (colonne =0; colonne<nb_case ; colonne++) {
			DessinerRectangle(300+colonne*longueur_case,50+ligne*longueur_case,longueur_case,longueur_case);
		}
	}
}
/* affiche le fond d'écran du menu, ainsi que les ticks correspondant aux choix de l'utilisateur */
void afficher_menu(int *p_nb_joueur, int *p_taille_grille){
	
	Ecran1();
	if(*p_nb_joueur==1){
		ChargerImage("./Image/tick.png",431,206, 0,0,14,14);

	}else if(*p_nb_joueur==2){
		ChargerImage("./Image/tick.png",749,204, 0,0,14,14);
	}
	if(*p_taille_grille==3){
		ChargerImage("./Image/tick.png",275,358, 0,0,14,14);
	}
	else if(*p_taille_grille==4){
		ChargerImage("./Image/tick.png",369,358, 0,0,14,14);
	} else if(*p_taille_grille==5){
		ChargerImage("./Image/tick.png",456,358, 0,0,14,14);
	} else if(*p_taille_grille==6){
		ChargerImage("./Image/tick.png",547,358, 0,0,14,14);
	}else if(*p_taille_grille==7){
		ChargerImage("./Image/tick.png",637,358, 0,0,14,14);
	}else if(*p_taille_grille==8){
		ChargerImage("./Image/tick.png",727,358, 0,0,14,14);
	}else if(*p_taille_grille==9){
		ChargerImage("./Image/tick.png",818,358, 0,0,14,14);
	}
	CopierZone(1,0,0,0,1067,600,0,0);
}

/* affiche le fond d'écran du menu de fin ainsi que le nom du gagnant */
void afficher_menu_fin(short int winner, int bloque){
	ChoisirEcran(3);

	couleur c=CouleurParComposante(0,0,0);
	ChoisirCouleurDessin(c);

	if (bloque==2) {
		ChargerImageFond("./Image/Ecran_fin_indien.png");
		
	} else {
		if (winner==1) {
			ChargerImageFond("./Image/Ecran_fin_cowboy.png");
		} else if (winner==2){
			ChargerImageFond("./Image/Ecran_fin_indien.png");
		}
	}

	CopierZone(3,0,0,0,1067,600,0,0);
}


/* affiche le fond d'écran du jeu, la grille, les pions, et les cases condamnées */
void afficher_partie (int virtual_board[][10], int taille_grille) {
int ligne;
int colonne;
couleur c;
int longueur_case=500/taille_grille;
c=CouleurParComposante(255,255,255);
ChoisirCouleurDessin(c);
ChoisirEcran(2);
	ChargerImageFond("./Image/fond.jpg");
	tracer_grille(taille_grille);


for (ligne=taille_grille; ligne > 0; ligne--){
	for (colonne=1; colonne<=taille_grille; colonne++){
		if (virtual_board[ligne][colonne]==1){
			c=CouleurParComposante(205,92,92);
			ChoisirCouleurDessin(c);
			RemplirArc(300+(colonne-1)*longueur_case, 50+(taille_grille - ligne )*longueur_case,longueur_case,longueur_case,0,360);


		} else if (virtual_board[ligne][colonne]==2){
			c=CouleurParComposante(76,112,67);
			ChoisirCouleurDessin(c);
			RemplirArc(300+(colonne-1)*longueur_case, 50+(taille_grille - ligne )*longueur_case,longueur_case,longueur_case,0,360);
		} else if (virtual_board[ligne][colonne]==3){
			c=CouleurParComposante(205,92,92);
			ChoisirCouleurDessin(c);
			DessinerSegment(300+(colonne-1)*longueur_case, 50+(taille_grille - ligne )*longueur_case, 300+(colonne)*(longueur_case), 50+(taille_grille - ligne+1 )*(longueur_case));
			DessinerSegment(300+(colonne-1)*longueur_case, 50+(taille_grille - ligne+1 )*(longueur_case ) ,300+(colonne)*(longueur_case) , 50+(taille_grille - ligne )*longueur_case);


		} else if (virtual_board[ligne][colonne]==4) {
			c=CouleurParComposante(76,112,67);
			ChoisirCouleurDessin(c);
			DessinerSegment(300+(colonne-1)*longueur_case, 50+(taille_grille - ligne )*longueur_case, 300+(colonne)*(longueur_case), 50+(taille_grille - ligne+1 )*(longueur_case ));
			DessinerSegment(300+(colonne-1)*longueur_case, 50+(taille_grille - ligne+1 )*(longueur_case ) ,300+(colonne)*(longueur_case) , 50+(taille_grille - ligne )*longueur_case);



		}

		}

	}
	
CopierZone(2,0,0,0,1067,600,0,0);
}