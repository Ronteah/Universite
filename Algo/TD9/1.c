#include <stdio.h>

typedef struct element 
{
    int valeur; 
    struct element* suivant;
} t_element;

typedef struct
{
    t_element* tete;
    t_element* queue;
} t_file;



void initfile(t_file* f){
	f->tete = NULL;
	f->queue = NULL;
}

int filevide(t_file* f){
	return (f->tete == NULL);
}

void ajouter(t_file* f,int n)
{
    t_element* nouv;

    nouv = malloc(sizeof(t_element));
    nouv->valeur = n;
    nouv->suivant = NULL;

    if(filevide(f))
        f->tete = nouv;
    else
        f->queue->suivant = nouv;

    f->queue = nouv;
}

void retirer(t_file* f,int* n)
{
    t_element* premier;

    if(!filevide(f)){
        premier = f->tete;
        *n = premier->valeur;
        f->tete = premier->suivant;
        free(premier);
    }
}



int main() 
{
    t_file* pair;
    t_file* impair;
    initfile(pair);
    initfile(impair);

    int n;
    printf("Entrer une suite d'entiers positifs se terminant par -1 :\n");
    printf("(Appuyez sur ENTRER à chaque nouvelle valeur)\n");
    
    scanf("%i", &n);
    while(n != -1)
    {
        if (n%2 == 0)
        {
            ajouter(&pair, n);
        }else ajouter(&impair, n);

        scanf("%i", &n);        
    }

    while (!filevide(&pair))
    {
        retirer(&pair,&n);
        printf("%i",n);
    }

    while (!filevide(&impair))
    {
        retirer(&impair,&n);
        printf("%i",n);
    }
    

    return 0;
}