#include <stdio.h>
#include "liste.h"
#define TAILLE_MAX 100

void afficher(int liste[TAILLE_MAX])
{
    en_tete();
    int vcour;
    
    while(!hors_liste())
    {
        valeur_elt(&vcour);
        printf("%i ", vcour);
        suivant();
    }
}


int somme(int liste[TAILLE_MAX])
{
    en_tete();
    int vcour;
    int res = 0;

    while(!hors_liste())
    {
        valeur_elt(&vcour);
        res = res + vcour;
        suivant();
    }
    return(res);
}


void elever_carre(int liste[TAILLE_MAX])
{
    en_tete();
    int vcour, res;

    while(!hors_liste())
    {
        valeur_elt(&vcour);
        res = vcour*vcour;
        modif_elt(res);
        suivant();
    }
}


void inserer(void)
{
    int vcour, elem;

    printf("Entrer un entier : ");
    scanf("%i", &elem);

    if(liste_vide()==1)
    {
        ajout_gauche(elem);
    }else
    {
        en_queue();
        valeur_elt(&vcour);

        if(elem>=vcour) ajout_droit(elem);
        else
        {
            en_tete();
            valeur_elt(&vcour);

            while(elem>=vcour)
            {
                suivant();
                valeur_elt(&vcour);
            }
            ajout_gauche(elem);
        }
    }
}


void supprimer(int liste[TAILLE_MAX])
{
    int vcour,elem;

    printf("Entrer un entier à retirer : ");
    scanf("%i", &elem);

    en_tete();

    while(!hors_liste())
    {
        valeur_elt(&vcour);
        if(vcour==elem) oter_elt();
        suivant();
    }
}


void vider_liste_tete(int liste[TAILLE_MAX])
{
    while(!hors_liste())
    {
        en_tete();
        oter_elt();
    }
}


void vider_liste_queue(int liste[TAILLE_MAX])
{
    en_queue();
    while(!hors_liste())
    {
        oter_elt();
    }
}
