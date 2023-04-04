#include <stdio.h>
#include <stdlib.h>

struct joueur { /*OK*/
  char prenom [50];
  int age;
  char symbole;
  int numero;
};

void affGrille(int tab[3][3]) /*OK*/
{
  for (int i=0 ; i<3 ; i++)
  {
    for (int j=0 ; j<3 ; j++)
    {
      switch (tab[i][j])
      {
      case 1:
        tab[i][j]='O';
        break;
      case 2:
        tab[i][j]='X';
        break;
      default:
        tab[i][j]=' ';
        break;
      }
    }
    int j=0;
    int n = 0;
    printf("%d | ", n);
    while (j<3)
    {
      printf("%c | ", tab[i][j]);
      j=j+1;
    };
    n=n+1;
    printf("\n");
    printf("-------------");
    printf("\n");
  }
  printf("    0   1   2");
}

void joue(int tab[3][3], struct joueur joueur_qui_joue)
{
  int i;
  int j;
  struct joueur put;

  if (tab[i][j]==' ')
  {
    tab[i][j] = put.symbole;
  }
  else
  {
    printf("Choisir une autre case");
  }
}


void tour2jeu(int tab[3][3], struct joueur joueur_à_jouer)
{
  int i;
  int j;

  switch (joueur_à_jouer.numero)
  {
  case 1:
    tab[i][j] = 'X';
    joueur_à_jouer.numero = 2;
    break;
  case 2:
    tab[i][j] = '0';
    joueur_à_jouer.numero = 1;
    break;
  default:
    break;
  }
}

void aGagnéDg(int tab[3][3])
{
  
}

// int main(int argc, char** argv)
// {
//   return 0;
// }

// int main (int argc, char** argv)
// {
//   int attribuer;
//   struct joueur res;

//   switch (attribuer)
//   {
//   case 0:
//     res.symbole = " ";
//     break;
//   case 1:
//     res.symbole = "X";
//     break;
//   case 2:
//     res.symbole = "O";
//   default:
//     break;
//   }

//   return 0;
// }






//Remake:
#include <stdio.h>
#include <stdlib.h>

struct joueurs { /*OK*/
  char prenom [50];
  int age;
  char symbole;
  int numero;
};

void initiaGrille(char tab[3][3]){
  for (int i=0 ; i<3 ; i++){
    for (int j=0 ; j<3 ; j++){
      tab[i][j]=' ';
    }
  }
}

void affiGrille(char tab[3][3]){

  int j=0;
  int i=0;
  for (int n = 0; n < 3; n++) {
    printf("%d | ", n);
    j=0;
    while (j<3){
      printf("%d | ", tab[i][j]);
      j=j+1;
    }
    printf("\n");
    printf("  -------------");
    printf("\n");
  }
  printf("    0   1   2 \n");
}

//
// void joue(int tab[3][3], struct joueur joueur_qui_joue)
// {
//   int i;
//   int j;
//   struct joueur put;
//
//   if (tab[i][j]==' ')
//   {
//     tab[i][j] = put.symbole;
//   }
//   else
//   {
//     printf("Choisir une autre case");
//   }
// }
//
//
// void tour2jeu(int tab[3][3], struct joueur joueur_à_jouer)
// {
//   int i;
//   int j;
//
//   switch (joueur_à_jouer.numero)
//   {
//   case 1:
//     tab[i][j] = 'X';
//     joueur_à_jouer.numero = 2;
//     break;
//   case 2:
//     tab[i][j] = '0';
//     joueur_à_jouer.numero = 1;
//     break;
//   default:
//     break;
//   }
// }
//
// void aGagnéDg(int tab[3][3])
// {
//
// }

int main(int argc, char** argv)
{
  char morpion[3][3];

  initiaGrille(morpion);
  affiGrille(morpion);
  return 0;
}

// int main (int argc, char** argv)
// {
//   int attribuer;
//   struct joueur res;

//   switch (attribuer)
//   {
//   case 0:
//     res.symbole = " ";
//     break;
//   case 1:
//     res.symbole = "X";
//     break;
//   case 2:
//     res.symbole = "O";
//   default:
//     break;
//   }

//   return 0;
// }
