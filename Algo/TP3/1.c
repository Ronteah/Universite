#include <stdio.h>


void format(int taille)
{
    int largeur = 841;
    int longueur = 1189;
    int i;

    for (i = 0; i < taille; i++)
    {
        if (i%2 == 0)
        {
            longueur = longueur / 2;
        }else{
            largeur = largeur / 2;
        }  
    }
    printf("Le format A%i a pour dimensions :\n", taille);
    printf("%i x %i (mm)\n", longueur, largeur);
}


int main() 
{
    int taille = 0;
    printf("Quel format de feuille souhaitez-vous : A");
    scanf("%i", &taille);

    format(taille);

    return 0;
}