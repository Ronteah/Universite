#include <stdio.h>

void affecter(int e1, int e2, int entier)
{
    vider_liste(e1);
    en_tete(e2); 
    while(!hors_liste(e2)) 
    {
        valeur_elt(e2,&entier); 
        ajout_droit (e1, entier); 
        suivant(e2);
    }
}
