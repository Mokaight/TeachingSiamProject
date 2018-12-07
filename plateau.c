
#include<stdlib.h>
#include<stdio.h>
#include "plateau.h"
char ligINIT='A',lig;
//fonction associées au plateau
plateau_t* initialisePlateau(){
  //cette ligne sera a modifier ( maybe)
  pion_t* init = initialiserPion();
  pion_t* initE = initialiserPionElephant();
  pion_t* initR = initialiserPionRhino();
  pion_t* initM = initialiserPionMontagne();

  plateau_t* p = malloc(sizeof(plateau_t));
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      p->plateau[i][j] = init;
    }
  }
  //les boucle remplisse les reserves Elephant et Rhino et Montagne , amodifier maybe
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
  printf("*************************\n");
  printf("*****Reserve Elephant****\n");
    for(int j=0;j<5;j++){
      if(p->reserveElephant[j]->race == ELEPHANT){
        printf("| E |");
      }
      else {
        printf("|   |");
      }

    }
  printf("\n");
  printf("*************************\n");
  printf("**1****2****3****4****5**\n");
  for(int i=0;i<5;i++){
        lig=ligINIT+i;
    for(int j=0;j<5;j++){
        if(p->plateau[i][j]->race == ELEPHANT && p->plateau[i][j]->poids == PION){
          printf("| E |");
        }
        else if(p->plateau[i][j]->race == RHINO && p->plateau[i][j]->poids == PION){
          printf("| R |");
        }
        else if(p->plateau[i][j]->race == AUTRE && p->plateau[i][j]->poids == MONTAGNE){
          printf("| M |");
        }
        else if(p->plateau[i][j]->race == AUTRE && p->plateau[i][j]->poids == VIDE){
          printf("|   |");
        }

    }
    printf(" %c\n",lig);
  }
  printf("*************************\n");
  printf("*******Reserve Rhino*****\n");
    for(int j=0;j<5;j++){
      if(p->reserveRhino[j]->race == RHINO){
        printf("| R |");
      }
      else {
        printf("|   |");
      }

    }
  printf("\n");
  printf("*************************\n");
}

void preparerPlateauPourJeu(plateau_t* t){
pion_t* M = initialiserPionMontagne(); // ?
M->position.posX=2;
M->position.posY=2;
t->plateau[2][2] = M;
M->position.posX=2;
M->position.posY=3;
t->plateau[2][3] = M;

}

void detruirePlateau(plateau_t* t){
  free(t);
}
