#include <stdio.h>

int main()
{
    int nb = 0;
    int i;
    int entier;
    FILE * fichier;    //Lit le fichier nombres.txt et affiche le nombre d'entiers pairs
    char nom_fich[20];

    printf("Donner le nom du fichier : ");
    scanf("%s", nom_fich);
    if(fichier==NULL) printf("Fichier inexistant")
    else{
        printf("Entrer un entier strictement positif : ");
        while (nb<=0) scanf("%d", &nb);

        for(i=0; i<nb; i++){
            entier = rand();
            fprintf(fichier, "%d ", entier);
        }

    }

    fclose(fichier);
    return 0;
}