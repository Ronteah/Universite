#include <stdio.h>
#include <stdlib.h>
#include "matrice.h"

int main()
{
    double * A;
    double * B;
 /*   double *C; */
    double * resultat;

    A = creerMatrice(3);

    *(A+0) = 1; *(A+1) = 2; *(A+2) = 3;
    *(A+3) = 4; *(A+4) = 5; *(A+5) = 6;
    *(A+6) = 7; *(A+7) = 8; *(A+8) = 9;

    B = creerMatrice(3);

    *(B+0) = -1; *(B+1) = -2; *(B+2) = 0;
    *(B+3) = 4; *(B+4) = 5; *(B+5) = 6;
    *(B+6) = 3; *(B+7) = 2; *(B+8) = 1;

    printf("Matrice A: \r\n");
    afficherMatrice(3, A);
    printf("Matrice B: \r\n");
    afficherMatrice(3, B);

    detruireMatrice(A);
    detruireMatrice(B);

    return 0;
}
