#include <stdio.h>
#define N 3
#define M 5
#define FAUX 0
#define VRAI 1
#define tmax 90
int file[tmax];
int tete, queue, nb_valeurs;

void initfile(void)
{
    nb_valeurs = 0;
    tete=0;
    queue=tmax-1;
}

void ajouter(int* v)
{
    if(nb_valeurs<tmax)
    {
        if(queue == tmax-1) queue=0;
        else queue++;
        file[queue] = v;
        nb_valeurs++;
    }
}

void retirer(int* v)
{
    if(nb_valeurs>0)
    {
        *v = file[tete];
        nb_valeurs--;
        if(tete == tmax-1) tete=0;
        else tete++;
    }
}

int filevide(void)
{
    return(nb_valeurs==0);
}

int filepleine(void)
{
    return(nb_valeurs==tmax);
}


int valides(int x, int y)
{
    return ((x>=0 && x<N-1)&&(y>=0 && y<M-1));
}

int est_vide(int laby[N][M], int x, int y)
{
    return (valides(x, y)==1 && laby[x][y]==0); 
}

int chercher_chemin(int lab[N][M], int xd, int yd, int xa, int ya)
{
    int x, y, i;
    int trouve = FAUX;
    initfile();
    lab[xd][yd]=1;
    ajouter(xd);
    ajouter(yd);
    
    while (!filevide()&&!trouve)
    //tant qu'il reste des case à traiter et qu'on n'a pas trouvé le chemin
    {
        retirer(&x);
        retirer(&y);
        if(x==xa && y==ya) trouve=VRAI;
        else{
            i=lab[x][y];
            if(est_vide(lab, x-1, y))
            {
                lab[x-1][y]= i+1;
                ajouter(x-1);
                ajouter(y);
            }
            
            if(est_vide(lab, x+1, y))
            {
                lab[x+1][y]= i+1;
                ajouter(x+1);
                ajouter(y);
            }

            if(est_vide(lab, x, y+1)==1) ajouter(x); ajouter(y+1);
            if(est_vide(lab, x, y-1)==1) ajouter(x); ajouter(y-1);
        }
    }
}

int main() 
{


    return 0;
}