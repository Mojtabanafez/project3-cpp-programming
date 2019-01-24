
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
using namespace std;
#define PI 3.14159265
const int SCREEN_WIDTH = 1400;
const int SCREEN_HEIGHT = 900;

class balls1
{
  public:
    int x;
    int y;
    int a;
    int v;
    int m;
    void intialize()
    {
    }
    void move()
    {
    }
};
void showline(SDL_Renderer *renderer)
{
}
void init(int *v)
{
}
bool init();
bool loadMedia();
void close();
SDL_Window *gWindow = NULL;
SDL_Surface *gScreenSurface = NULL;
SDL_Surface *gHelloWorld = NULL;
bool init()
{
    bool success = true;
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        gWindow = SDL_CreateWindow("Mojtaba", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL)
        {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            gScreenSurface = SDL_GetWindowSurface(gWindow);
        }
    }
    return success;
}
void close()
{
    SDL_FreeSurface(gHelloWorld);
    gHelloWorld = NULL;
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    SDL_Quit();
}

int main()
{
    SDL_Window *window = NULL;
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Mojtaba", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    balls1 a[5];
    SDL_SetRenderDrawColor(renderer, 0, 100, 158, SDL_ALPHA_OPAQUE);
    while (true)
    {
        //      filledCircleRGBA(renderer, , a[, a[i].dia, 255, 255, 255, 255);
        //   showline(&renderer);
        SDL_RenderDrawLine(renderer, 100, 200, 1300, 200);
        SDL_RenderDrawLine(renderer, 1300, 200, 1300, 1300);
        SDL_RenderDrawLine(renderer, 50, 850, 550, 850);
        //        SDL_RenderDrawLine(renderer, 550, 100, 550, 850);
        SDL_RenderPresent(renderer);
    }
    return 0;
}
