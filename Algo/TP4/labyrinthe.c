#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
//#include "file.h"
//#include "pile.h"
#define VRAI 1
#define FAUX 0
#define N 25
#define M 55
#define COULOIR 0
#define MUR -1
#define CHEMIN -2

typedef struct element {int nombre; struct element* suivant;} t_element;
t_element* tete;
t_element* queue;

void initfile(void){
	tete = NULL;
	queue = NULL;
}

int filevide(void){
	return tete == NULL;
}

void ajouter(int v){
t_element* nouv;

nouv = malloc(sizeof(t_element));
nouv->nombre = v;
nouv->suivant = NULL;
if(filevide())
	tete = nouv;
else
	queue->suivant = nouv;
queue = nouv;
}

void retirer(int* v){
t_element* premier;

if(!filevide()){
	premier = tete;
	*v = premier->nombre;
	tete = premier->suivant;
	free(premier);
}
}

void afficher_lab(int lab[N][M]){
// Affiche le labyrinthe
    int i, j;
    
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if(lab[i][j] == MUR)
                printf("@ ");
            if(lab[i][j] == COULOIR)
                printf("  ");
        }
        printf("\n");
    }
}


void init_lab(int lab[N][M]){
//Initialise le labyrinthe avec des murs 
	int i,j;

	for(i=0;i<N;i++)
		for(j=0;j<M;j++)
			lab[i][j] = MUR;
}

//******************************
// Partie création du labyrinthe
//******************************

int valides(int i, int j){
// renvoie VRAI si i et j désignent une case de la matrice
	return(i>=0 && i<N &&j>=0 && j<M);
}

int est_vide(int i, int j, int lab[N][M]){
// renvoie VRAI si i et j désignent une case couloir
	return(valides(i,j) && lab[i][j]==COULOIR);
}

int est_mur(int i, int j, int lab[N][M]){
// renvoie VRAI si i et j d�signent une case mur
	return(valides(i,j) && lab[i][j]==MUR);
}

int blocage(int i, int j, int lab[N][M]){
// renvoie VRAI si aucune case voisine n'est un mur
	return (!est_mur(i+2,j,lab) && !est_mur(i-2,j,lab)
		&& !est_mur(i,j+2,lab) && !est_mur(i,j-2,lab));
}

int creer_lab(int lab[N][M]){
// Cree le labyrinthe de maniere aleatoire avec une pile

	int termine=FAUX;
	int trouve=FAUX;
	int i,j,alea;

	init_lab(lab);
	initpile();

	i=0, 
	j=0;
	lab[0][0]=COULOIR;

   while(!termine){

	if(blocage(i,j,lab)){
		if(!pilevide()){
			depiler(&j);
			depiler(&i);
		}
		else
			termine=VRAI;
	}
	else{
		trouve=FAUX;
		while(!trouve){
			alea=rand()%4; 
			switch(alea){
				case 0: 
					if(est_mur(i+2,j,lab)){ 
						empiler(i);
						empiler(j);
						lab[i+1][j]=COULOIR;
						lab[i+2][j]=COULOIR;
						i=i+2;
						trouve=VRAI;
						break;
					}	
				case 1: 	
					if(est_mur(i-2,j,lab)){
						empiler(i);
						empiler(j);
						lab[i-1][j]=COULOIR;
						lab[i-2][j]=COULOIR;
						i=i-2;
						trouve=VRAI;
						break;
					}	
				case 2: 	
					if(est_mur(i,j+2,lab)){
						empiler(i);
						empiler(j);
						lab[i][j+1]=COULOIR;
						lab[i][j+2]=COULOIR;
						j=j+2;
						trouve=VRAI;
						break;
					}	
				case 3: 	
					if(est_mur(i,j-2,lab)){
						empiler(i);
						empiler(j);
						lab[i][j-1]=COULOIR;
						lab[i][j-2]=COULOIR;
						j=j-2;
						trouve=VRAI;
					}	
			}
		}
	}
   }

}

//***************************
// Partie recherche de chemin
//***************************

int chercher_chemin(int lab[N][M],int xd, int yd, int xa, int ya){
//Cherche le chemin D -> A le plus court avec une file
// Renvoie VRAI si un chemin existe, FAUX sinon
	
	int i, j, indice = 1;
    lab[xd][yd]=1;

    while(lab[xa][ya]==0){
        for(i=0 ; i<N; i++)
        {
            for(j=0; j<M; j++){
                if(lab[i][j]==indice)
                {
                    if(est_vide(i+1, j,lab)==1 && valides(i+1,j)==1) lab[i+1][j]=indice+1;
                    if(est_vide(i-1, j,lab)==1 && valides(i-1,j)==1) lab[i-1][j]=indice+1;
                    if(est_vide(i, j+1,lab)==1 && valides(i,j+1)==1) lab[i][j+1]=indice+1;
                    if(est_vide(i, j-1,lab)==1 && valides(i,j-1)==1) lab[i][j-1]=indice+1;
                }
            }
        }
        indice++;
    }
	return indice;
}


void marquer_chemin(int lab[N][M],int x, int y,int* lgmin){
// Marque le chemin le plus court a partir de lab[x][y]
// Renvoie sa taille dans lgmin


	int i, j;
	int l,m;
	int save;

	for (l = 0; l < N; l++)
	{
		for (m = 0; m < M; m++)
		{
			if(lab[l][m] > lab[l-1][m]) save=lab[l][m];
		}
	}

	*lgmin = save;
	int indice = save;	

    while(lab[x][y]==1){
        for(i=0 ; i<N; i++)
        {
            for(j=0; j<M; j++){
                if(lab[i][j]==indice)
                {
                    if(est_vide(i+1, j,lab)==1 && valides(i+1,j)==1) lab[i+1][j]=-2;
                    if(est_vide(i-1, j,lab)==1 && valides(i-1,j)==1) lab[i-1][j]=-2;
                    if(est_vide(i, j+1,lab)==1 && valides(i,j+1)==1) lab[i][j+1]=-2;
                    if(est_vide(i, j-1,lab)==1 && valides(i,j-1)==1) lab[i][j-1]=-2;
                }
            }
        }
        indice--;
    }
}

//void nettoyer(int lab[N][M]){
// Nettoyage des couloirs (facultatif pour ce TP)

//}

//****************************************************
// Programme principal
// Cree le labyrinthe, cherche le chemin et l'affiche
//****************************************************

int main(){	
	int labyrinthe[N][M];
	int lgmin;
	
	srand(time(0));

	creer_lab(labyrinthe);
	afficher_lab(labyrinthe);

	if(chercher_chemin(labyrinthe,N-1,M-1,0,0)){
		marquer_chemin(labyrinthe,0,0,&lgmin);
		system("clear");
		afficher_lab(labyrinthe);
	}
	printf("Chemin le plus court de longueur %i\n",lgmin);

	return 0;
}