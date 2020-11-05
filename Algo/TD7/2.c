#include <stdio.h>

typedef struct element
{
    int valeur;
    struct element * pred;
    struct element * succ;
}t_element;

t_element * drapeau;
t_element * ec;


int init_liste(void)
{
    drapeau = malloc(sizeof(t_element));
    drapeau -> pred = drapeau;
    drapeau -> succ = drapeau;
    ec = drapeau;
}


int liste_vide(void)
{
    return (drapeau -> succ == drapeau);
}


int hors_liste(void)
{
    return (ec == drapeau);
}


void en_tete(void)
{
    if(!liste_vide())
        ec = drapeau -> succ;
}


void en_queue(void)
{
    if(!liste_vide())
        ec = drapeau -> pred;
}


void suivant(void)
{
    if(!hors_liste())
        ec = ec -> succ;
}


void precedent(void)
{
    if(!hors_liste())
        ec = ec -> pred;
}


void valeur_elt(int* v)
{
    if(!hors_liste())
        *v = ec -> valeur;
}


void modif_elt(int v)
{
    if(!hors_liste())
        ec -> valeur = v;
}


void oter_elt(void)
{
    if(!hors_liste())
    {
        ec->pred->succ = ec->succ;
        ec->succ->pred = ec->pred;

        t_element * save = ec;

        ec = ec->pred;
        
        free(save);
        save = NULL;   
    }
}


void ajout_droit(int v)
{
    if(liste_vide()||!hors_liste())
    {
        
    }
}