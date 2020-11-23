#include <stdio.h>
#include <stdlib.h>
#define N 10
#define VRAI 1
#define FAUX 0

int debog = VRAI; // mettre a faux apres debogage

// Declarations necessaires a la table
int table[N];

int hachage(int entier)
{
    return entier % N;
}

void initialiser(void)
{
    int i;
    for (i = 0; i < N; i++)
        table[i] = -1;
}

void ajouter(int entier)
{
    int h;
    h = hachage(entier);
    while (table[h] != -1)
        h = (h + 1) % N;
    printf("J'ajoute %i a l'indice %i ...\n", entier, h);
    table[h] = entier;
}

int est_present(int entier)
{
    int h;
    h = hachage(entier);
    while (table[h] != -1 && table[h] != entier)
    {
        h = (h + 1) % N;
    }

    return table[h] == entier;
}

void insertion(void)
{
    int entier;
    printf("Entrer un entier a inserer : ");
    do
    {
        scanf("%i", &entier);
    } while (entier < 0);
    if (!est_present(entier))
        ajouter(entier);
    else
        printf("Cet entier est deja present.\n");
}

void recherche(void)
{
    int entier;
    printf("Entrer un entier a rechercher : ");
    scanf("%i", &entier);
    if (est_present(entier))
        printf("%i est present dans la table\n", entier);
    else
        printf("%i est introuvable dans la table.\n", entier);
}

void afficher_table(void)
{
    int i;

    for (i = 0; i < N; i++)
        printf("table[%i] = %i\n", i, table[i]);
    printf("\n");
}

int main()
{
    int rep; // Choix de l'utilisateur [1-3]

    initialiser();

    do
    {
        printf("\n  Menu:\n");
        printf("1) Ajouter un element dans la table\n");
        printf("2) Rechercher un element dans la table\n");
        printf("3) Quitter\n\n");

        // Lecture et verification du choix de l'utilisateur
        do
        {
            printf("Votre choix [1-3] ? ");
            scanf("%d", &rep);
            if (rep < 1 || rep > 3)
                printf("Votre choix doit etre compris entre 1 et 3\n");
        } while (rep < 1 || rep > 3);

        // Traitement du choix de l'utilisateur
        switch (rep)
        {
        case 1:
            insertion();
            break;
        case 2:
            recherche();
            break;
        case 3:
        {
            printf("Au revoir!\n");
            break;
        }
        }

        if (debog)
            afficher_table();
    } while (rep != 3);

    return EXIT_SUCCESS;
}
