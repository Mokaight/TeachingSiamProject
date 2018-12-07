#include <stdlib.h>
#include <stdio.h>
//Une règle a se rappeler = nom du fichier.c = nom du fichier.h
#include "plateau.h"

int main(){
    pion_t* pionTEST=initialiserPionRhino();
  plateau_t* test=initialisePlateau();
  test->plateau[0][0]=pionTEST;
  preparerPlateauPourJeu(test);
  Deplacement(pionTEST,test,2,1);
  afficherPlateau(test);
  return EXIT_SUCCESS;
}
//

