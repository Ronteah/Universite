#include <stdio.h>

int main()
{
    int nombre = 0;
    int pair = 0;
    FILE * fichier;    //Lit le fichier nombres.txt et affiche le nombre d'entiers pairs
    char nom_fich[20];

    printf("Donner le nom du fichier : ");
    scanf("%s", nom_fich);
    if(fichier==NULL) printf("Fichier inexistant");
    else{

        fichier=fopen(nom_fich, "r");
        fscanf(fichier, "%i", &nombre);

        while (!feof(fichier)){
            if (nombre%2 == 0) pair++;
            fscanf(fichier, "%i", &nombre);
        }

        fclose(fichier);
    }
    printf("Le fichier contient %d entiers pairs", pair);

    return 0;
}