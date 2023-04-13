#include <stdio.h>
#include <stdlib.h>
#define TAILLE 3

//Structure des joueurs
struct joueurs { /*OK*/
  char prenom [50];
  int age;
  char symbole;
  int numero;
};

//Procédure qui permet d'initialiser la grille
void initGrille(int tab[TAILLE][TAILLE]){
  for (int i=0 ; i<TAILLE ; i++){
    for (int j=0 ; j<TAILLE ; j++){
      tab[i][j]=0;
    }
  }
}

//Procédure qui permet d'afficher la grille
void affGrille(int tab[TAILLE][TAILLE], struct joueurs joueur_qui_joue){
  for (int i=0; i<TAILLE; i++){
    printf("+---+---+---+ \n");
    printf("|");
    for (int j=0; j<TAILLE; j++){
      switch (tab[i][j]){
        case 1:
          printf(" %d |",joueur_qui_joue.symbole);
          break;
        case 2:
          printf(" %d |",joueur_qui_joue.symbole);
          break;
        default:
          printf("   |");
          break;
        }
    }
    printf("\n");
  }
  printf("+---+---+---+");
  printf("\n");
}

//Procédure qui permet à un joueur de placer son pion
int joue(int tab[TAILLE][TAILLE], struct joueurs joueur_qui_joue, int i, int j){
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
int tour2jeu(int tab[TAILLE][TAILLE], struct joueurs joueur_qui_joue) {
  //change de joueur
  switch(joueur_qui_joue.numero){
    case 1 :
      joueur_qui_joue.numero = 2;
      break;
    case 2 :
      joueur_qui_joue.numero = 1;
      break;
  }
  return joueur_qui_joue.numero;    
}

//Prédicat qui permet de tester si un joueur a gagné
int gagne (int tab[TAILLE][TAILLE], struct joueurs joueur_qui_joue){
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
  int morpion[TAILLE][TAILLE];
  struct joueurs joueur1;
  struct joueurs joueur2;
  int j = 0;
  int nbCoups = 0;
  int joueur_gagnant = 0;
  
  //Initialisation de la grille
  initGrille(morpion);
  
  //Initialisation des joueurs
  printf("Joueur 1, veuillez entrer votre prénom : ");
  scanf("%s", joueur1.prenom);
  printf("Joueur 1, veuillez entrer votre âge : ");
  scanf("%d", &joueur1.age);
  joueur1.symbole = 1;
  joueur1.numero = 1;
  
  printf("Joueur 2, veuillez entrer votre prénom : ");
  scanf("%s", joueur2.prenom);
  printf("Joueur 2, veuillez entrer votre âge : ");
  scanf("%d", &joueur2.age);
  joueur2.symbole = 2;
  joueur2.numero = 2;

  struct joueurs joueur_qui_joue = joueur1;
  
  for (int i = 0; i<TAILLE*TAILLE; i++){
    //affiche la grille joue le coup donné par le joueur
    if (joueur1.numero){
      do {
        printf("Joueur %s, veuillez entrer la ligne (0-2) : ", joueur1.prenom);
        scanf("%d", &i);
        printf("Veuillez entrer la colonne (0-2) : ");
        scanf("%d", &j);
      } while ((i > 2) || (i < 0) || (j > 2) || (j < 0) || (morpion[i][j] != 0));
    } else {
      do {
        printf("Joueur %s, veuillez entrer la ligne (0-2) : ", joueur2.prenom);
        scanf("%d", &i);
        printf("Veuillez entrer la colonne (0-2) : ");
        scanf("%d", &j);
      } while ((i > 2) || (i < 0) || (j > 2) || (j < 0) || (morpion[i][j] != 0));
    }
    joue(morpion,joueur2,i,j);     
    affGrille(morpion,joueur2);
    nbCoups++;// incrémente le compteur de coups
    joueur_qui_joue.numero = tour2jeu(morpion, joueur_qui_joue);
    if (gagne(morpion, joueur_qui_joue)){
      joueur_gagnant = joueur_qui_joue.numero;
      break;
    } else {
      printf("Match nul !\n");
    }
  }

  // Annonce du gagnant ou du match nul
  if(joueur_gagnant == 1){
    printf("%s a gagné !\n", joueur1.prenom);
  } else if(joueur_gagnant == 2){
    printf("%s a gagné !\n", joueur2.prenom);
  } else {
    printf("Match nul !\n");
  }
  
  return 0;
}