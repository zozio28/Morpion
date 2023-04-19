#include <stdio.h>
#include <stdlib.h>
#define TAILLE 3

//Structure des joueurs
struct joueurs {
  char prenom [50];
  int age;
  char symbole;
  int numero;
};

typedef struct joueurs j;

//Procédure qui permet d'initialiser la grille
void initGrille(char tab[TAILLE][TAILLE]){
  for (int i=0 ; i<TAILLE ; i++){
    for (int j=0 ; j<TAILLE ; j++){
      tab[i][j]=0;
    }
  }
}

//Procédure qui permet d'afficher la grille
void affGrille(char tab[TAILLE][TAILLE], j joueur1, j joueur2){
  for (int i=0; i<TAILLE; i++){
    printf("+---+---+---+ \n");
    printf("|");
    for (int j=0; j<TAILLE; j++){
      switch (tab[i][j]){
        case 'X':
          printf(" %c |",joueur1.symbole);
          break;
        case '0':
          printf(" %c |",joueur2.symbole);
          break;
        default:
          printf("   |");
          break;
        }
    }
    printf("\n");
  }
  printf("+---+---+---+");
  printf("\n\n");
}

//Procédure qui permet à un joueur de placer son pion
int joue(char tab[TAILLE][TAILLE], j joueur_qui_joue, int i, int j){
  if (tab[i][j] == 0) {
    tab[i][j] = joueur_qui_joue.symbole;
    return 1;
  }
  else {
    printf("Case déjà occupée !\n");
    return 0;
  }
}

//Procédure qui permet à un joueur de saisir les coordonnées de son pion
j tour2jeu(char tab[TAILLE][TAILLE], j joueur_qui_joue, j joueur1, j joueur2) {
  //change de joueur
  switch(joueur_qui_joue.numero){
    case 1 :
      return joueur2;
      break;
    case 2 :
      return joueur1;
      break;
  }
  return joueur_qui_joue;
}

//Prédicat qui permet de tester si un joueur a gagné
int gagne (char tab[TAILLE][TAILLE], j joueur_qui_joue){

  // Vérification des lignes
  for (int i = 0; i < TAILLE; i++) {
    if (tab[i][0] == joueur_qui_joue.symbole && tab[i][1] == joueur_qui_joue.symbole && tab[i][2] == joueur_qui_joue.symbole) {
      return 1;
    }
  }

  // Vérification des colonnes
  for (int i = 0; i < TAILLE; i++) {
    if (tab[0][i] == joueur_qui_joue.symbole && tab[1][i] == joueur_qui_joue.symbole && tab[2][i] == joueur_qui_joue.symbole) {
      return 1;
    }
  }

  // Vérification de la diagonale haut-gauche vers bas-droite
  if (tab[0][0] == joueur_qui_joue.symbole && tab[1][1] == joueur_qui_joue.symbole && tab[2][2] == joueur_qui_joue.symbole) {
    return 1;
  }

  // Vérification de la diagonale bas-gauche vers haut-droite
  if (tab[2][0] == joueur_qui_joue.symbole && tab[1][1] == joueur_qui_joue.symbole && tab[0][2] == joueur_qui_joue.symbole) {
    return 1;
  }
  return 0;
}

//Fonction principale
int main() {

  //Variables
  char morpion[TAILLE][TAILLE];
  int c;
  int nbCoups = 0;

  j joueur1;
  j joueur2;

  //Initialisation des joueurs
  printf("----------JOUEUR 1----------\n");
  printf("Veuillez entrer votre prénom : ");
  scanf("%s", joueur1.prenom);
  printf("Veuillez entrer votre âge : ");
  scanf("%d", &joueur1.age);
  joueur1.symbole = 'X';
  joueur1.numero = 1;
  
  printf("\n----------JOUEUR 2----------\n");
  printf("Veuillez entrer votre prénom : ");
  scanf("%s", joueur2.prenom);
  printf("Veuillez entrer votre âge : ");
  scanf("%d", &joueur2.age);
  joueur2.symbole = '0';
  joueur2.numero = 2;
  
  //Initialisation de la grille
  initGrille(morpion);

  j joueur = joueur1;
  
  //boucle de jeu
  for (int i = 0; i<TAILLE*TAILLE; i++){

    //affiche la grille joue le coup donné par le joueur
    affGrille(morpion, joueur1,joueur2);
    do {
      printf("%s, veuillez entrer la ligne (0-2) : ", joueur.prenom);
      scanf("%d", &i);
      printf("Veuillez entrer la colonne (0-2) : ");
      scanf("%d", &c);
    } while ((i > 2) || (i < 0) || (c > 2) || (c < 0) || (morpion[i][c] != 0));

    if (joue(morpion, joueur, i, c)){
      nbCoups++;
      if (gagne(morpion, joueur)){ //vérifie si un joueur a gagné
        affGrille(morpion, joueur1,joueur2);
        printf("%s a gagné !\n\n", joueur.prenom);
        break;
      }
      if (nbCoups == TAILLE*TAILLE){
        affGrille(morpion, joueur1,joueur2);
        printf("Match nul !\n\n");
        break;
      }

      // change le joueur qui joue
      joueur = tour2jeu(morpion, joueur,joueur1,joueur2);
    }
}


  return 0;
}