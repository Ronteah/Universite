#include <stdio.h>
#define tmax 10
int pile[tmax];
int sommet;

void initpile(void)
{
    sommet = -1;
}

void empiler(int c)
{
    if(sommet < tmax-1)
    {
        sommet ++;
        pile[sommet]=c;
    }
}

void depiler(int* c)
{
    if(sommet>-1)
    {
        *c = pile[sommet];
        sommet--;
    }
}

int pilevide(void)
{
    return(sommet==-1);
}

void convertir(int entier, int exp)
{
    int re;
    int a;

    while (entier!=0)
    {
        re = entier%exp;
        empiler(re);
        entier = entier/exp;
    }

    while (!pilevide())
    {
        depiler(&a);
        printf("%i", a);
    }
}


int main() 
{
    int entier;
    int exp;

    printf("Entrer un entier positif ou nul : ");
    scanf("%i", &entier);
    printf("Entrer un entier : ");
    scanf("%i", &exp);

    convertir(entier, exp);
    

    return 0;
}