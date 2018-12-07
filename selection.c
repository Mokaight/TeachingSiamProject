#include "plateau.h"

pion_t* selectionPion(plateau_t* t){
int X,Y;
printf("Quelle sont l'abscisse et l'ordonnée du pion que vous voulez selectionner ?\n");
do
{
    scanf("%d %d ",&X,&Y);
}while((X>5)&&(X<1)&&(Y>5)&&(Y<1));
return t->plateau[Y-1][X-1];
}
//pion_t* PionSelect = selectionPion(t);
