// L2 info - TP 1 - Base de donnees sur des personnages
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 50

 // Définition du type catégorie
typedef enum {
    elfe, dragon, nain, titan
} t_categ;

 // Définition du type position (coordonnées ligne et colonne)
typedef struct {
    int x, y ; 
} t_posit ;

 // Définition du type personne (nom, catégorie, coordonnées, points de vie)
typedef struct {
     char nom[20] ; 
     t_categ categ ; 
     t_posit posit ; 
     int pdv
} t_pers ;


void afficher_base(t_pers* pers, int nb_pers)
{
    int i;
    for (i = 0; i < nb_pers; i++)
    {
        printf("%s \n", pers[i].nom);
        printf("%i \n", pers[i].categ);
        printf("%i %i\n", pers[i].posit.x, pers[i].posit.y);
        printf("%i \n", pers[i].pdv);
    }
}

void afficher_nombre(t_pers* pers, int nb_pers)
{
    int i;
    int j;
    int nelfe = 0;
    int ndragon = 0;
    int nnain = 0;
    int ntitan = 0;
    for (i = 0; i < nb_pers; i++)
    {
        switch (pers[i].categ)
        {
        case elfe:
            nelfe++;
            break;
        case dragon:
            ndragon++;
            break;
        case nain:
            nnain++;
            break;
        case titan:
            ntitan++;
            break;
        }
    }
    
    printf("Elfe : %d \n", nelfe);
    printf("Dragon : %d \n", ndragon);
    printf("Nain : %d \n", nnain);
    printf("Titan : %d \n", ntitan);
}

void afficher_max(t_pers* pers, int nb_pers)
{
    int i;
    int save = 0;
    int savei;
    for (i = 0; i < nb_pers; i++)
    {
        if (pers[i].pdv > save) {
            save = pers[i].pdv;
            savei = i;
        }
    }

    printf("Le personnage avec le plus d'HP : %s", pers[savei].nom);
}

void sauvegarder(t_pers* pers, int nb_pers)
{
    FILE * fichier;
    int i;
    fichier = fopen("base.txt", "w");

    for (i = 0; i < nb_pers; i++)
    {
        fprintf(fichier, "%s ", pers[i].nom); fprintf(fichier, "\n");
        fprintf(fichier, "%i ", pers[i].categ); fprintf(fichier, "\n");
        fprintf(fichier, "%i %i ", pers[i].posit.x, pers[i].posit.y); 
        fprintf(fichier, "\n");
        fprintf(fichier, "%i ", pers[i].pdv); fprintf(fichier, "\n");
    }
    fclose(fichier);
}

void charger(t_pers* pers, int* nb_pers)
{
    FILE * fichier;
    int i = 0;
    fichier = fopen("base.txt", "r");
    
    fscanf(fichier, "%s ", pers[i].nom);
    while(!feof(fichier))
    {
        
        fscanf(fichier, "%i ", &pers[i].categ);
        fscanf(fichier, "%i ", &pers[i].posit.x);
        fscanf(fichier, "%i ", &pers[i].posit.y);
        fscanf(fichier, "%i ", &pers[i].pdv);

        i++;
        fscanf(fichier, "%s ", pers[i].nom);
    }
    *nb_pers = i;

    fclose(fichier);
}

void ajouter(t_pers* pers, int* nb_pers)
{
    char nom[20];
    int i;
    int erreur = 0;
    printf("Entrer le nom du personnage a supprimer : ");
    scanf("%s", nom);

    for (i = 0; i < nb_pers; i++)
    {
        if (pers[i].nom == nom) 
        {
            printf("Erreur, ce personnage existe deja");
            erreur = 1;
        }
    }

    if(erreur = 0)
    {
        *nb_pers++;
        int categorie;
        int x, y;
        int hp;
        printf("Entrer sa categorie : ");
        printf("1 : Elfe");
        printf("2 : Dragon");
        printf("3 : Nain");
        printf("4 : Titan");
        scanf("%i", &categorie);

        printf("Entrer ses coordonées : ");
        printf("En X : ");
        scanf("%i", &x);
        printf("En Y : ");
        scanf("%i", &y);

        printf("Entrer son nombre de HP : ");
        scnaf("%i", &hp);

        *pers[*nb_pers].nom = nom;
        pers[*nb_pers].categ = categorie;
        pers[*nb_pers].posit.x = x;
        pers[*nb_pers].posit.y = y;
        pers[*nb_pers].pdv = hp;
    }
}

void supprimer(t_pers* pers, int* nb_pers)
{
    char nom[15];

    int i = nb_pers;
    int j;
    int erreur = 0;

    printf("Entrer le nom du personnage a supprimer : ");
    scanf("%s", nom);

    for (i = 0; i < nb_pers; i++)
    {
        if (pers[i].nom == nom)
        {
            printf("Erreur, ce personnage est inconnu");
            erreur = 1;
        }
    }

    if(erreur == 0)
    {
        for (j = i; j < nb_pers; j++)
        {
            *pers[j].nom = *pers[j+1].nom;
            pers[j].categ = pers[j+1].categ;
            pers[j].posit.x = pers[j+1].posit.x;
            pers[j].posit.y = pers[j+1].posit.y;
            pers[j].pdv = pers[j+1].pdv;
        }    

        *nb_pers--;
    }
}

// Programme principal
int main(void){
int choix;	// Choix de l'utilisateur

// Declaration de la base de donnees, 
// de taille maximale 50 et de taille utile nb_pers

t_pers pers[N] ;
 int nb_pers = 0 ;

do
{	// Affichage du menu
    printf("\nMenu :\n");
    printf(" 1 - Afficher tous les personnages\n");
    printf(" 2 - Afficher le nombre de personnages par categorie\n");
    printf(" 3 - Afficher le nom du personnage qui a le plus de points de vie\n");
    printf(" 4 - Sauvegarder la base\n");
    printf(" 5 - Charger la base depuis le fichier\n");
    printf(" 6 - Quitter\n");
    printf("Votre choix : ");
    scanf("%i",&choix);

    // Traitement du choix de l'utilisateur
    switch(choix)
    {	case 1 : afficher_base(pers,nb_pers); break;
        case 2:  afficher_nombre(pers,nb_pers); break;
        case 3:  afficher_max(pers,nb_pers); break;
        case 4:  sauvegarder(pers,nb_pers); break;
        case 5:  charger(pers,&nb_pers); break;
        case 6:  break;
        default: printf("Erreur: votre choix doit etre compris entre 1 et 6\n");
    }
}
while(choix!=6);
printf("Au revoir !\n");
return EXIT_SUCCESS;
}