// Fonction initmap
void initmap(minimap *m)
{
    m->x = 0;
    m->y = 0;
    m->largeur = 800;
    m->hauteur = 600;
    m->image = IMG_Load("minimap.png");
    m->carte = SDL_CreateRGBSurface(0, m->largeur, m->hauteur, 32, 0, 0, 0, 0);
    SDL_BlitSurface(m->image, NULL, m->carte, NULL);
}

// Fonction afficherminimap
void afficherminimap(minimap m, SDL_Surface *screen)
{
    SDL_Rect position;
    position.x = m.x;
    position.y = m.y;
    SDL_BlitSurface(m.carte, NULL, screen, &position);
}
//Pour le calcul et l'affichage du temps depuis le lancement du jeu et le temps restant dans chaque énigme, voici le code C :

// Fonction affichertemps
void affichertemps(int temps)
{
    int temps_ecoule = SDL_GetTicks() - temps;
    int temps_restant = temps_ecoule % 1000;
    printf("Temps écoulé : %d secondes\nTemps restant : %d secondes\n", temps_ecoule/1000, temps_restant);
}
Pour la gestion de la collision perfect pixel, voici le code C :

// Fonction collisionPP
int collisionPP(Personne p, SDL_Surface *Masque)
{
    int collision = 0;
    Uint32 *pixels = (Uint32 *)Masque->pixels;
    int x = 0;
    int y = 0;
    for (x = p.x; x < p.x + p.largeur; x++)
    {
        for (y = p.y; y < p.y + p.hauteur; y++)
        {
            Uint32 pixel = pixels[(y * Masque->w) + x];
            if (pixel == 0xFFFFFFFF)
            {
                collision = 1;
            }
        }
    }
    return collision;
}
Pour l'animation de la mini-carte, voici le code C :

// Fonction animerMinimap
void animerMinimap(Mini carte *m)
{
    // Dessiner les points qui changent de couleur
    SDL_Rect position;
    position.x = m->x;
    position.y = m->y;
    SDL_BlitSurface(m->carte, NULL, m->image, &position);
    SDL_UpdateRect(m->image, position.x, position.y, m->largeur, m->hauteur);
}