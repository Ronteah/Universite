#include <stdio.h>

void compter(FILE * fichier, int* nb_caract, int* nb_lignes)
{
    int i;
    nb_lignes = 0;
    char ligne;
    while(!feof(fichier)){
        fscanf(fichier, "%c", &ligne);
        if (ligne == "\n") nb_lignes++;
        nb_caract++;
    }

    printf("Il y a %d caracteres et %d lignes.", nb_caract, nb_lignes);
}