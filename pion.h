#include<stdlib.h>
#include<stdio.h>
#include "position.h"

typedef enum poids_s{
  PION=2,MONTAGNE=1,VIDE=0
}poids_t;

typedef enum type_s{
  ELEPHANT=1,RHINO=2,AUTRE=0
}type_t;

typedef struct pion_s
{
    type_t race;
    poids_t poids; //poids montagne = 1 et poids d'un autre pion = 2
    int surPlateau; //true pour sur le plateau | false sur pas sur le plateau
    char orientation; // H | B | G | D | N
    position_t position;
}pion_t;

pion_t* initialiserVide();
pion_t* initialiserPionElephant();
pion_t* initialiserPionRhino();
pion_t* initialiserPionMontagne();
void detruirePersonnage(pion_t* tata);
void afficherPosition(pion_t* tata);
void rotationPion(pion_t* p);



