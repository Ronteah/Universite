#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>
#define N 8


int verifie (int x, int y)
{
    return ((x>=0 && x<N) && (y>=0 && y<N));
}

void compte_voisins(int automate[N][N], int voisins[N][N])
{
    int i, j;
    int n_voisins=0;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if(verifie((i-1), (j-1))==1 && automate[i-1][j-1] == 1) n_voisins++;

            if(verifie((i-1), j)==1 && automate[i-1][j] == 1) n_voisins++;
            
            if(verifie((i-1), (j+1))==1 && automate[i-1][j+1] == 1) n_voisins++;
            
            if(verifie(i, (j-1))==1 && automate[i][j-1] == 1) n_voisins++;
            
            if(verifie(i, (j+1))==1 && automate[i][j+1] == 1) n_voisins++;
            
            if(verifie(i, (j-1))==1 &&  automate[i+1][j-1] == 1) n_voisins++;
            
            if(verifie((i+1), j)==1 &&  automate[i+1][j] == 1) n_voisins++;
            
            if(verifie((i+1), (j+1))==1 && automate[i+1][j+1] == 1) n_voisins++;


            voisins[i][j] = n_voisins;
            n_voisins = 0;
        }
    }
}

void cellules(int automate[N][N], int voisins[N][N])
{
    int i, j;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if((voisins[i][j] == 3 || voisins[i][j] == 2) && automate[i][j] == 1)
                automate[i][j] = 1;
            else if(voisins[i][j] == 3 && automate[i][j] == 0)
                automate[i][j] = 1;
            else if(voisins[i][j] == 4)
                automate[i][j] = 0;
            else automate[i][j] = 0;
        }
    }
}

void afficher_cellules(int automate[N][N])
{
    int i, j;
    char vivant = 'o';
    char mort = '-';

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if(automate[i][j] == 1)
                printf("%c ", vivant);
            if(automate[i][j] == 0)
                printf("%c ", mort);
        }
        printf("\n");
    }
}

int main() 
{
    char nom_fich[20];
    int generations;
    int i, j;
    FILE * fichier;
    int erreur = 1;

    //Demande le fichier d'initialisation.
    while (erreur == 1)
    {
        printf("Entrer le nom du fichier d'initialisation : \n");
        scanf("%s", nom_fich);

        //Vérifie si le fichier existe.
        fichier=fopen(nom_fich, "r");
        if(fichier==NULL) 
            printf("Fichier inexistant, recommencez.\n");
        else erreur = 0;
    }
    fclose(fichier);


    printf("Entrer le nombre de generations a affichier : ");
    scanf("%i", &generations);


    //Initialisation des matrices.
    int automate[N][N];
    int voisins[N][N];

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            automate[i][j] = 0;
            voisins[i][j] = 0;
        }
    }


    //Place les cellules vivantes depuis le fichier dans la matrice automate.
    fichier=fopen(nom_fich, "r");

    int x = 0, y = 0;
    
    while(!feof(fichier))
    {
        //Récupère les coordonées des cellules vivantes.
        fscanf(fichier, "%i ", &x);
        fscanf(fichier, "%i ", &y);

        automate[x][y] = 1;
    }
    fclose(fichier);

    int n;

    //Répète jusqu'au nombre de générations demandé.
    for (n = 0; n < generations; n++)
    {
        compte_voisins(automate, voisins);

        afficher_cellules(automate);
        cellules(automate, voisins);

        Sleep(2000);
        system("cls");
    }

    return 0;
}