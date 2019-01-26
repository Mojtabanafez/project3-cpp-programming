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
<<<<<<< HEAD
const int BUTTON_WIDTH = 300;
const int BUTTON_HEIGHT = 200;
const int TOTAL_BUTTONS = 4;
/*class LButton
{
  public:
    LButton();
    void setPosition(int x, int y);
    void handleEvent(SDL_Event *e);
    void render();
=======
class gTexture2
{
  public:
    SDL_Texture *gTextureball1;
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
>>>>>>> 89d45afaa341c923bb413ac838483ab62088afa8

  private:
    SDL_Point mPosition;
};*/
SDL_Texture *gTextureGround = NULL;
SDL_Window *gWindow = NULL;
SDL_Surface *gScreenSurface = NULL;
SDL_Texture *loadTexture(std::string path);
SDL_Renderer *gRenderer = NULL;
//LButton gButtons[TOTAL_BUTTONS];
//LTexture gButtonSpriteSheetTexture;
bool init();
bool loadMedia();
void close();
/*LButton::LButton()
{
    mPosition.x = 0;
    mPosition.y = 0;
    mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
}
void LButton::setPosition(int x, int y)
{
    mPosition.x = x;
    mPosition.y = y;
}*/
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
                printf("Rendereracould not be created! SDL Error: %s\n", SDL_GetError());
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
bool loadMedia(gTexture2 b[5])
{
    bool success = true;
    for (int i = 0; i < 5; i++)
    {
        b[i].gTextureball1 = loadTexture("ball1.png");
    }
    for (int i = 0; i < 5; i++)
    {
        if (b[i].gTextureball1 == NULL)
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
void close(gTexture2 b[5])
{
    for (int i = 0; i < 5; i++)
    {
        SDL_DestroyTexture(b[i].gTextureball1);
    }
    for (int i = 0; i < 5; i++)
    {
        b[i].gTextureball1 = NULL;
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
}
void InitialPositiom(gTexture2 b[5])
{
    b[0].x = 660 ;
    b[0].y = 400;
    b[1].x = 315;
    b[1].y = 320;
    b[2].x = 315;
    b[2].y = 200;
    b[3].x = 200;
    b[3].y = 145;
    b[4].x = 200;
    b[4].y = 375;
}
int main()
{
    gTexture1 a[5];
    gTexture2 b[5];
    InitialPositiom(a);
    for (int i = 0; i < 5; i++)
    {
        a[i].gTextureball = NULL;
        b[i].gTextureball1 = NULL;
    }
    SDL_Init(SDL_INIT_VIDEO);
    if (!init())
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        if (!loadMedia(a)and!loadMedia(b))
        {
            printf("Failed to load media!\n");
        }
        else
        {
            bool quit = false;
            SDL_Event e;
            while (!quit)
            {
                //      handleEvent(SDL_Event e, gTexture1 a[5]);

                SDL_Rect dstrect1;
                dstrect1.x = 0;
                dstrect1.y = 0;
                dstrect1.w = 800;
                dstrect1.h = 500;
                SDL_RenderClear(gRenderer);
                SDL_RenderCopy(gRenderer, gTextureGround, NULL, &dstrect1);
                SDL_Rect dstrect2;
                SDL_Rect dstrect3;
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
                    dstrect3.x = b[i].x;
                    dstrect3.y = b[i].y;
                    SDL_RenderCopy(gRenderer, b[i].gTextureball1, NULL, &dstrect3);
                }
                SDL_RenderCopy(gRenderer, b[0].gTextureball1, NULL, &dstrect3);
                SDL_RenderCopy(gRenderer, a[0].gTextureball, NULL, &dstrect2);
                SDL_RenderPresent(gRenderer);
                while (SDL_PollEvent(&e) != 0)
                {
                    if (e.type == SDL_QUIT)
                    {
                        quit = true;
                    }
                    int r = 0;
                    int y = 0;
                    double m = 0;
                    if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP)
                    {
                        if (e.type == SDL_QUIT)
                        {
                            quit = true;
                        }
                        int x, y;
                        SDL_GetMouseState(&x, &y);
                        bool inside = true;
                        if (x < 0)
                        {
                            inside = false;
                        }
                        else if (x > 500)
                        {
                            inside = false;
                        }
                        else if (y < 0)
                        {
                            inside = false;
                        }
                        else if (y > 800)
                        {
                            inside = false;
                        }
                        if (!inside)
                        {
                            ;
                        }
                        else
                        {
                            for (int i = 0; i < 5; i++)
                            {
                                if (((x - a[i].x - 25) * (x - a[i].x - 25)) + ((y - a[i].y - 25) * (y - a[i].y - 25)) < 625)
                                {
                                    if (e.type == SDL_MOUSEBUTTONDOWN)
                                    {
                                        while (e.type != SDL_MOUSEBUTTONUP)
                                        {
                                            if (e.type == SDL_QUIT)
                                            {
                                                quit = true;
                                                break;
                                            }
                                            SDL_GetMouseState(&x, &y);

                                            y = sqrt(((x - a[i].x - 25) * (x - a[i].x - 25)) + ((y - a[i].y - 25) * (y - a[i].y - 25)));
                                            if (y < 80)
                                            {
                                                filledCircleRGBA(gRenderer, a[i].x + 25, a[i].y + 25, y, 255, 255, 255, 255);
                                                a[i].v = y / 15;
                                            }
                                            else
                                            {
                                                filledCircleRGBA(gRenderer, a[i].x + 25, a[i].y + 25, 80, 255, 255, 255, 255);
                                            }
                                            m = (y - a[i].y - 25) / (x - a[i].x - 25);
                                            int o = y;
                                            if (y > 80)
                                            {
                                                o = 80;
                                            }
                                            float e = 0;
                                            for (float p = 25 * sqrt(1 / (m * m + 1)), e = 25 * sqrt((m * m) / (m * m + 1)); p < o * (sqrt(1 / (m * m + 1))), e < o * (sqrt((m * m) / (m * m + 1)));)
                                            {
                                                SDL_RenderDrawPoint(gRenderer, a[i].x + p, a[i].y + e);
                                                e += 4 * sqrt((m * m) / (m * m + 1));
                                                p += 4 * sqrt(1 / (m * m + 1));
                                            }
                                            
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    close(a);
    close(b);
    return 0;
}