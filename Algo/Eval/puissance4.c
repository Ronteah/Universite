#include <stdio.h>                  // LOUIS GEORGET
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>
#define N 6
#define M 7
#define ROUGE 1
#define JAUNE 2

int colonne_valide(int n)
{
    n--;
    return (n>=0 && n<M);
}

void place_pion(int colonne, int jeu[N][M], int couleur)
{
    int i;
    colonne--;

    for (i = N-1; i >= 0; i--)
    {
        if (jeu[i][colonne] == 0)       //Vérifie si la case de la colonne est vide
        {
            jeu[i][colonne] = couleur;  //Place le pion de la couleur du joueur
            return;
        }   
    }
}

int verifie_jeu(int jeu[N][M])          //Vérifie si un joueur a gagné
{
    int i, j;
    int save1 = 0;
    int save2 = 0;
    int save3 = 0;
    int save4 = 0;

    for (i = 0; i < N; i++)             //Regarde horizontalement
    {
        for (j = 0; j < M; j++)
        {
            if (jeu[i][j] == jeu[i][j-1] && jeu[i][j]!=0)
            {
                save1++;
                if(save1 >= 3) return 1;
            }else save1=0;            
        }
    }

    for (j = 0; j < M; j++)             //Regarde verticalement
    {
        for (i = 0; i < N; i++)
        {
            if (jeu[i][j] == jeu[i-1][j] && jeu[i][j]!=0)
            {
                save2++;
                if(save2 >= 3) return 1;
            }else save2 = 0;
        }
    }

/*    for (j = 0; j < M; j++)             //Regarde de haut gauche à bas droite
    {  
        for (i = 0; i < N; i++)
        {
            if (jeu[i][j] == jeu[i+1][j+1] && jeu[i][j] == jeu[i-3][j-3] && jeu[i][j] == jeu[i-2][j-2] && jeu[i][j] == jeu[i-1][j-1] && jeu[i][j]!=0)
            {
                save3++;
                if(save3 >= 3) return 1;
            }else save3 = 0;
        }
    }
*/


    return 0;
}

void sauvegarder(int jeu[N][M], int n_tours)
{
    FILE * fichier;
    fichier = fopen("partie.txt", "w");

    int i, j;
    fprintf(fichier, "%i ", n_tours);

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            fprintf(fichier, "%i ", jeu[i][j]);
        }
    }

    fclose(fichier);
}

void restaurer(int jeu[N][M], int n_tours)
{
    FILE * fichier;
    fichier = fopen("partie.txt", "r");

    int i, j, entier; 
    fscanf(fichier, "%i ", &entier);
    n_tours = entier;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            fscanf(fichier, "%i ", &entier);
            jeu[i][j] = entier;
        }
    }

    fclose(fichier);
}

int main() 
{
    int jeu[N][M];
    int i, j;

    for (i = 0; i < N; i++)         //Initialisation de la table de jeu
    {
        for (j = 0; j < M; j++)
        {
            jeu[i][j] = 0;
        }
    }
    
    int pion =-1;
    int n_tours;

    int choix;
    printf("PUISSANCE 4\n");
    printf("1 : Charger partie\n");
    printf("2 : Nouvelle partie\n");

    printf("Que souhaitez-vous faire : ");
    scanf("%i", &choix);

    if(choix == 1) 
    {
        restaurer(jeu, n_tours);
        system("cls");                  //Efface les éléments affichés
    }
    
    else

    system("cls");                  //Efface les éléments affichés
    for (i = 0; i < N; i++)         //Affiche la table de jeu
    {
        for (j = 0; j < M; j++)
        {
            printf("%i ",jeu[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int fini = 0;
    
    for(n_tours=0 ; fini==0 ; n_tours++)
    {
        if (n_tours%2 == 0)               //Tour des rouges
        {
            printf("Au tour des rouges. (Entrer 11 pour sauvegarder)\n");

            while (colonne_valide(pion) == 0)   //Vérifie que le pion placé soit dans la table de jeu
            {
                printf("Placer un pion : ");
                scanf("%i", &pion);
                if (pion == 11)
                {
                    sauvegarder(jeu, n_tours);
                    printf("Jeu sauvegarde, la partie reprend :\n");
                }
                
                if(colonne_valide(pion)==0) printf("Pion invalide, recommencer.\n");
            }

        place_pion(pion, jeu, ROUGE);
        system("cls");                  //Efface les éléments affichés

        printf("\n");
        for (i = 0; i < N; i++)         //Affiche la table de jeu
        {
            for (j = 0; j < M; j++)
            {
                printf("%i ",jeu[i][j]);
            }
            printf("\n");
        }
        printf("\n");   

        if (verifie_jeu(jeu)==1)
        {
            printf("Les rouges gagnent !");
            fini = 1;
        }
             

        printf("\n");
        pion =-1;
        }
        
        
        else                       //Tour des jaunes
        {
            printf("Au tour des jaunes. (Entrer 11 pour sauvegarder)\n");
            
            while (colonne_valide(pion) == 0)   //Vérifie que le pion placé soit dans la table de jeu
            {
                printf("Placer un pion : ");
                scanf("%i", &pion);
                if (pion == 11)
                {
                    sauvegarder(jeu, n_tours);
                    printf("Jeu sauvegarde, la partie reprend :\n");
                }

                if(colonne_valide(pion)==0) printf("Pion invalide, recommencer.\n");
            }


        place_pion(pion, jeu, JAUNE);
        system("cls");                  //Efface les éléments affichés

        printf("\n");
        for (i = 0; i < N; i++)         //Affiche la table de jeu
        {
            for (j = 0; j < M; j++)
            {
                printf("%i ",jeu[i][j]);
            }
            printf("\n");
        }
        printf("\n");        

        if (verifie_jeu(jeu)==1)
        {
            printf("Les jaunes gagnent !");
            fini = 1;
        }

        if (n_tours >= 41)
        {
            printf("Match nul !");
            fini = 1;
        }

        sauvegarder(jeu, n_tours);               //Sauvegarde la partie automatiquement tous les deux tours

        printf("\n");
        pion =-1;
        }
        
    }

    return 0;
}