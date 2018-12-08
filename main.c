#include <stdlib.h>
#include <stdio.h>
#include "plateau.h"

int main(){
 int choix, direction, poidsAUTO, victoire=0, compteurELE=4, compteurRHI=4, joueur, joueurINIT;
 plateau_t* t=initialisePlateau();
 pion_t* CaseChoisie;
 preparerPlateauPourJeu(t);
 printf("Joueur 1 : choisissez votre animal :\n");
 printf("1/ Elephant    2/Rhinoceros\n");
 do{
    scanf("%d",&joueur);
 }while((joueur!=1)||(joueur!=2));
 if(joueur==1)
    printf("Le joueur 2 jouera donc les Rhinoceros\n");
 else
    printf("Le joueur 2 jouera donc les Elephants\n");
 joueurINIT=joueur;
 joueur=1;
 while(victoire==0) //Debut du tour
 {
    if(joueur==joueurINIT) //Savoir quel joueur joue
        printf("Tour du joueur 1\n");
    else
        printf("Tour du joueur 2\n");
    if(joueur==1)
    do  //SelectionCase
    {
        CaseChoisie=selectionPion(t);
    }while(((joueur=2)&&(CaseChoisie->race!=ELEPHANT)&&(CaseChoisie->poids!=MONTAGNE))||((joueur=1)&&(CaseChoisie->race!=RHINO)&&(CaseChoisie->poids!=MONTAGNE)));
    if(CaseChoisie->race!=AUTRE) //Affichage subtil des actions possibles
    {
    printf("1/Deplacer un pion\n");
    printf("2/Tourner un pion\n");
    }
    if((CaseChoisie->position.posX=0)||(CaseChoisie->position.posX=4)||(CaseChoisie->position.posY=0)||(CaseChoisie->position.posY=4))
    {
        printf("3/Sortir un pion du plateau\n");
        if(CaseChoisie->race==AUTRE)
        {
        printf("4/Entrer un pion sur le plateau\n");
        }
    }
    if(CaseChoisie->race!=AUTRE) //Blindage du choix
    {
        do{
        scanf("%d",&choix);
        }while((choix!=1)||(choix!=2));
    }
    if((CaseChoisie->position.posX=0)||(CaseChoisie->position.posX=4)||(CaseChoisie->position.posY=0)||(CaseChoisie->position.posY=4))
    {
        if(CaseChoisie->race!=AUTRE)
        {
            do{
        scanf("%d",&choix);
        }while((choix!=1)||(choix!=2)||(choix!=3));
        }
        if(CaseChoisie->race==AUTRE)
        {
            do{
        scanf("%d",&choix);
        }while(choix!=4);
        }
    }
    switch(choix) //Actions
    {
    case 1 :
    /*direction=QuestionDirection();
    poidsAUTO=AutorisationPoids();
    Deplacement(CaseChoisie, t, direction ,poidsAUTO, &compteurELE);*/
    break;

    case 2 :
    rotationPion(CaseChoisie);
    break;

    case 3 :
    SortirPion(CaseChoisie, t, joueur, &compteurELE, &compteurRHI);
    break;

    case 4 :
    EntrerPion(CaseChoisie, t, joueur, &compteurELE, &compteurRHI);
    break;
    }
    afficherPlateau(t);
    if(joueur%2==0)
        joueur-=1;
    else
        joueur+=1;
}
return 0;
}

//Deplacement(pionTEST,test,2,1);

