#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int N = 0, i;
    char car;
    printf("Entrer la durée de l'animation (en sec) : );
    scanf("%d, &N);
    N = N/2;

    FILE * fichier;

    for (i=0; i<N, i++){
        fichier = fopen("lapin1.txt", "r");
        while (!feof(fichier)){
            fscanf(fichier, "%c", &car);
            if (car == '\n') printf("\n");
            else printf("%c", car);
        }

        sleep(1);
        system("clear");
        fclose(fichier);

        fichier = fopen("lapin2.txt", "r");
        while (!feof(fichier)){
            fscanf(fichier, "%c", &car);
            if (car == '\n') printf("\n");
            else printf("%c", car);
        }

        sleep(1);
        system("clear");
        fclose(fichier);
    }
    return 0;
}
