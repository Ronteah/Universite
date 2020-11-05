#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define tmax 10
char pile[tmax];
int sommet;

void initpile(void)
{
    sommet = -1;
}

void empiler(char c)
{
    if(sommet < tmax-1)
    {
        sommet ++;
        pile[sommet]=c;
    }
}

void depiler(char* c)
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

void traiter_vcour(char c)
{
    int a,b;
    int res;
    if (c>='0' && c<='9') empiler(convertir(c));
    else 
        depiler(&a);
        depiler(&b);
    
        switch (c)
        {
        case '+':
            res = a+b;
            break;
        
        case '-':
            res = b-a;
            break;

        case '*':
            res = a*b;
            break;

        case '/':
            res = b/a;
            break;

        default: return 1;
            break;
        }

    empiler(res);
}


int main() 
{
    char exp[tmax];
    int valeur;
    printf("Entrer une expression postfixe : ");
    scanf("%s", exp);

    traiter_vcour(exp);

    return 0;
}