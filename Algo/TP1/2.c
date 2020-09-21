#include <stdio.h>

int main()
{
    FILE * fichier;
    FILE * f1;
    FILE * f2;
    int n;
    int saveinf = 0;
    int savesup = 0;
    fichier = fopen("releves.txt", "r");
    f1 = fopen("positif.txt", "w");
    f2 = fopen("negatif.txt", "w");

    while (!feof(fichier))
    {
        fscanf(fichier, "%i ", &n);
        if (n >= 0){
            if (n > savesup) savesup=n;
            fprintf(f1, "%i ", n);
        }else{
            if (n < saveinf) saveinf=n;
            fprintf(f2, "%i ", n);
        }
    }
    fclose(fichier);
    fclose(f1);
    fclose(f2);

    f1 = fopen("positif.txt", "a");
    f2 = fopen("negatif.txt", "a");

    fprintf(f1, "%i ", savesup);
    fprintf(f2, "%i ", saveinf);

    fclose(f1);
    fclose(f2);

    return 0;
}