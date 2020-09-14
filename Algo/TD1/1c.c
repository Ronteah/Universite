#include <stdio.h>

int main(){
    int nombre;
    FILE * fichier;
    printf("Entrer un entier : ");
    scanf("%d", &nombre);

    if(nombre>0){
        fichier = fopen("diviseurs.txt", "w");

        for(int i=1; i<nombre; i++){
            if(nombre%i==0) fprintf(fichier, "%i ", i);
        }

        fclose(fichier;)
    }
    return 0;
}