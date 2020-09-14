#include <stdio.h>

int main()
{
    FILE * fichier;    //Lit le fichier nombres.txt et affiche le nombre d'entiers pairs
    char nom_fich[20];
    int total = 0;
    int entier;

    printf("Donner le nom du fichier : ");
    scanf("%s", nom_fich);
    if(fichier==NULL) printf("Fichier inexistant");
    else{
        fichier=fopen(nom_fich, "r");

        while(!feof(fichier)){
            fscanf(fichier, "%i", &entier);
            total+=entier;
        }
        fclose(fichier);

        fichier=fopen(nom_fich, "a");
        fprintf(fichier, "%d ", total);
        fclose(fichier);
    }

    return 0;
}