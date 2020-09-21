#include <stdio.h>
#define N 3
#define M 5

int valides(int x, int y)
{
    return ((x>=0 && x<N-1)&&(y>=0 && y<M-1));
}

int est_vide(int laby[N][M], int x, int y)
{
    return (valides(x, y)==1 && laby[x][y]==0); 
}

void chercher_chemin(int laby[N][M], int xa, int ya, int xd, int yd)
{
    int i, j, indice = 1;
    laby[xd][yd]=1;

    while(laby[xa][ya]==0){
        for(i=0 ; i<N; i++)
        {
            for(j=0; j<M; j++){
                if(laby[i][j]==indice)
                {
                    if(est_vide(laby, i+1, j)==1) laby[i+1][j]=indice+1;
                    if(est_vide(laby, i-1, j)==1) laby[i-1][j]=indice+1;
                    if(est_vide(laby, i, j+1)==1) laby[i][j+1]=indice+1;
                    if(est_vide(laby, i, j-1)==1) laby[i][j-1]=indice+1;
                }
            }
        }
        indice++;
    }
//complexité N*M*N*M
//          ^2For  ^While
//          O(N²*M²)

}

void marquer_chemin(int laby[N][M], int xa, int ya, int xd, int yd)
{
    int i, j;
    int indice = laby[xa][ya];

    while(laby[xd][yd]==1){
        for(i=0 ; i<N; i++)
        {
            for(j=0; j<M; j++){
                if(laby[i][j]==indice)
                {
                    if(est_vide(laby, i+1, j)==1) laby[i+1][j]=-2;
                    if(est_vide(laby, i-1, j)==1) laby[i-1][j]=-2;
                    if(est_vide(laby, i, j+1)==1) laby[i][j+1]=-2;
                    if(est_vide(laby, i, j-1)==1) laby[i][j-1]=-2;
                }
            }
        }
        indice--;
    }
}