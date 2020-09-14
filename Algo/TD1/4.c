#include <stdio.h>

int main()
{
    int ptLeia=0;
    int ptLuke=0;
    int score=0;
    int eptLeia=0;
    int eptLuke=0;
    FILE * fichier;

    printf("Donner les points marqués par Leia : ");
    scanf("%d", &ptLeia);
    printf("Donner les points marqués par Luke : ");
    scanf("%d", &ptLuke);

    fichier = fopen("scores.txt", "a");
    if(fichier==NULL){
        fichier = fopen("scores.txt", "w");
        fprintf(fichier, "%d ", ptLeia);
        fprintf(fichier, "%d", ptLuke);
        fclose(fichier);

        printf("Les nouveaux scores sont : %d pour Leia, %d pour Luke.", ptLeia, ptLuke);
    }else{
        fscanf(fichier, "%i%i", &eptLeia, &eptLuke);
        printf("Les anciens scores sont : %d pour Leia, %d pour Luke?", eptLeia, eptLuke);
        fclose(fichier);

        fichier = fopen("scores.txt", "w");
        ptLeia+=eptLeia;
        ptLuke+=eptLuke;
        fprintf(fichier, "%d ", ptLeia);
        fprintf(fichier, "%d", ptLuke);
        fclose(fichier);

        printf("Les nouveaux scores sont : %d pour Leia, %d pour Luke.", ptLeia, ptLuke);
    }

    printf("Le fichier des scores est mis à jour.");
    return 0;
}