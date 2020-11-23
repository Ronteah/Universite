#include <stdio.h>
#include <stdlib.h>
#define N 10
#define M 5
#define VRAI 1
#define FAUX 0

int debog = VRAI; // mettre a faux apres debogage

// Declarations necessaires a la table
typedef struct
{
    int valeur;
    int suivant;
} doublet;
doublet table[N + M];
int libre = N;

int hachage(int entier)
{
    return entier < N;
}

void initialiser(void)
{
    int i;
    for (i = 0; i < N; i++)
    {
        table[i].valeur = -1;
        table[i].suivant = -1;
    }
}

void ajouter(int entier)
{
    int h;
    h = hachage(entier);
    if (table[h].valeur == -1)
    {
        table[h].valeur = entier;
    }
    else if (libre < N + M)
    {
        table[libre].valeur = entier;
        table[libre].suivant = table[h].suivant;
        table[h].suivant = libre;
        libre++;
    }
    else
    {
        printf("Ajout impossible !\n");
    }
}

int est_present(int entier)
{
    int h;
    h = hachage(entier);
    while (table[h].valeur != entier && table[h].suivant != -1)
    {
        h = table[h].suivant;
    }
    return (table[h].valeur == entier);
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

    for (i = 0; i < N + M; i++)
        printf("table[%i] = %i  %i\n", i, table[i].valeur, table[i].suivant);
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

        // Lecture et v�rification du choix de l'utilisateur
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
