#include <stdio.h>

int main()
{
    int entier = 0;
    FILE * fichier;    //Lit le fichier nombres.txt et affiche le nombre d'entiers pairs
    char nom_fich[20];

    printf("Donner le nom du fichier : ");
    scanf("%s", nom_fich);
    fichier=fopen(nom_fich, "r");
    if(fichier==NULL) printf("Fichier inexistant");
    else{
        fclose(fichier);
        fichier = fopen(nom_fich, "a");
        printf("Donner un entier : ");
        scanf("%d", &entier);

        fprintf(fichier, "%d ", entier);

        fclose(fichier);
    }

    return 0;
}