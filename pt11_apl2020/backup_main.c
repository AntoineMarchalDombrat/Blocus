#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <string.h>

void Ecran1(void){

	ChoisirEcran(1);
	ChargerImageFond("./Image/Menu_1.png");
	CopierZone(1,0,0,0,1067,600,0,0);
}

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

void Ecran2(int taille_grille){
	ChoisirEcran(2);
	ChargerImageFond("./Image/fond.jpg");
	tracer_grille(taille_grille);
	CopierZone(2,0,0,0,1067,600,0,0);
}


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


void create_virtual_board(int board[][10], int taille_grille) {
	short int nb_clef=taille_grille +2;
	short int i,j;
	
	for (i=0;i<nb_clef;i++) {
		for (j=0;j<nb_clef;j++) {
			if (j==0 || j==nb_clef-1 || i==0 || i==nb_clef-1) {
				board[i][j]=5;
			} else {
				board[i][j]=0;
			}
		}
	}

}


short int fermer(short int exit, short int *p_etat) {
	Ecran1();
	SourisPosition();
	if (989<_X && _X<1054 && 141<_Y && _Y<196) {
		exit=1;
		*p_etat=0;		
	}	
	return exit;
}

void  selection_case_condamnation(short int taille_grille, int *p_colonne, int *p_ligne, int virtual_board[][10]){
	short int dans_grille = 0;
	short int valeur_case =1;
	int longueur_case = 500/taille_grille;
		while(!dans_grille || valeur_case != 0){
			dans_grille=0;
			valeur_case=1;
			if (SourisCliquee()){
			
				if ( _X>300 && _X<800 && _Y>50 && _Y<550){
					dans_grille=1;
					*p_colonne= ((_X - 300) / longueur_case) +1;
					*p_ligne= taille_grille - (((_Y - 50) / longueur_case) );
					valeur_case=virtual_board[*p_ligne][*p_colonne];


			}
		}
	}	
}


void  selection_case_pion(short int taille_grille, int *p_colonne, int *p_ligne, int virtual_board[][10], int ancienne_ligne, int ancienne_colonne){
	short int dans_grille = 0;
	short int valeur_case =1;
	short int case_a_cote =1;
	short int ecart_ligne;
	short int ecart_colonne;
	

	int longueur_case = 500/taille_grille;
		while(!dans_grille || valeur_case != 0 || case_a_cote ){
			dans_grille=0;
			valeur_case=1;
			case_a_cote=1;


			if (SourisCliquee()){
			
				if ( _X>300 && _X<800 && _Y>50 && _Y<550){
					dans_grille=1;
					*p_colonne= ((_X - 300) / longueur_case) +1;
					*p_ligne= taille_grille - (((_Y - 50) / longueur_case) );
					valeur_case=virtual_board[*p_ligne][*p_colonne];
					ecart_ligne= ancienne_ligne-*p_ligne;
					ecart_colonne=ancienne_colonne - *p_colonne;
					if (ecart_colonne >= -1 && ecart_colonne <=1 && ecart_ligne >= -1 && ecart_ligne <= 1 && (ecart_ligne!=0 || ecart_colonne !=0)){
					case_a_cote = 0;
				}

			}
		}
	
	}
	virtual_board[ancienne_ligne][ancienne_colonne]=0;
}


void  selection_case_condamnation_bot(short int taille_grille, int *p_colonne, int *p_ligne, int virtual_board[][10]){

	short int valeur_case ;

	*p_ligne=1;
	*p_colonne=1;
	valeur_case=virtual_board[*p_ligne][*p_colonne];
		while( valeur_case != 0){
			
			if (*p_colonne <= taille_grille){
				*p_colonne=*p_colonne+1;

			}else  {
				*p_colonne=1;
				*p_ligne=*p_ligne+1;
			}			
	
		
		valeur_case=virtual_board[*p_ligne][*p_colonne];
	
		}	
}


void  selection_case_pion_bot(short int taille_grille, int *p_colonne, int *p_ligne, int virtual_board[][10], int ancienne_ligne, int ancienne_colonne){

	short int valeur_case =1;
	short int case_a_cote =1;
	short int ecart_ligne;
	short int ecart_colonne;
	*p_ligne=1;
	*p_colonne=1;	

		while( valeur_case != 0 || case_a_cote ){

			valeur_case=1;
			case_a_cote=1;

			if (*p_colonne <= taille_grille){
				*p_colonne=*p_colonne+1;

			}else  {
				*p_colonne=1;
				*p_ligne=*p_ligne+1;
			}			


			valeur_case=virtual_board[*p_ligne][*p_colonne];
			ecart_ligne= ancienne_ligne-*p_ligne;
			ecart_colonne=ancienne_colonne - *p_colonne;
			if (ecart_colonne >= -1 && ecart_colonne <=1 && ecart_ligne >= -1 && ecart_ligne <= 1 && (ecart_ligne!=0 || ecart_colonne !=0)){
			case_a_cote = 0;
				

			
		}
	
	}
	virtual_board[ancienne_ligne][ancienne_colonne]=0;
}


void remplir_case(int tab[][10], int valeur, int ligne, int colonne) {
tab[ligne][colonne]=valeur;
}




int pion_bloque(int virtual_board[][10], int ligne, int colonne){
	int i;
	int j;
	int compteur =0;
	printf("%d;%d\n",ligne, colonne );
	for(i=ligne-1; i < ligne +2; i++){

		for (j=colonne-1 ; j< colonne +2; j++) {
				printf("%d\n",colonne);
			if (virtual_board[i][j]==0){
				compteur++;

			}
		}

	}
		printf("%d\n",compteur);
if (compteur==0){
	return 1;
} else {
	return 0;
}


}


void who_play(int joueur){
	couleur c;

	ChoisirEcran(2);

	if (joueur==1) {
		c=CouleurParComposante(205,92,92);
		ChoisirCouleurDessin(c);
		EcrireTexte(40,40,"Au tour de l'Indien",2);
	} else {
		c=CouleurParComposante(76,112,67);
		ChoisirCouleurDessin(c);
		EcrireTexte(40,40,"Au tour du Cowboy",2);
	}

	CopierZone(2,0,0,0,1067,600,0,0);

}



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


		}else if (virtual_board[ligne][colonne]==2){
			c=CouleurParComposante(76,112,67);
			ChoisirCouleurDessin(c);
			RemplirArc(300+(colonne-1)*longueur_case, 50+(taille_grille - ligne )*longueur_case,longueur_case,longueur_case,0,360);
		}else if (virtual_board[ligne][colonne]==3){
			c=CouleurParComposante(205,92,92);
			ChoisirCouleurDessin(c);
			DessinerSegment(300+(colonne-1)*longueur_case, 50+(taille_grille - ligne )*longueur_case, 300+(colonne)*(longueur_case), 50+(taille_grille - ligne+1 )*(longueur_case));
			DessinerSegment(300+(colonne-1)*longueur_case, 50+(taille_grille - ligne+1 )*(longueur_case ) ,300+(colonne)*(longueur_case) , 50+(taille_grille - ligne )*longueur_case);


		}else if (virtual_board[ligne][colonne]==4) {
			c=CouleurParComposante(76,112,67);
			ChoisirCouleurDessin(c);
			DessinerSegment(300+(colonne-1)*longueur_case, 50+(taille_grille - ligne )*longueur_case, 300+(colonne)*(longueur_case), 50+(taille_grille - ligne+1 )*(longueur_case ));
			DessinerSegment(300+(colonne-1)*longueur_case, 50+(taille_grille - ligne+1 )*(longueur_case ) ,300+(colonne)*(longueur_case) , 50+(taille_grille - ligne )*longueur_case);



		}




	}
}

CopierZone(2,0,0,0,1067,600,0,0);
}

void selection_menu_fin (int x, int y, short int* p_etat){
	if(x<699 && x>369 && y>430 && y<573){
		*p_etat=1;
	}
}





int main(int argc, char * argv[]) {
	short int exit=0;
	short int etat = 1;
	short int* p_etat = &etat;
	int nb_joueur = 2;	
	int taille_grille = 5;
	int *p_nb_joueur=&nb_joueur;
	int *p_taille_grille=&taille_grille;
	int ligne_j1;
	int colonne_j1;
	int ligne_j2;
	int colonne_j2;
	short int winner=0;

		int virtual_board[10][10];
		int ligne;
		int colonne;
		int *p_ligne=&ligne;
		int *p_colonne=&colonne;

		int a_qui_de_jouer =1;
		int bloque =0;


	InitialiserGraphique();
	CreerFenetre(10,10,1067,600);

	/*La fenêtre reste ouverte tant que le joueur ne clique pas sur exit*/
	while (!exit) {
		/*Menu*/
		while (etat==1){
			afficher_menu(p_nb_joueur, p_taille_grille);
			if (SourisCliquee()){
				selection_menu(_X,_Y, p_nb_joueur,p_taille_grille, p_etat);
				afficher_menu(p_nb_joueur, p_taille_grille);
				exit=fermer(exit, p_etat);
			}
		}
		/*Jeu*/
		
		a_qui_de_jouer =1;
		bloque =0;
		
	
		while (etat==2) {
			create_virtual_board(virtual_board, taille_grille);
			Ecran2(taille_grille);
			selection_case_condamnation(taille_grille, p_colonne, p_ligne, virtual_board);
			remplir_case(virtual_board,1,ligne,colonne);
			afficher_partie(virtual_board,taille_grille);
			ligne_j1 = ligne;
			colonne_j1 = colonne;
	

		
			if (nb_joueur==2) {
			
				selection_case_condamnation(taille_grille, p_colonne, p_ligne, virtual_board);
				remplir_case(virtual_board,2,ligne,colonne);
				afficher_partie(virtual_board,taille_grille);
				ligne_j2=ligne;
				colonne_j2=colonne;
		

		




				while (bloque==0) {

			




					if (a_qui_de_jouer==1){

						who_play(a_qui_de_jouer);
						selection_case_pion(taille_grille, p_colonne, p_ligne, virtual_board, ligne_j1, colonne_j1);
						ligne_j1 = ligne;
						colonne_j1 = colonne;
						remplir_case(virtual_board,1,ligne,colonne);
						afficher_partie(virtual_board,taille_grille);
						selection_case_condamnation(taille_grille, p_colonne, p_ligne, virtual_board);
						remplir_case(virtual_board,3,ligne,colonne);
				
						a_qui_de_jouer=2;


				
				




					} else if (a_qui_de_jouer==2) {

						who_play(a_qui_de_jouer);
						selection_case_pion(taille_grille, p_colonne, p_ligne, virtual_board, ligne_j2, colonne_j2);
						ligne_j2 = ligne;
						colonne_j2 = colonne;
						remplir_case(virtual_board,2,ligne,colonne);
						afficher_partie(virtual_board,taille_grille);
						selection_case_condamnation(taille_grille, p_colonne, p_ligne, virtual_board);
						remplir_case(virtual_board,4,ligne,colonne);

						a_qui_de_jouer=1;

				
					}

			

					afficher_partie(virtual_board,taille_grille);
					printf("j1\n");
					bloque =pion_bloque(virtual_board, ligne_j1, colonne_j1);
					if (bloque > 0) {
						puts("Je suis rentrer à winner=1");
						winner=1;
					}
					printf("j2\n");
					bloque +=pion_bloque(virtual_board, ligne_j2,colonne_j2);
					if (bloque > 0) {
						if (winner==0){
							puts("Je suis rentrer à winner=2");
							winner=2;	
						}
						etat = 3;
			
					}


				}

			} else if (nb_joueur==1){

				selection_case_condamnation_bot(taille_grille, p_colonne, p_ligne, virtual_board);
				remplir_case(virtual_board,2,ligne,colonne);
				afficher_partie(virtual_board,taille_grille);
				ligne_j2=ligne;
				colonne_j2=colonne;
		

		




				while (bloque==0) {

			




					if (a_qui_de_jouer==1){
				
						selection_case_pion(taille_grille, p_colonne, p_ligne, virtual_board, ligne_j1, colonne_j1);
						ligne_j1 = ligne;
						colonne_j1 = colonne;
						remplir_case(virtual_board,1,ligne,colonne);
						afficher_partie(virtual_board,taille_grille);
						selection_case_condamnation(taille_grille, p_colonne, p_ligne, virtual_board);
						remplir_case(virtual_board,3,ligne,colonne);
				
						a_qui_de_jouer=2;


				
				




					} else if (a_qui_de_jouer==2) {
						selection_case_pion_bot(taille_grille, p_colonne, p_ligne, virtual_board, ligne_j2, colonne_j2);
						ligne_j2 = ligne;
						colonne_j2 = colonne;
						remplir_case(virtual_board,2,ligne,colonne);
						afficher_partie(virtual_board,taille_grille);
						selection_case_condamnation_bot(taille_grille, p_colonne, p_ligne, virtual_board);
						remplir_case(virtual_board,4,ligne,colonne);
						a_qui_de_jouer=1;

				
					}

			
	
					afficher_partie(virtual_board,taille_grille);
		
					bloque =pion_bloque(virtual_board, ligne_j2, colonne_j2);
					if (bloque > 0) {
						winner=2;
					}	

		
					bloque +=pion_bloque(virtual_board, ligne_j1,colonne_j1);
					if (bloque > 0) {
						if (winner==0){
							winner=1;	
						}
						etat = 3;
					}	

				}

			}

		}





		
		/*Fin de partie*/
		while (etat==3) {
			afficher_menu_fin(winner,bloque);
			if (SourisCliquee()){
					selection_menu_fin(_X,_Y, p_etat);
					exit=fermer(exit, p_etat);
				}
		}
	}

	FermerGraphique();
	return EXIT_SUCCESS;

}