#include <stdio.h> //printf,scanf
#include <stdlib.h>
#define TAILLE 3 //taille du tableau

//Fonction qui permet d'allouer un tablau dynamique
int** allouerTableau(int nb_lignes,int nb_colonnes){
    int** ptab = NULL;
    ptab = malloc(nb_colonnes*sizeof(int*));
    for (int i=0; i<nb_colonnes; i++){
        ptab[i] = malloc(nb_lignes*sizeof(int))
;    }
    return ptab;
}

//Procédure qui permet d'initialiser un tableau dynamique
void initTableau(int** maGrille,int nb_lignes,int nb_colonnes){
    for (int i=0; i<nb_lignes; i++){
        for (int j=0; j<nb_colonnes; j++){
            maGrille[i][j]=0;
        }
    }
}

//Procédure qui permet d'afficher un tableau dynamique
void afficherGrille(int** maGrille){
    for (int i=0; i<TAILLE; i++){
        printf("+---+---+---+ \n");
        printf("|");
        for (int j=0; j<TAILLE; j++){
            switch (maGrille[i][j]){
                case 1:
                    printf(" X |");
                    break;
                case 2:
                    printf(" 0 |");
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
void joue(int** maGrille, int numeroJoueur,int i,int j){
    if (maGrille[i][j] == 0) {
        maGrille[i][j] = numeroJoueur;
    }
    else {
        printf("Case déjà occupée !\n");
    }
}

//Procédure qui permet à un joueur de saisir les coordonnées de son pion
void tour2jeu(int** maGrille, int* joueur, int* i, int* j) {
    //demande au joueur de jouer tant que ses coordonnées sont inexactes
    do {
        printf("Joueur %d, veuillez entrer la ligne (0-2) : ", *joueur);
        scanf("%d", i);
        printf("Veuillez entrer la colonne (0-2) : ");
        scanf("%d", j);
    } while ((*i > 2) || (*i < 0) || (*j > 2) || (*j < 0) || (maGrille[*i][*j] != 0));
    //change de joueur
    switch(*joueur){
        case 1 :
            *joueur = 2;
            break;
        case 2 :
            *joueur = 1;
            break;
    }
    
}

//Prédicat qui permet de tester si un joueur a gagné
int gagne (int** maGrille, int joueur){
    // Vérification des lignes
    for (int i = 0; i < TAILLE; i++) {
        if (maGrille[i][0] == joueur && maGrille[i][1] == joueur && maGrille[i][2] == joueur) {
            return 1;
        }
    }
    // Vérification des colonnes
    for (int i = 0; i < TAILLE; i++) {
        if (maGrille[0][i] == joueur && maGrille[1][i] == joueur && maGrille[2][i] == joueur) {
            return 1;
        }
    }
    // Vérification de la diagonale haut-gauche vers bas-droite
    if (maGrille[0][0] == joueur && maGrille[1][1] == joueur && maGrille[2][2] == joueur) {
        return 1;
    }
    // Vérification de la diagonale bas-gauche vers haut-droite
    if (maGrille[2][0] == joueur && maGrille[1][1] == joueur && maGrille[0][2] == joueur) {
        return 1;
    }
    return 0;
}

//Fonction principake
int main(){
    
    //Variables
    int** tab = NULL;
    int lignes = 3;
    int colonnes = 3;
    int joueur = 1;
    int j = 0;
    int nbCoups = 0;

    //alloue l'espace pour tab et initialise le tableau
    tab = allouerTableau(lignes,colonnes);
    initTableau(tab,lignes,colonnes);

    //boucle de jeu
    for (int i = 0; i<lignes*colonnes; i++){
        //affiche la grille joue le coup donné par le joueur
        afficherGrille(tab);
        tour2jeu(tab,&joueur,&i,&j);
        joue(tab,joueur,i,j);
        nbCoups++;// incrémente le compteur de coups
        if (gagne(tab,joueur)) { // vérifie si un joueur a gagné
            afficherGrille(tab); 
            printf("Joueur %d a gagné !\n", joueur);
            break;
        } else if (nbCoups == lignes*colonnes) { // vérifie si la grille est remplie
            afficherGrille(tab);
            printf("Match nul !\n");
            break;
        }
    }
    
    //libère l'espace alloué
    free(tab);
    tab = NULL;

    return 0;
}