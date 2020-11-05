#include <stdio.h>

typedef struct element
{
    int entier;
    struct element* pred;
    struct element* succ;
} t_element;

typedef struct
{
    t_element* drapeau;
    t_element* ec;
} t_liste;


void trier(t_liste* liste)
{
    t_liste inter;
    int n;

    init_liste(&inter);
    en_queue(liste);

    while(!hors_liste(&inter))
    {
        valeur_elt(liste, &n);
        inserer(&inter, n);
        oter_elt(&liste);
    }
    *liste = inter;
}
