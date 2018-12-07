#include "plateau.h"

int QuestionDirection(){
int var, direction;
printf("Dans quelle direction voulez vous vous deplacer ?\n");
printf("1/Haut\n2/Droite\n3/Bas\n4/Gauche\n");
do{
scanf("%d",&var);
}while((var<1)&&(var>4));
switch(var){
case 1 : direction=-1;
break;
case 2 : direction=2;
break;
case 3 : direction=1;
break;
case 4 : direction=-2;
break;
}
return direction;
}

void Deplacement(pion_t* pion, plateau_t* t, int direction, int AutorisationPoids){
int compteur=0,compteurCLONE,X,Y,r,rCLONE;
pion_t* pionCLONE;
pionCLONE=pion;
X=pion->position.posX;
Y=pion->position.posY;
if(AutorisationPoids=1)
{
if((direction<-1)||(direction>1))
{
    printf("1\n");
    r=direction/2;
    rCLONE=r;
    printf("1,5\n");
    while((pionCLONE->poids!=VIDE))
    {
        printf("1,75\n");
        pionCLONE=t->plateau[Y][X+rCLONE];
        compteur+=1;
        rCLONE+=r;
    }
    printf("compteur=%d\n",compteur);
    compteurCLONE=compteur;
    while(compteurCLONE>0)
    {
        printf("3\n");
        t->plateau[Y][X+compteur]=t->plateau[Y][X+compteur-r];
        printf("%d\n",t->plateau[Y][X+compteur]->race);
        compteurCLONE-=1;
    }
    printf("4\n");
    t->plateau[Y][X]=initialiserVide();
    printf("5\n");
}
if((direction>-2)||(direction<2))
{
    r=direction;
    rCLONE=r;
    while((pionCLONE->poids!=VIDE))
    {
        pionCLONE=t->plateau[Y+r][X];
        compteur+=1;
        rCLONE+=r;
    }
    compteurCLONE=compteur;
    while(compteur>0)
    {
        t->plateau[Y+compteur][X]=t->plateau[Y+compteur-r][X];
        compteurCLONE-=1;
    }
    t->plateau[Y][X]=initialiserVide();
}
}
else printf("Action impossible\n");



}
