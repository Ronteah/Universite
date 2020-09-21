#include <stdio.h>

void creerFichier()
{  
    int n = 1;
    FILE * fichier;
    char nom_fich[20];

    printf("Donner le nom du fichier : ");
    scanf("%s", nom_fich);

    fichier=fopen(nom_fich, "w");

    while (n != -1)
    {
        printf("Entrez un entier : ");
        scanf("%i",&n);

        fprintf(fichier, "%i ",n);
    }
    fclose(fichier);
}

void afficherFichier()
{
    FILE * fichier;
    int n;
    char nom_fich[20];

    printf("Donner le nom du fichier a afficher : ");
    scanf("%s", nom_fich);

    fichier=fopen(nom_fich, "r");

    if(fichier==NULL) printf("Fichier inexistant");
    else{
        while (!feof(fichier)){
            fscanf(fichier, "%i", &n);
            printf("%d ", n);
        }
    }

    fclose(fichier);
}

int main()
{
    creerFichier();
    afficherFichier();

    return 0;
}