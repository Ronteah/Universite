#include <stdio.h>

int main()
{
    int nombre = 0;
    int pair = 0;
    FILE * fic1;    //Lit le fichier nombres.txt et affiche le nombre d'entiers pairs
    fic1=fopen("nombres.txt", "r");
    fscanf(fic1, "%i", &nombre);

    while (!feof(fic1)){
        if (nombre%2 == 0) pair++;
        fscanf(fic1, "%i", &nombre);
    }

    fclose(fic1);
    printf("Le fichier contient %d entiers pairs", pair);

    return 0;
}