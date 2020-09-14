#include <stdio.h>

int main()
{
    int nb = 0;
    int i;
    int entier;
    int b_inf;
    int b_sup;
    FILE * fichier;    //Lit le fichier nombres.txt et affiche le nombre d'entiers pairs
    char nom_fich[20];

    printf("Donner le nom du fichier : ");
    scanf("%s", nom_fich);
    if(fichier==NULL) printf("Fichier inexistant")
    else{
        printf("Entrer un entier strictement positif : ");
        while (nb<=0) scanf("%d", &nb);
        printf("Entrer un entier minimum : ");
        while (b_inf<0) scanf("%d", &b_inf);
        printf("Entrer un entier maximum : ");
        while (b_sup<b_inf) scanf("%d", &b_sup);

        for(i=0; i<nb; i++){
            while (entier< b_inf && entier> b_sup) entier = rand();
            fprintf(fichier, "%d ", entier);
        }

    }

    fclose(fichier);
    return 0;
}