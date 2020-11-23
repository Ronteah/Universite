#include <stdio.h>
#include <stdlib.h>

double *creerMatrice(int n)
{
    double *A = malloc(n * n * sizeof(*A));

    if (A == NULL)
    {
        printf("Erreur d'allocation");
        exit(EXIT_FAILURE);
    }

    return A;
}

void detruireMatrice(double *A)
{
    free(A);
}

void afficherMatrice(int n, double *A)
{
    int i, j, k;

    for (i = 0; i < n; i++)
    {
        for (k = 0; k < n; k++)
        {
            printf("--");
        }
        printf("-\n");

        for (j = 0; j < n; j++)
        {
            printf("|%.2f", A[i * n + j]);
        }
        printf("|\n");
    }
    printf("\n");
}

double *somme2Matrices(int n, double *A, double *B)
{
    double *R = creerMatrice(n);
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            R[n * i + j] = A[n * i + j] + B[n * i + j];
        }
    }
    return R;
}

double *produitReelMatrice(int n, double r, double *A)
{
    double *R = creerMatrice(n);
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            R[n * i + j] = r * A[n * i + j];
        }
    }
    return R;
}

double *produit2Matrices(int n, double *A, double *B)
{
    double *R = creerMatrice(n);
    int i, j, k;
    double r;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            for (k = 0; k < n; k++)
            {
                r += A[i * n + k] * B[k * n + j];
            }
            R[n * i + j] = r;
        }
    }
    return R;
}

double *copieMatrice(int n, double *A)
{
    double *R = creerMatrice(n);
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            R[n * i + j] = A[n * i + j];
        }
    }
    return R;
}

double *transposeeMatrice(int n, double *A)
{
    double *R = creerMatrice(n);
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            R[n * i + j] = A[n * j + i];
        }
    }
    return R;
}

double *matriceSansLC(int n, double *A, int L, int C)
{
    double *R = creerMatrice(n - 1);
    int i, j, k = 0;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (j != C && i != L)
            {
                R[k] = A[n * i + j];
                k++;
            }
        }
    }
    return R;
}

double determinant(int taille, double *A)
{
    if (taille == 2)
    {
        return A[0] * A[3] - A[1] * A[2];
    }
    int i;
    double r;

    for (i = 0; i < taille; i++)
    {
        double *M = matriceSansLC(taille, A, 0, i);
        if (i % 2)
            r -= A[i] * determinant(taille - 1, M);
        else
            r += A[i] * determinant(taille - 1, M);

        detruireMatrice(M);
    }
    return r;
}

double *comatrice(int n, double *A)
{
    double *R = creerMatrice(n);
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; n++)
        {
            double *M = matriceSansLC(n, A, i, j);
            if (i % 2)
            {
                if (j % 2)
                {
                    R[n * i + j] = determinant(n - 1, M);
                }
                else
                {
                    R[n * i + j] = -(determinant(n - 1, M));
                }
            }
            else
            {
                if (j % 2)
                {
                    R[n * i + j] = (determinant(n - 1, M));
                }
                else
                {
                    R[n * i + j] = determinant(n - 1, M);
                }
            }
            detruireMatrice(M);
        }
    }
    return R;
}

double *inverserMatrice(int n, double *A)
{
    double *R = creerMatrice(n);
    double d = determinant(n, A);
    d = 1 / d;

    double *C = comatrice(n, A);
    C = transposeeMatrice(n, C);

    R = produitReelMatrices(n, d, C);

    detruireMatrice(C);
    return R;
}