#include <stdio.h>
#define N 4

void afficherMatrice(double A[N][N])
{
    int i,j;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%10.3f ",A[i][j]);
        }
        printf("\n");
    }
}


void somme2Matrices(double A[N][N], double B[N][N], double resultat[N][N])
{
    int i,j;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            resultat[i][j] = A[i][j] + B[i][j];
        }
    }
}


void produitReelMatrice(double r, double A[N][N], double resultat[N][N])
{
    int i,j;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            resultat[i][j] = A[i][j] * r;
        }
    }
}


void produit2Matrices(double A[N][N], double B[N][N], double resultat[N][N])
{
    int i,j,k;
    double res=0;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            for (k = 0; k < N; k++)
            { 
                res = res + A[i][k] * B[j][k];
            }
            resultat[i][j]=res;
        }
        res=0;
    }
}


void copieMatrice(double A[N][N], double copie[N][N])
{
    int i,j;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            copie[i][j] = A[i][j];
        }
    }
}


void creerIdentite(double id[N][N])
{
    int i,j,k=0;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (i==k && j==k)
            {
                id[i][j]=1;
                k++;
            }else{
                id[i][j]=0;
            }
        }
    }
}


void permuterLignes(double A[N][N], int l1, int l2)
{
    int i;
    double save;
    l1--;
    l2--;

    for (i = 0; i < N; i++)
    {
        save = A[l2][i];
        A[l2][i] = A[l1][i];
        A[l1][i] = save;
    }
}


int estNul(double a)
{
    if (a < 0) a = a*(-1);
    return (a < 0.00001);
}


void diviserLigneMatrice(double A[N][N], int ligne, double a)
{
    int i,j;
    ligne--;

    if (estNul(a) == 0)
    {
        for (i = 0; i < N; i++)
        {
            A[ligne][i] = A[ligne][i] / a;
        }
    }
}


void inversionPivotGauss(double AOriginal[N][N], double resultat[N][N])
{
    int r=-1,i,j,k;
    double save[N][N];
    
    copieMatrice(AOriginal,save);

    for (j = 1; j < N; j++)
    {
        for (i = r+1; estNul(save[i][j])==1; i++);

        if (i>=0 && i<N)
        {
            r++;
            permuterLignes(save,i,r);
            diviserLigneMatrice(save,r,save[r][j]);
            for (i = 1; i < N; i++)
            {
                if (i != r)
                {
                    for (k = 0; k < N; k++)
                    {
                        save[i][k] = save[i][k] - save[i][j]*r;
                    }
                }
            }
        }
    }
    copieMatrice(save,resultat);
}