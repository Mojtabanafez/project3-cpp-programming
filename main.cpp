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
class gTexture2
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
void handleEvent(SDL_Event *e, gTexture1 a[5])
{
}
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
bool loadMedia(gTexture1 a[5], gTexture2 iran[5])
{
    bool success = true;
    for (int i = 0; i < 5; i++)
    {
        iran[i].gTextureball = loadTexture("ballsiran.png");
    }
    for (int i = 0; i < 5; i++)
    {
        if (iran[i].gTextureball == NULL)
        {
            printf("Failed to load texture image!\n");
            success = false;
        }
    }
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
void close(gTexture1 a[5], gTexture2 iran[5])
{
    for (int i = 0; i < 5; i++)
    {
        SDL_DestroyTexture(a[i].gTextureball);
    }
    for (int i = 0; i < 5; i++)
    {
        a[i].gTextureball = NULL;
    }
    for (int i = 0; i < 5; i++)
    {
        SDL_DestroyTexture(iran[i].gTextureball);
    }
    for (int i = 0; i < 5; i++)
    {
        iran[i].gTextureball = NULL;
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
void InitialPositiom(gTexture1 a[5], gTexture2 iran[5])
{
    a[0].x = 82;
    a[0].y = 260;
    a[1].x = 315;
    a[1].y = 320;
    a[2].x = 315;
    a[2].y = 200;
    a[3].x = 200;
    a[3].y = 145;
    a[4].x = 200;
    a[4].y = 375;

    iran[0].x = 668;
    iran[0].y = 260;
    iran[1].x = 435;
    iran[1].y = 320;
    iran[2].x = 435;
    iran[2].y = 200;
    iran[3].x = 550;
    iran[3].y = 145;
    iran[4].x = 550;
    iran[4].y = 375;
}
void showmap(gTexture1 a[5], gTexture2 iran[5])
{
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
    for (int i = 0; i < 5; i++)
    {
        dstrect2.x = iran[i].x;
        dstrect2.y = iran[i].y;
        SDL_RenderCopy(gRenderer, iran[i].gTextureball, NULL, &dstrect2);
    }
}
void drawcircleA(int i, double z, gTexture1 a[5])
{
    if (z < 22)
    {
        circleRGBA(gRenderer, a[i].x + 25, a[i].y + 25, 26, 255, 255, 255, 255);
    }
    else if (z < 80)
    {
        circleRGBA(gRenderer, a[i].x + 25, a[i].y + 25, 1.5 * z, 255, 255, 255, 255);
        a[i].v = z / 15;
    }
    else
    {
        circleRGBA(gRenderer, a[i].x + 25, a[i].y + 25, 120, 255, 255, 255, 255);
    }
}
void drawcircleiran(int i, double z, gTexture2 iran[5])
{
    if (z < 22)
    {
        circleRGBA(gRenderer, iran[i].x + 25, iran[i].y + 25, 26, 255, 255, 255, 255);
    }
    else if (z < 80)
    {
        circleRGBA(gRenderer, iran[i].x + 25, iran[i].y + 25, 1.5 * z, 255, 255, 255, 255);
        iran[i].v = z / 15;
    }
    else
    {
        circleRGBA(gRenderer, iran[i].x + 25, iran[i].y + 25, 120, 255, 255, 255, 255);
    }
}
void drawlineA(gTexture1 a[5], double m, double z, int i)
{
    double o = z;
    if (z > 80)
    {
        o = 80;
    }
    float e = 0;
    for (float p = 25 * sqrt(1 / (m * m + 1)), e = 25 * sqrt((m * m) / (m * m + 1)); p < o * (sqrt(1 / (m * m + 1))), e < o * (sqrt((m * m) / (m * m + 1)));)
    {
        SDL_RenderDrawPoint(gRenderer, a[i].x + p + 25, a[i].y + 25 + e);
        e += 2 * sqrt((m * m) / (m * m + 1));
        p += 2 * sqrt(1 / (m * m + 1));
    }
}
void drawlineiran(gTexture2 iran[5], double m, double z, int i)
{
    double o = z;
    if (z > 80)
    {
        o = 80;
    }
    float e = 0;
    for (float p = 25 * sqrt(1 / (m * m + 1)), e = 25 * sqrt((m * m) / (m * m + 1)); p < o * (sqrt(1 / (m * m + 1))), e < o * (sqrt((m * m) / (m * m + 1)));)
    {
        SDL_RenderDrawPoint(gRenderer, iran[i].x + p + 25, iran[i].y + 25 + e);
        e += 2 * sqrt((m * m) / (m * m + 1));
        p += 2 * sqrt(1 / (m * m + 1));
    }
}
int main()
{
    bool flag = false;
    bool flag2 = true;
    int turn = 2;
    gTexture1 a[5];
    gTexture2 iran[5];
    InitialPositiom(a, iran);
    for (int i = 0; i < 5; i++)
    {
        a[i].gTextureball = NULL;
        iran[i].gTextureball = NULL;
    }
    SDL_Init(SDL_INIT_VIDEO);
    if (!init())
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        if (!loadMedia(a, iran))
        {
            printf("Failed to load media!\n");
        }
        else
        {
            bool quit = false;
            SDL_Event e;
            SDL_Event q;
            while (!quit)
            {
                showmap(a, iran);
                SDL_RenderPresent(gRenderer);
                if (SDL_PollEvent(&e) != 0)
                {
                    if (e.type == SDL_QUIT)
                    {
                        quit = true;
                    }
                    if (flag2)
                    {
                        int r = 0;
                        double z = 0;
                        double m = 0;
                        if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP)
                        {
                            if (e.type == SDL_QUIT)
                            {
                                quit = true;
                            }
                            {
                                cout << 2 << endl;
                                if (e.type == SDL_QUIT)
                                {
                                    quit = true;
                                }
                                int x, y;
                                SDL_GetMouseState(&x, &y);
                                {
                                    cout << 123 << endl;
                                    for (int i = 0; i < 5; i++)
                                    {
                                        cout << 9 << endl;
                                        if (((x - a[i].x - 25) * (x - a[i].x - 25)) + ((y - a[i].y - 25) * (y - a[i].y - 25)) < 625)
                                        {

                                            cout << 5 << endl;
                                            if (e.type == SDL_MOUSEBUTTONDOWN)
                                            {
                                                flag = true;

                                                while (flag)
                                                {
                                                    cout << 3 << endl;
                                                    showmap(a, iran);
                                                    if (SDL_PollEvent(&q) != 0)
                                                    {
                                                        if (q.type == SDL_MOUSEBUTTONUP)
                                                        {
                                                            if (sqrt(((x - a[i].x - 25) * (x - a[i].x - 25)) + ((y - a[i].y - 25) * (y - a[i].y - 25)))>25)
                                                            {
                                                                flag2 = false;
                                                            }
                                                            flag = false;
                                                        }
                                                        if (q.type == SDL_QUIT)
                                                        {
                                                            flag2 = false;
                                                            quit = true;
                                                            break;
                                                        }
                                                    }
                                                    SDL_GetMouseState(&x, &y);
                                                    z = sqrt(((x - a[i].x - 25) * (x - a[i].x - 25)) + ((y - a[i].y - 25) * (y - a[i].y - 25)));
                                                    drawcircleA(i, z, a);
                                                    if (x - 25 != a[i].x)
                                                    {
                                                        m = (y - a[i].y - 25) / (x - a[i].x - 25);
                                                    }
                                                    drawlineA(a, m, z, i);
                                                    SDL_RenderPresent(gRenderer);
                                                    SDL_RenderClear(gRenderer);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        cout << 0 << endl;
                        //   int r = 0;
                        double z = 0;
                        double m = 0;
                        if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP)
                        {
                            if (e.type == SDL_QUIT)
                            {
                                quit = true;
                            }
                            int x, y;
                            SDL_GetMouseState(&x, &y);
                            {
                                for (int i = 0; i < 5; i++)
                                {
                                    if (((x - iran[i].x - 25) * (x - iran[i].x - 25)) + ((y - iran[i].y - 25) * (y - iran[i].y - 25)) < 625)
                                    {
                                        bool flag = false;
                                        if (e.type == SDL_MOUSEBUTTONDOWN)
                                        {
                                            flag = true;
                                            while (flag)
                                            {
                                                showmap(a, iran);
                                                if (SDL_PollEvent(&q) != 0)
                                                {
                                                    if (q.type == SDL_MOUSEBUTTONUP)
                                                    {
                                                        flag = false;
                                                        if (sqrt(((x - iran[i].x - 25) * (x - iran[i].x - 25)) + ((y - iran[i].y - 25) * (y - iran[i].y - 25))) > 25)
                                                        {
                                                            flag2 = true;
                                                        }
                                                    }
                                                    if (q.type == SDL_QUIT)
                                                    {
                                                        quit = true;
                                                        break;
                                                    }
                                                }
                                                SDL_GetMouseState(&x, &y);
                                                z = sqrt(((x - iran[i].x - 25) * (x - iran[i].x - 25)) + ((y - iran[i].y - 25) * (y - iran[i].y - 25)));
                                                drawcircleiran(i, z, iran);
                                                if (x - 25 != iran[i].x)
                                                {
                                                    m = (y - iran[i].y - 25) / (x - iran[i].x - 25);
                                                }
                                                drawlineiran(iran, m, z, i);
                                                SDL_RenderPresent(gRenderer);
                                                SDL_RenderClear(gRenderer);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    turn++;
                }
            }
        }
    }
    close(a, iran);
    return 0;
}
