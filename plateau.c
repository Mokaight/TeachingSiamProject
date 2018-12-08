#include<stdlib.h>
#include<stdio.h>
#include "plateau.h"
char ligINIT='A',lig;
plateau_t* initialisePlateau(){
  pion_t* init = initialiserVide();
  pion_t* initE = initialiserPionElephant();
  pion_t* initR = initialiserPionRhino();
  pion_t* initM = initialiserPionMontagne();

  plateau_t* p = malloc(sizeof(plateau_t));
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      p->plateau[i][j] = init;
    }
  }
  for(int j=0;j<5;j++){
      p->reserveElephant[j] = initE;
    }
  for(int j=0;j<5;j++){
      p->reserveRhino[j] = initR;
    }
  for(int j=0;j<3;j++){
      p->reserveMontagne[j] = initM;
    }
}

void afficherPlateau(plateau_t* p){
  printf("******************************\n");
  printf("*****Reserve Elephant*********\n");
    for(int j=0;j<5;j++){
      if(p->reserveElephant[j]->race == ELEPHANT){
        printf("| EE |");
      }
      else {
        printf("|    |");
      }

    }
  printf("\n");
  printf("******************************\n");
  printf("***1*****2*****3*****4*****5**\n");
  for(int i=0;i<5;i++){
        lig=ligINIT+i;
    for(int j=0;j<5;j++){
        if((p->plateau[i][j]->race == ELEPHANT) && (p->plateau[i][j]->poids == PION)&&(p->plateau[i][j]->orientation == 'H')){
          printf("| Eh |");
        }
        else if((p->plateau[i][j]->race == ELEPHANT) && (p->plateau[i][j]->poids == PION)&&(p->plateau[i][j]->orientation == 'B')){
          printf("| Eb |");
        }
        else if((p->plateau[i][j]->race == ELEPHANT) && (p->plateau[i][j]->poids == PION)&&(p->plateau[i][j]->orientation == 'D')){
          printf("| Ed |");
        }
        else if((p->plateau[i][j]->race == ELEPHANT) && (p->plateau[i][j]->poids == PION)&&(p->plateau[i][j]->orientation == 'G')){
          printf("| Eg |");
        }
        else if((p->plateau[i][j]->race == RHINO) && (p->plateau[i][j]->poids == PION)&&(p->plateau[i][j]->orientation == 'H')){
          printf("| Rh |");
        }
        else if((p->plateau[i][j]->race == RHINO) && (p->plateau[i][j]->poids == PION)&&(p->plateau[i][j]->orientation == 'H')){
          printf("| Rb |");
        }
        else if((p->plateau[i][j]->race == RHINO) && (p->plateau[i][j]->poids == PION)&&(p->plateau[i][j]->orientation == 'H')){
          printf("| Rd |");
        }
        else if((p->plateau[i][j]->race == RHINO) && (p->plateau[i][j]->poids == PION)&&(p->plateau[i][j]->orientation == 'H')){
          printf("| Rg |");
        }
        else if(p->plateau[i][j]->race == AUTRE && p->plateau[i][j]->poids == MONTAGNE){
          printf("| M  |");
        }
        else if(p->plateau[i][j]->race == AUTRE && p->plateau[i][j]->poids == VIDE){
          printf("|    |");
        }

    }
    printf(" %c\n",lig);
  }
  printf("******************************\n");
  printf("*******Reserve Rhino**********\n");
    for(int j=0;j<5;j++){
      if(p->reserveRhino[j]->race == RHINO){
        printf("| RR |");
      }
      else {
        printf("|    |");
      }

    }
  printf("\n");
  printf("******************************\n");
}

void preparerPlateauPourJeu(plateau_t* t){
pion_t* M = initialiserPionMontagne();
M->position.posX=2;
M->position.posY=1;
t->plateau[1][2] = M;
M->position.posX=2;
M->position.posY=1;
t->plateau[2][2] = M;
M->position.posX=2;
M->position.posY=3;
t->plateau[3][2] = M;

}

void detruirePlateau(plateau_t* t){
  free(t);
}

void RetirerReserveElephant(plateau_t* t, int* compteurELE){
t->reserveElephant[*compteurELE]=initialiserVide();
*compteurELE-=1;
}

void RetirerReserveRhino(plateau_t* t, int* compteurRHI){
t->reserveRhino[*compteurRHI]=initialiserVide();
*compteurRHI-=1;
}

void AjouterReserveElephant(plateau_t* t, int* compteurELE){
t->reserveElephant[*compteurELE+1]=initialiserPionElephant();
*compteurELE+=1;
}

void AjouterReserveRhino(plateau_t* t, int* compteurRHI){
t->reserveElephant[*compteurRHI+1]=initialiserPionRhino();
*compteurRHI+=1;
}

void FinDuJeu(pion_t* pion, int* victoire){
*victoire+=1;
printf("******************************\n");
if(pion->race==ELEPHANT)
    printf("Les elephants ont gagné !");
else
    printf("Les rhinocéros ont gagné !");
}


