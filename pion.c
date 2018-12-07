#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "pion.h"

pion_t* initialiserPion(){
  pion_t* tata = malloc(sizeof(pion_t));
  tata->race = AUTRE;
  tata->poids = VIDE;
  return tata;
}
pion_t* initialiserPionElephant(){
  pion_t* tata = malloc(sizeof(pion_t));
  tata->race = ELEPHANT;
  tata->poids = PION;
  tata->surPlateau = false;
  tata->orientation = 'N';
  tata->position.posX = 0;
  tata->position.posY = 0;
  return tata;
}
pion_t* initialiserPionRhino(){
  pion_t* tata = malloc(sizeof(pion_t));
  tata->race = RHINO;
  tata->poids = PION;
  tata->surPlateau = false;
  tata->orientation = 'N';
  tata->position.posX = 0;
  tata->position.posY = 0;
  return tata;
}
pion_t* initialiserPionMontagne(){
  pion_t* tata = malloc(sizeof(pion_t));
  tata->race = AUTRE;
  tata->poids = MONTAGNE;
  tata->surPlateau = false;
  tata->orientation = 'N';
  tata->position.posX = 0;
  tata->position.posY = 0;
  return tata;
}
void detruirePersonnage(pion_t* tata){
  free(tata);
}
void rotationPion(pion_t* p, char rotation){
  p->orientation = rotation;
}
void afficherPosition(pion_t* tata){
  printf("Le pion est en (%d,%d)\n Il est orienté vers  : %c \n Sur le plateau  = %d"/*?*/,tata->position.posX,tata->position.posY,tata->surPlateau,tata->orientation);
}
