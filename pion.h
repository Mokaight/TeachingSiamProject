#include<stdlib.h>
#include<stdio.h>
#include "position.h"

//Structure de données
//permet d'écrire PION+PION  pion_t toto
//Un pion qui est AUTRE + VIDE est une case vide
typedef enum poids_s{
  PION=2,MONTAGNE=1,VIDE=0
}poids_t;

typedef enum type_s{
  ELEPHANT=1,RHINO=2,AUTRE=0
}type_t;
//typedef c'est " faire un renommage" de struct personnage_s en personnage_t
typedef struct pion_s
{
    type_t race;
    poids_t poids; //poids montagne = 1 et poids d'un autre pion = 2
    int surPlateau; //true pour sur le plateau | false sur pas sur le plateau
    char orientation; // H | B | G | D | N
    position_t position;
}pion_t;

//déclaration de mes fonctions
pion_t* initialiserPion();
pion_t* initialiserPionElephant();
pion_t* initialiserPionRhino();
pion_t* initialiserPionMontagne();
void detruirePersonnage(pion_t* tata);
void afficherPosition(pion_t* tata);
void rotationPion(pion_t* p, char rotation);

//poserPion qui nétait pas sur le platea

