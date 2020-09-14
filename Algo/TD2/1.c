#include <stdio.h>

typedef enum
{
    carreau,
    coeur,
    trefle,
    pique
} t_couleur;
typedef enum
{
    as,
    deux,
    trois,
    quatre,
    cinq,
    six,
    sept,
    huit,
    neuf,
    dix,
    valet,
    cavalier,
    dame,
    roi
} t_hauteur;

typedef struct
{
    t_couleur couleur;
    t_hauteur hauteur;
} t_carte;

typedef union
{
    int atout;
    t_carte carte;
} t_tarot;

int main()
{
    t_tarot petit;
    petit.atout = 1;
    t_tarot cavalierPique;
    cavalierPique.carte.couleur = pique;
    cavalierPique.carte.hauteur = cavalier;

    return 0;
}