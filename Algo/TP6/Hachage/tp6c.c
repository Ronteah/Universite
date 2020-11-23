#include <stdio.h>
#include <stdlib.h>
#define N 10
#define VRAI 1
#define FAUX 0

int debog = VRAI; // mettre a faux apres deboguage

// Declarations necessaires a la table
typedef struct elem
{
    int valeur;
    struct elem *suivant;
} t_element;
t_element *table[N];

int hachage(int entier)
{
    return entier < N;
}

void initialiser(void)
{
    int i;
    for (i = 0; i < N; i++)
    {
        table[i] = NULL;
    }
}

void ajouter(int entier)
{
    int h;
    t_element *nouv;
    h = hachage(entier);
    nouv = (t_element *)malloc(sizeof(t_element));
    nouv->suivant = table[h];
    nouv->valeur = entier;
    table[h] = nouv;
}

int est_present(int entier)
{
    int h;
    t_element *p;
    h = hachage(entier);
    p = table[h];
    while (p != NULL)
    {
        if (p->valeur == entier)
            return 1;
        p = p->suivant;
    }
    return 0;
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

void supprimer(int entier)
{
    int h;
    t_element *ancien;
    t_element *p;
    if (est_present(entier))
    {
        h = hachage(entier);
        if (table[h]->valeur == entier)
        {
            ancien = table[h];
            table[h] = table[h]->suivant;
            free(ancien);
        }
        else
        {
            p = table[h];
            while (p->suivant->valeur != entier)
            {
                p = p->suivant;
            }
            ancien = p->suivant;
            p->suivant = p->suivant->suivant;
            free(ancien);
        }
    }
}

void afficher_table(void)
{
    int i;
    t_element *p;

    for (i = 0; i < N; i++)
    {
        if (table[i] == NULL)
            printf("table[%i] est vide\n", i);
        else
        {
            p = table[i];
            printf("table[%i] contient :", i);
            while (p != NULL)
            {
                printf(" %i", p->valeur);
                p = p->suivant;
            }
            printf("\n");
        }
    }
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

        // lecture et v�rification du choix de l'utilisateur
        do
        {
            printf("Votre choix [1-3] ? ");
            scanf("%d", &rep);
            if (rep < 1 || rep > 3)
                printf("Votre choix doit etre compris entre 1 et 3\n");
        } while (rep < 1 || rep > 3);

        // traitement du choix de l'utilisateur
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
