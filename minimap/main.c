#include <stdio.h>
#include <SDL/SDL.h>
#include "minimap.h"

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Surface *screen = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);

    minimap m;
    initmap(&m);
    afficherminimap(m, screen);

    int temps = SDL_GetTicks();
    affichertemps(temps);

    Personne p;
    p.x = 0;
    p.y = 0;
    p.largeur = 10;
    p.hauteur = 10;
    int collision = collisionPP(p, m.carte);

    animerMinimap(&m);

    SDL_Flip(screen);

    SDL_Quit();

    return 0;
}