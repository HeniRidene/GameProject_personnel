// importing libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> //for loading images
#include <SDL/SDL_ttf.h>   //for loading fonts
#include <SDL/SDL_mixer.h> //for loading sounds

// including the headers
#include "../include/image.h"
#include "../include/music.h"
//heni
// images
SDL_Surface *screen;
image background;
image playButton;
image settingsButton;
image exitButton;

// music
Mix_Music *music;
Mix_Chunk *FX;

// logic
SDL_Event event;
int loop = 1;
int main()
{
    // initializing SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("SDL_Init Error: %s.\n", SDL_GetError());
        return 1;
    }

    // creating the window
    screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    if (screen == NULL)
    {
        printf("Error creating the screen: %s\n", SDL_GetError());
        return 1;
    }

    // loading images
    imageLoad_background(&background);
    imageLoad_playbutton(&playButton);
    imageLoad_settingsbutton(&settingsButton);
    imageLoad_quitbutton(&exitButton);
    // loading music
    musicLoad(music);
    // game loop
    while (loop)
    {
        imageDraw_background(screen, background);
        imageDraw_playbutton(screen, playButton);
        imageDraw_settingsbutton(screen, settingsButton);
        imageDraw_quitbutton(screen, exitButton);
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                loop = 0;
                break;

            default:
                break;
            }
        }

        // refreshing the screen
        SDL_Flip(screen);
    }
    SDL_Delay(5000);
    SDL_Quit();
    return 0;
}