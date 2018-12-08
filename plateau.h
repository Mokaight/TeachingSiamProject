#include<stdlib.h>
#include<stdio.h>
#include "pion.h"

typedef struct plateau_s
{
  pion_t* plateau[5][5];
  pion_t* reserveElephant[5];
  pion_t* reserveRhino[5];
  pion_t* reserveMontagne[3];
}plateau_t;

plateau_t* initialisePlateau();
void detruirePlateau(plateau_t* t);
void afficherPlateau(plateau_t* p);
void preparerPlateauPourJeu(plateau_t* t);
void RetirerReserveElephant(plateau_t* t, int* compteurELE);
void RetirerReserveRhino(plateau_t* t, int* compteurRHI);
void AjouterReserveElephant(plateau_t* t, int* compteurELE);
void AjouterReserveRhino(plateau_t* t, int* compteurRHI);
void FinDuJeu(pion_t* pion, int* victoire);
pion_t* selectionPion(plateau_t* t);
