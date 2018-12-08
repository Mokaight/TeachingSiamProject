#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "plateau.h"

pion_t* initialiserVide(){
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

void detruirePion(pion_t* tata){
  free(tata);
}

void rotationPion(pion_t* p){
    char rotation;
    printf("Dans quelle direction voulez vous vous orienter :?\n");
    printf("                        h   \n");
    printf("                     g<-|->d   \n");
    printf("                        b   \n");

    do{
        scanf("%c",&rotation);
    }while((rotation!='h')&&(rotation!='b')&&(rotation!='g')&&(rotation!='d'));
    p->orientation = rotation;
}

void afficherPosition(pion_t* tata){
  printf("Le pion est en (%d,%d)\n Il est orient� vers  : %c \n Sur le plateau  = %d",tata->position.posX,tata->position.posY,tata->orientation,tata->surPlateau);
}


