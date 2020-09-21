#include <stdio.h>
#define N 8

typedef enum {
    pion, cavalier, fou, tour, dame, roi 
}t_piece;

typedef enum{
    noir, blanc
}t_couleur;

typedef struct{
    t_couleur couleur;
    t_piece piece;
}t_case;

void init_matrice (char echec[N][N])
{
    int i, j;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            echec[i][j]='.';
        }
    }
}

void placer_cavalier(char echec[N][N], int xc, int yc)
{
    echec[xc][yc]='c';

    int x = 0;
    int y = 0;

    x=xc - 1; y=yc - 2;
    if(verif_coordonnees(x, y)==1) echec[x][y]='*';

    x=xc + 1; y=yc - 2;
    if(verif_coordonnees(x, y)==1) echec[x][y]='*';

    x=xc - 1; y=yc + 2;
    if(verif_coordonnees(x, y)==1) echec[x][y]='*';

    x=xc + 1; y=yc + 2;
    if(verif_coordonnees(x, y)==1) echec[x][y]='*';

    x=xc - 2; y=yc - 1;
    if(verif_coordonnees(x, y)==1) echec[x][y]='*';

    x=xc + 2; y=yc - 1;
    if(verif_coordonnees(x, y)==1) echec[x][y]='*';

    x=xc - 2; y=yc + 1;
    if(verif_coordonnees(x, y)==1) echec[x][y]='*';

    x=xc + 2; y=yc + 1;
    if(verif_coordonnees(x, y)==1) echec[x][y]='*';
}

verif_coordonnees(int x, int y)
{
    return ((x>=0 && x<N-1) && (y>=0 && y<N-1));
}

int main()
{
    char echec[N][N];
    init_matrice(echec);
    int erreur = 1;

    int xt = 0;
    int yt = 0;

    while(erreur==1)
    {
        printf("Donner les coordonnees d'une tour :\n");
        printf("X : ");
        scanf("%d", &xt);

        printf("Y : ");
        scanf("%d", &yt);            //Coordonnees echequier

        xt--;
        yt--;                        //Coordonnees matrice

        if(verif_coordonnees(xt, yt)==1) erreur=0;
    }
    erreur = 1;

    int i;

    for (i = 0; i < N; i++)
    {
        echec[i][xt]='*';
        echec[yt][i]='*';
    }
    echec[xt][yt]='t';

    int xc = 0;
    int yc = 0;

    while(erreur==1)
    {
        printf("Donner les coordonnees d'un cavalier :\n");
        printf("X : ");
        scanf("%d", &xc);

        printf("Y : ");
        scanf("%d", &yc);            //Coordonnees echequier

        xc--;
        yc--;                        //Coordonnees matrice

        if(verif_coordonnees(xc, yc)==1) erreur = 0;
    }
    erreur=1;


    return 0;
}