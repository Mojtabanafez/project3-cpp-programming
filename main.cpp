
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
using namespace std;
#define PI 3.14159265
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 500;
//SDL_Rect *rect;
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
void init(int *v)
{
}
bool init();
bool loadMedia();
void close();
SDL_Texture *texture;
SDL_Event event;
SDL_Rect r;
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
bool loadMedia()
{
    bool success = true;
    gHelloWorld = SDL_LoadBMP("ground.bmp");
    if (gHelloWorld == NULL)
    {
        printf("Unable to load image %s! SDL Error: %s\n", " /home/mojtaba/Desktop/02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError());
        success = false;
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
    if (!init())
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        if (!loadMedia())
        {
            printf("Failed to load media!\n");
        }
        else
        {
            SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
            SDL_UpdateWindowSurface(gWindow);
            SDL_Delay(2000);
        }
    }
   /* while (true)
    {
        
        SDL_RenderPresent(renderer);
    }*/
    return 0;
}
