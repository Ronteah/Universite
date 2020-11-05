#include <stdio.h>
#define N 10
int tab[N]


int h(int x)
{
    return (x%N);
}

void initialiser(void)
{
    int i;
    for (i = 0; i < N; i++)
    {
        tab[i] = -1;
    }
}