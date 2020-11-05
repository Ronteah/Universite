#include<stdio.h>
#include<stdlib.h>
#include "liste.h"

// Fonctions de manipulation de la liste 

void afficher(void){
// Affiche les valeurs de la liste 

	int elem;

	if(liste_vide())
		printf("La liste est vide\n");
	else{
		printf("\nLa liste contient: ");
		en_tete();
		while(!hors_liste()){
			valeur_elt(&elem);
			printf("%i ",elem);
			suivant();
		}
		printf("\n");
	}
}

void inserer(void){
// Insere une valeur dans la liste 

    int vcour, elem;

    printf("Entrer un entier : ");
    scanf("%i", &elem);

    if(liste_vide()==1)
    {
        ajout_gauche(elem);
    }else
    {
        en_queue();
        valeur_elt(&vcour);

        if(elem>=vcour) ajout_droit(elem);
        else
        {
            en_tete();
            valeur_elt(&vcour);

            while(elem>=vcour)
            {
                suivant();
                valeur_elt(&vcour);
            }
            ajout_gauche(elem);
        }
    }
}

void afficher_multiples(void){
// Affiche tous les multiples d'une valeur lue au clavier 

    int val, vcour;

    printf("Entrer un entier : ");
    scanf("%i", &val);

    en_tete();

    if(liste_vide()) printf("La liste est vide.\n");
    else{
        while(!hors_liste())
        {
            valeur_elt(&vcour);
            if(val%vcour==0) printf("%i", vcour);
            suivant();
        }
    }
}

void compter(void){
// Compte les occurrences d'une valeur lue au clavier 

    int val, vcour, res=0;

    printf("Entrer un entier : ");
    scanf("%i", &val);

    en_tete();

    if(liste_vide()) printf("La liste est vide.\n");
    else{
        while(!hors_liste())
        {   
            valeur_elt(&vcour);
            if(vcour==val) res++;
            suivant();
        }
    }
    printf("Il y a %i occurrences.\n", res);
}

void supprimer(void){
// Supprime toutes les occurrences d'une valeur lue au clavier

    int val, vcour;

    printf("Entrer un entier : ");
    scanf("%i", &val);

    en_tete();

    if(liste_vide()) printf("La liste est vide.\n");
    else{
        while(!hors_liste())
        {
            valeur_elt(&vcour);
            if(vcour==val) oter_elt();
            suivant();
        }
    }
}

void vider_liste(void){
// Supprime toutes les valeurs de la liste

    en_queue();

    if(liste_vide()) printf("La liste est deja vide.\n");
    else{
        while(!hors_liste())
        {
            oter_elt();
        }
    }
}

//	Programme principal 
int main(void){
	int choix;

// Initialisation de la liste d'entiers
	init_liste();

	do{
// Affichage du menu et saisie du choix
		printf("\nMenu :\n");
		printf(" 1 - Inserer une valeur\n");
		printf(" 2 - Afficher les multiples\n");
		printf(" 3 - Compter les occurrences d'une valeur\n");
		printf(" 4 - Supprimer une valeur\n");
		printf(" 5 - Vider la liste\n");
		printf(" 6 - Quitter\n");
		printf("Votre choix : ");
		scanf("%d",&choix);

// Traitement du choix de l'utilisateur 
		switch(choix){
			case 1: inserer();  afficher(); break;
			case 2: afficher_multiples(); afficher(); break;
			case 3: compter(); afficher(); break;
			case 4: supprimer(); afficher(); break;
			case 5: vider_liste(); afficher(); break;
			case 6: break;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 6\n");
		}
	}
	while(choix!=6);

	printf("Au revoir !\n");
	return EXIT_SUCCESS;
}