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
    double x;
    double y;
    double a = -3;
    double v;
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
    double x;
    double y;
    int a = 3;
    int v;
    int m;
    void intialize()
    {
    }
    void move()
    {
    }
};
class gTexture3
{
  public:
    SDL_Texture *gTextureball;
    double x;
    double y;
    int a = 2;
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
bool loadMedia(gTexture1 a[5], gTexture2 iran[5], gTexture3 ball[1])
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
    ball[0].gTextureball = loadTexture("ball3.png");
    if (ball[0].gTextureball == NULL)
    {
        cout << "Failed to load texture image!\n";
        success = false;
    }

    return success;
}
void close(gTexture1 a[5], gTexture2 iran[5], gTexture3 ball[1])
{
    for (int i = 0; i < 5; i++)
    {
        SDL_DestroyTexture(a[i].gTextureball);
    }
    for (int i = 0; i < 5; i++)
    {
        a[i].gTextureball = NULL;
    }
    SDL_DestroyTexture(ball[0].gTextureball);
    ball[0].gTextureball = NULL;
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
void InitialPositiom(gTexture1 a[5], gTexture2 iran[5], gTexture3 ball[1])
{
    ball[0].x = 390;
    ball[0].y = 275;

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
void showmap(gTexture1 a[5], gTexture2 iran[5], gTexture3 ball[1])
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
    dstrect2.w = 20;
    dstrect2.h = 20;
    dstrect2.x = ball[0].x;
    dstrect2.y = ball[0].y;
    SDL_RenderCopy(gRenderer, ball[0].gTextureball, NULL, &dstrect2);
}
void drawcircleA(int i, double z, gTexture1 a[5])
{
    if (z < 22)
    {
        circleRGBA(gRenderer, a[i].x + 25, a[i].y + 25, 26, 255, 255, 255, 255);
    }
    else if (z < 80)
    {
        circleRGBA(gRenderer, a[i].x + 25, a[i].y + 25, z, 255, 255, 255, 255);
        a[i].v = z / 15;
    }
    else
    {
        circleRGBA(gRenderer, a[i].x + 25, a[i].y + 25, 80, 255, 255, 255, 255);
        a[i].v = 80.0 / 15.0;
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
        circleRGBA(gRenderer, iran[i].x + 25, iran[i].y + 25, z, 255, 255, 255, 255);
        iran[i].v = z / 15;
    }
    else
    {
        circleRGBA(gRenderer, iran[i].x + 25, iran[i].y + 25, 80, 255, 255, 255, 255);
        iran[i].v = 80.0 / 15.0;
    }
}
double CosDetermineA(double m, gTexture1 a[5], int x, int y, int i)
{
    double f;
    f = sqrt(1 / (m * m + 1));
    if (x == a[i].x + 25)
    {
        f = 0;
    }
    if (x == a[i].x + 25)
    {
        f = 0;
    }
    if (x > a[i].x + 25)
        f = -f;
    return f;
}
double SinDetermineA(double m, gTexture1 a[5], int x, int y, int i)
{
    double b;
    b = sqrt((m * m) / (m * m + 1));
    if (y > a[i].y + 25)
        b = -b;
    return b;
}
void drawlineA(gTexture1 a[5], double m, double z, int i, int x, int y)
{
    double b, f;
    b = SinDetermineA(m, a, x, y, i);
    f = CosDetermineA(m, a, x, y, i);
    double o = z;

    if (z > 80)
    {
        o = 80;
    }
    double e = 0;
    for (double p = 25 * f, e = 25 * b; abs(p) < abs(o * f), abs(e) < abs(o * b);)
    {

        cout << 3 << endl;
        SDL_RenderDrawPoint(gRenderer, a[i].x + p + 25, a[i].y + 25 + e);
        e += 2 * b;
        p += 2 * f;
    }
}
double SinDetermineIran(double m, gTexture2 iran[5], int x, int y, int i)
{
    double b;
    b = sqrt((m * m) / (m * m + 1));
    if (y > iran[i].y + 25)
        b = -b;
    return b;
}
double CosDetermineIran(double m, gTexture2 iran[5], int x, int y, int i)
{
    double f;
    f = sqrt(1 / (m * m + 1));

    if (x == iran[i].x + 25)
        f = 0;
    if (x > iran[i].x + 25)
        f = -f;
    return f;
}

void drawlineiran(gTexture2 iran[5], double m, double z, int i, int x, int y)
{
    double o = z;
    double f, b;
    b = SinDetermineIran(m, iran, x, y, i);
    f = CosDetermineIran(m, iran, x, y, i);
    if (z > 80)
    {
        o = 80;
    }
    double e = 0;
    for (double p = 25 * f, e = 25 * b; abs(p) < abs(o * f), abs(e) < abs(o * b);)
    {
        cout << 3 << endl;
        SDL_RenderDrawPoint(gRenderer, iran[i].x + p + 25, iran[i].y + 25 + e);
        e += 2 * b;
        p += 2 * f;
    }
}
void MoveA(gTexture2 a[5], int i)
{
    int v1 == a[i].v;
    while (a[i].v != 0)
    {
        a[i].x=
        iran[i].x =
    }
}

int main()
{
    int r = 0;
    bool flag = false;
    bool flag2 = true;
    int turn = 2;
    gTexture3 ball[1];
    gTexture1 a[5];
    gTexture2 iran[5];
    ball[0].gTextureball = NULL;
    for (int i = 0; i < 5; i++)
    {
        a[i].gTextureball = NULL;
        iran[i].gTextureball = NULL;
    }
    for (int i = 0; i < 5; i++)
    {
        a[i].v = 0;
        iran[i].v = 0;
    }
    ball[0].v = 0;
    InitialPositiom(a, iran, ball);
    SDL_Init(SDL_INIT_VIDEO);
    if (!init())
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        if (!loadMedia(a, iran, ball))
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
                showmap(a, iran, ball);
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
                                        if (((x - a[i].x - 25) * (x - a[i].x - 25)) + ((y - a[i].y - 25) * (y - a[i].y - 25)) < 625)
                                        {
                                            r = i;
                                            if (e.type == SDL_MOUSEBUTTONDOWN)
                                            {
                                                flag = true;

                                                while (flag)
                                                {
                                                    showmap(a, iran, ball);
                                                    if (SDL_PollEvent(&q) != 0)
                                                    {
                                                        if (q.type == SDL_MOUSEBUTTONUP)
                                                        {
                                                            if (sqrt(((x - a[i].x - 25) * (x - a[i].x - 25)) + ((y - a[i].y - 25) * (y - a[i].y - 25))) > 25)
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
                                                    drawlineA(a, m, z, i, x, y);
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
                        moveA(a, i);
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
                                        r = i;
                                        bool flag = false;
                                        if (e.type == SDL_MOUSEBUTTONDOWN)
                                        {
                                            flag = true;
                                            while (flag)
                                            {
                                                showmap(a, iran, ball);
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
                                                    m = (double(y) - iran[i].y - 25.0) / (double(x) - iran[i].x - 25.0);
                                                }
                                                drawlineiran(iran, m, z, i, x, y);
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
    close(a, iran, ball);
    return 0;
}