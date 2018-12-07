#include <stdlib.h>
#include <stdio.h>
//Une règle a se rappeler = nom du fichier.c = nom du fichier.h
#include "plateau.h"

int main(){
  plateau_t* test=initialisePlateau();
  preparerPlateauPourJeu(test);
  afficherPlateau(test);
  return EXIT_SUCCESS;
}
