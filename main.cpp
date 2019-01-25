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
class gTexture1
{
  public:
    SDL_Texture *gTextureball;
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

SDL_Texture *gTextureGround = NULL;
SDL_Window *gWindow = NULL;
SDL_Surface *gScreenSurface = NULL;
SDL_Texture *loadTexture(std::string path);
SDL_Renderer *gRenderer = NULL;
bool init();
bool loadMedia();
void close();
bool init()
{
    bool success = true;
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        {
            printf("Warning: Linear texture filtering not enabled!");
        }
        gWindow = SDL_CreateWindow("Mojtaba", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL)
        {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
            if (gRenderer == NULL)
            {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            }
            else
            {
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags))
                {
                    printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                    success = false;
                }
            }
        }
    }
    return success;
}
bool loadMedia(gTexture1 a[5])
{
    bool success = true;
    for (int i = 0; i < 5; i++)
    {
        a[i].gTextureball = loadTexture("ball.png");
    }
    for (int i = 0; i < 5; i++)
    {
        if (a[i].gTextureball == NULL)
        {
            printf("Failed to load texture image!\n");
            success = false;
        }
    }
    gTextureGround = loadTexture("ground.png");
    if (gTextureGround == NULL)
    {
        printf("Failed to load texture image!\n");
        success = false;
    }
    return success;
}
void close(gTexture1 a[5])
{
    for (int i = 0; i < 5; i++)
    {
        SDL_DestroyTexture(a[i].gTextureball);
    }
    for (int i = 0; i < 5; i++)
    {
        a[i].gTextureball = NULL;
    }
    SDL_DestroyTexture(gTextureGround);
    gTextureGround = NULL;
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    gRenderer = NULL;
    IMG_Quit();
    SDL_Quit();
}
SDL_Texture *loadTexture(std::string path)
{
    SDL_Texture *newTexture = NULL;
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }
    else
    {
        newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
        if (newTexture == NULL)
        {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }
        SDL_FreeSurface(loadedSurface);
    }
    return newTexture;
}
void InitialPositiom(gTexture1 a[5])
{
    a[0].x =82 ;
    a[0].y = 260;
    a[1].x = 315;
    a[1].y = 320;
    a[2].x = 315;
    a[2].y = 200;
    a[3].x = 200;
    a[3].y = 145;
    a[4].x = 200;
    a[4].y = 375;
}
int main()
{
    gTexture1 a[5];
    InitialPositiom(a);
    for (int i = 0; i < 5; i++)
    {
        a[i].gTextureball = NULL;
    }
    SDL_Init(SDL_INIT_VIDEO);
    if (!init())
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        if (!loadMedia(a))
        {
            printf("Failed to load media!\n");
        }
        else
        {
            bool quit = false;
            SDL_Event e;
            while (!quit)
            {
                while (SDL_PollEvent(&e) != 0)
                {
                    if (e.type == SDL_QUIT)
                    {
                        quit = true;
                    }
                }
                SDL_Rect dstrect1;
                dstrect1.x = 0;
                dstrect1.y = 0;
                dstrect1.w = 800;
                dstrect1.h = 500;
                SDL_RenderClear(gRenderer);
                SDL_RenderCopy(gRenderer, gTextureGround, NULL, &dstrect1);
                SDL_Rect dstrect2;
                dstrect2.w = 50;
                dstrect2.h = 50;
                for (int i = 0; i < 5; i++)
                {
                    dstrect2.x = a[i].x;
                    dstrect2.y = a[i].y;
                    SDL_RenderCopy(gRenderer, a[i].gTextureball, NULL, &dstrect2);
                }
                SDL_RenderCopy(gRenderer, a[0].gTextureball, NULL, &dstrect2);
                SDL_RenderPresent(gRenderer);
            }
        }
    }
    close(a);
    return 0;
}