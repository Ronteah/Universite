#include <stdio.h>

int fibo1(int n) 
{
    if(n == 0 || n == 1)
    return 1;
    else return fibo1(n-1) + fibo1(n-2);
}

int main() {
    
    int n;
    printf("Entrer un entier : ");
    scanf("%i", &n);

    printf("%i", fibo1(n));

    return 0;
}