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

void convertir(int entier)
{
    int re;
    int a;

    while (entier!=0)
    {
        re = entier%2;
        empiler(re);
        entier = entier/2;
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

    printf("Entrer un entier positif ou nul : ");
    scanf("%i", &entier);

    convertir(entier);
    

    return 0;
}