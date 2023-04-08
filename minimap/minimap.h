#ifndef MINIMAP_H
#define MINIMAP_H

typedef struct minimap
{
    int x;
    int y;
    int largeur;
    int hauteur;
    SDL_Surface *image;
    SDL_Surface *carte;
} minimap;

typedef struct Personne
{
    int x;
    int y;
    int largeur;
    int hauteur;
} Personne;

void initmap(minimap *m);
void afficherminimap(minimap m, SDL_Surface *screen);
void affichertemps(int temps);
int collisionPP(Personne p, SDL_Surface *Masque);
void animerMinimap(Mini carte *m);

#endif