#include <stdio.h>

int fibo1(int n) 
{
    if(n == 0 || n == 1)
    return 1;
    else return fibo1(n-1) + fibo1(n-2);
}

int partition (int* T, int i_deb, int i_fin)
{
    int temp, i, j, pivot=T[i_deb];
    i=i_deb+1;
    j=i_fin;
    while (i<j)
    {
        while (T[i]<=pivot) {i++;}
        while (T[i]>pivot) {j--;}
        if (i<j) permuter (T,i,j);
    }

    permuter(T, i_deb, j);
    return j;
}
