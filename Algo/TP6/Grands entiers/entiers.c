#include <stdio.h>
#include <stdlib.h>
#include "listes.c"
#define MAX_LISTE 11
#define VRAI 1
#define FAUX 0

void vider_liste()
{
    int i;
    for (i = 1; i < MAX_LISTE; i++)
        init_liste(i);
}

void vider_liste()
{
    int i;
    for (i = 1; i < MAX_LISTE; i++)
        init_liste(i);
}

int taille(int n)
{
    en_tete(n);
    int i = 0;
    while (!hors_liste(n))
    {
        i++;
        suivant(n);
    }
    return i;
}

void saisie()
{

    int iliste, entier;
    printf("Numero de liste : ");
    scanf("%i", &iliste);
    init_liste(iliste);
    printf("Entrer un chiffre un à un : \n");
    en_tete(iliste);
    scanf("%i", &entier);

    while (entier != -1)
    {

        ajout_droit(iliste, entier);
        scanf("%i", &entier);
    }
}

void affichage()
{
    int iliste;
    printf("Numero de liste : ");
    scanf("%i", &iliste);

    printf("Entier numéro %i : ", iliste);
    en_tete(iliste);
    int vcour;
    while (!hors_liste(iliste))
    {
        valeur_elt(iliste, &vcour);
        printf("%i", vcour);
        suivant(iliste);
    }
}

void affectation(void)
{
}

void comparaison(void)
{
}

void addition(void)
{
}

int main(void)
{
    // Programme principal
    int choix; // choix de l'utilisateur
    int i;

    for (i = 1; i < MAX_LISTE; i++)
        init_liste(i);

    do
    {
        // Affichage du menu
        printf("\nMenu :\n");
        printf(" 1 - Saisir un entier\n");
        printf(" 2 - Afficher un entier\n");
        printf(" 3 - Affecter un entier\n");
        printf(" 4 - Comparer deux entiers\n");
        printf(" 5 - Additionner deux entiers\n");
        printf(" 6 - Quitter\n");
        printf("Votre choix : ");
        scanf("%i", &choix);

        // Traitement du choix de l'utilisateur
        switch (choix)
        {
        case 1:
            saisie();
            break;
        case 2:
            affichage();
            break;
        case 3:
            affectation();
            break;
        case 4:
            comparaison();
            break;
        case 5:
            addition();
            break;
        case 6:
            break;
        default:
            printf("Erreur: votre choix doit etre compris entre 1 et 6\n");
        }
    } while (choix != 6);
    printf("Au revoir !\n");
    return EXIT_SUCCESS;
}