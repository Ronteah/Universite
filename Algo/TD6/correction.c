#include <stdio.h>

void ajout_tete (int v)
{
    t_element* nouv;

    nouv = malloc (sizeof(t_element));
    nouv -> val = v;
    nouv->succ = ;
    nouv -> pred = NULL;
    if(dequ_vide())
        queue = nouv;
    else tete->pred = nouv;

    tete=nouv;
}



int vcour,res=0;
initpile;
empiler(n);
while(!pilevide())
{
    depiler (&vcour);
    if(vcour<2)
        res = res+vcour;
    else
    {
        empiler (vcour-1);
        empiler (vcour-2);
    }
}
return res;
