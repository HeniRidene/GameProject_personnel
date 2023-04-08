#ifndef PERSO_H_INCLUDED
#define PERSO_H_INCLUDED

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#define SCREEN_H 1000
#define SCREEN_W 720

typedef struct  personnage
{
	SDL_Rect posaffich;
	SDL_Rect posSprit;
	SDL_Surface *imgperso;
    SDL_Rect pos_score;
	int crouch;
    float acceleration;
	float score;
    int vie;
	float vitesse;
	int sens;

}personnage;


void initPerso(personnage *p);
void afficher_personnage(personnage p,SDL_Surface *ecran);
void deplacerPerso (personnage *p,int action,Uint32 dt);
void Saute(personnage *p,int action);
void animerPerso (int action,personnage* p);


#endif // PERSO_H_INCLUDED
