#include <stdio.h>
#define NB_CARTES 52
#define TAILLE_MAIN 13
#include <stdlib.h>

typedef enum
{
    carreau,
    coeur,
    trefle,
    pique
} t_couleur;
typedef enum
{
    deux,
    trois,
    quatre,
    cinq,
    six,
    sept,
    huit,
    neuf,
    dix,
    valet,
    dame,
    roi,
    as
} t_hauteur;

typedef struct
{
    t_couleur couleur;
    t_hauteur hauteur;
} t_carte;

void initialiser(t_carte jeu[])
{
    int k = 0;
    int j = 0;
    int i;
    for (i = 0; i < 4; i++)
    {
        for (k = 0; k < 13; k++)
        {
            jeu[j].couleur = i;
            jeu[j].hauteur = k;
            j++;
        }
    }
}

void melanger(t_carte jeu[])
{
    int i;
    for (i = 0; i < NB_CARTES; i++)
    {
        t_carte save = jeu[i];
        int entier = rand() % 52;
        jeu[i] = jeu[entier];
        jeu[entier] = save;
    }
}

void distribuer(t_carte jeu[], t_carte j1[], t_carte j2[], t_carte j3[], t_carte j4[])
{
    int i;
    int j = 0;
    for (i = 0; i < NB_CARTES; i += 4)
    {
        j1[j] = jeu[i];
        j2[j] = jeu[i + 1];
        j3[j] = jeu[i + 2];
        j4[j] = jeu[i + 3];
        j++;
    }
}

int est_inferieur(t_carte carte1, t_carte carte2)
{
    return carte1.hauteur < carte2.hauteur;
}

void trier(t_carte main[])
{
    int fini = 0;
    int i;
    while (!fini)
    {
        fini = 1;
        for (i = 1; i < TAILLE_MAIN; i++)
        {
            if (main[i].couleur > main[i + 1].couleur)
            {
                t_carte save = main[i + 1];
                main[i + 1] = main[i];
                main[i] = save;
                fini = 0;
            }
            else if ((main[i].couleur == main[i + 1].couleur) && main[i].hauteur > main[i + 1].hauteur)
            {
                t_carte save = main[i + 1];
                main[i + 1] = main[i];
                main[i] = save;
                fini = 0;
            }
        }
    }
}

void afficher_carte(t_carte carte)
{
    switch (carte.hauteur)
    {
    case deux:
        printf("Deux de ");
        break;
    case trois:
        printf("Tois de ");
        break;
    case quatre:
        printf("Quatre de ");
        break;
    case cinq:
        printf("Cinq de ");
        break;
    case six:
        printf("Six de ");
        break;
    case sept:
        printf("Sept de ");
        break;
    case huit:
        printf("Huit de ");
        break;
    case neuf:
        printf("Neuf de ");
        break;
    case dix:
        printf("Dix de ");
        break;
    case valet:
        printf("Valet de ");
        break;
    case dame:
        printf("Dame de ");
        break;
    case roi:
        printf("Roi de ");
        break;
    case as:
        printf("As de ");
        break;
    }

    switch (carte.couleur)
    {
    case carreau:
        printf("carreau");
        break;
    case coeur:
        printf("coeur");
        break;
    case trefle:
        printf("trefle");
        break;
    case pique:
        printf("pique");
        break;
    }

    printf("\n");
}

void afficher_main(t_carte main[])
{
    int i;
    for (i = 0; i < TAILLE_MAIN; i++)
    {
        afficher_carte(main[i]);
    }
}

int main()
{
    srand(time(NULL));

    t_carte jeu[52];
    initialiser(jeu);
    melanger(jeu);
    t_carte j1[TAILLE_MAIN], j2[TAILLE_MAIN], j3[TAILLE_MAIN], j4[TAILLE_MAIN];
    distribuer(jeu, j1, j2, j3, j4);
    trier(j1);
    afficher_main(j1);

    return 0;
}