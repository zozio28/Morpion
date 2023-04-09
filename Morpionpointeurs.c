#include <stdio.h>
#include <stdlib.h>

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
    for (int i=0; i<3; i++){
        printf("+---+---+---+ \n");
        printf("|");
        for (int j=0; j<3; j++){
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

void joue(int** maGrille, int numeroJoueur,int i,int j){
    maGrille[i][j]=numeroJoueur;
}

void tour2jeu(int** maGrille,int* joueur, int i, int j){
    do {
        printf("Veuillez entrez la ligne suivie de la ligne : ");
        scanf("%d", &i);
        printf("Veuillez entrer la colonne : ");
        scanf("%d", &j);
    } while (((i > 2) || (i < 0)) || ((j > 2) || (j < 0)) || (maGrille[i][j]!=0));

    switch(*joueur){
        case 1 :
            *joueur = 2;
            break;
        case 2 :
            *joueur = 1;
            break;
    }
    
}

int main(){
    int** tab = NULL;
    int lignes = 3;
    int colonnes = 3;
    int joueur = 1;

    tab = allouerTableau(lignes,colonnes);
    initTableau(tab,lignes,colonnes);
    afficherGrille(tab);
    for (int i = 0; i<lignes*colonnes; i++){
        joue(tab,joueur,lignes,colonnes);
        afficherGrille(tab);
        tour2jeu(tab,joueur,lignes,colonnes);
    }

    free(tab);
    tab = NULL;

    return 0;
}