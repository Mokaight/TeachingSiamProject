#include<stdlib.h>
#include<stdio.h>
#include "pion.h"
//Structure de données
//typedef c'est " faire un renommage" de struct personnage_s en personnage_t
typedef struct plateau_s
{
  pion_t* plateau[5][5];
  pion_t* reserveElephant[5];
  pion_t* reserveRhino[5];
  pion_t* reserveMontagne[3];
}plateau_t;

//fonction associées au plateau
plateau_t* initialisePlateau();
void detruirePlateau(plateau_t* t);
void afficherPlateau(plateau_t* p);

void preparerPlateauPourJeu(plateau_t* t);
