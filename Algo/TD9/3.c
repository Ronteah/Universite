#include <stdio.h>

typedef union
{
    int entier;
    char caractere;
} t_union;

typedef struct element
{
    t_union valeur;
    struct element* pred;
    struct element* succ;
} t_element;

typedef struct
{
    t_element* drapeau;
    t_element* ec;
} t_liste;


int main() 
{
    t_liste nombre;
    t_union vcour;

    init_liste(&nombre);
    vcour.entier(5);
    ajout_droit(&nombre,vcour);

    vcour.caractere='F';
    ajout_droit(&nombre,vcour);

    return 0;
}