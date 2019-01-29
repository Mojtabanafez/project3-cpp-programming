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
    double a;
    double ax;
    double ay;
    double v;
    double vy;
    double vx;
    double vx1;
    double vy1;
    double x1;
    double y1;
    double m;

    double t;
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
bool loadMedia(gTexture1 a[5], gTexture1 iran[5], gTexture1 ball[1])
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
void close(gTexture1 a[5], gTexture1 iran[5], gTexture1 ball[1])
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
void InitialPositiom(gTexture1 a[5], gTexture1 iran[5], gTexture1 ball[1])
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
void showmap(gTexture1 a[5], gTexture1 iran[5], gTexture1 ball[1])
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
        a[i].v = z;
    }
    else
    {
        circleRGBA(gRenderer, a[i].x + 25, a[i].y + 25, 80, 255, 255, 255, 255);
        a[i].v = 80.0;
    }
}
void drawcircleiran(int i, double z, gTexture1 iran[5])
{
    if (z < 22)
    {
        circleRGBA(gRenderer, iran[i].x + 25, iran[i].y + 25, 26, 255, 255, 255, 255);
    }
    else if (z < 80)
    {
        circleRGBA(gRenderer, iran[i].x + 25, iran[i].y + 25, z, 255, 255, 255, 255);
        iran[i].v = z;
    }
    else
    {
        circleRGBA(gRenderer, iran[i].x + 25, iran[i].y + 25, 80, 255, 255, 255, 255);
        iran[i].v = 80.0;
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
        SDL_RenderDrawPoint(gRenderer, a[i].x + p + 25, a[i].y + 25 + e);
        e += 2 * b;
        p += 2 * f;
    }
}
double SinDetermineIran(double m, gTexture1 iran[5], int x, int y, int i)
{
    double b;
    b = sqrt((m * m) / (m * m + 1));
    if (y > iran[i].y + 25)
        b = -b;
    return b;
}
double CosDetermineIran(double m, gTexture1 iran[5], int x, int y, int i)
{
    double f;
    f = sqrt(1.0 / (m * m + 1));

    if (x == iran[i].x + 25)
        f = 0;
    if (x > iran[i].x + 25)
        f = -f;
    return f;
}

void drawlineiran(gTexture1 iran[5], double m, double z, int i, int x, int y)
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
        SDL_RenderDrawPoint(gRenderer, iran[i].x + p + 25, iran[i].y + 25 + e);
        e += 2 * b;
        p += 2 * f;
    }
} /*
void checkWallStrike(int i, gTexture1 a[5], double *t, double *vx1, double *vy1)
{
    for (int i = 0; i < 5; i++)
    {
        if (a[i].x < 92)
        {
            a[i].vx *= (-1);
            *t = 0;
            *vx1 = a[i].vx;
        }
        if (a[i].x > 708)
        {
            a[i].vx *= (-1);
            *t = 0;
            *vx1 = a[i].vx;
        }
        if (a[i].y < 105)
        {
            a[i].vy *= (-1);
            *t = 0;
            *vy1 = a[i].vy;
        }
        if (a[i].y > 465)
        {
            a[i].vy *= (-1);
            *t = 0;
            *vy1 = a[i].vy;
        }
    }
}*/
double SinA(double m, gTexture1 a[5], int x, int y, int i)
{
    double b;
    b = sqrt((m * m) / (m * m + 1));
    if (y > a[i].y)
        b = -b;
    return b;
}
double CosA(double m, gTexture1 a[5], int x, int y, int i)
{
    double f;
    f = sqrt(1 / (m * m + 1));
    if (x == a[i].x)
    {
        f = 0;
    }
    if (x > a[i].x)
        f = -f;
    return f;
}
double SinIran(double m, gTexture1 iran[5], int x, int y, int i)
{
    double b;
    b = sqrt((m * m) / (m * m + 1));
    if (y > iran[i].y)
        b = -b;
    return b;
}
double CosIran(double m, gTexture1 iran[5], int x, int y, int i)
{
    double f;
    f = sqrt(1 / (m * m + 1));

    if (x == iran[i].x)
        f = 0;
    if (x > iran[i].x)
        f = -f;
    return f;
}
double m9(double x1, double x2, double y1, double y2)
{
    double m;
    if (x1 != x2)
    {
        m = (y2 - y1) / (x2 - x1);
    }
    return m;
}
void barkhord(gTexture1 iran[5], gTexture1 a[5], gTexture1 ball[1], int i)
{
    for (int p = 0; p < 5; p++)
    {
        for (int k = 0; k < 5; k++)
        {
            if (a[p].x < 67)
            {
                a[p].vx *= (-1);
                //    if(a[p].vx<0)
                //  a[p].ay *= (-1);
                a[p].vx1 = a[p].vx;
                a[p].x1 = a[p].x;
                a[p].vy1 = a[p].vy;
                a[p].y1 = a[p].y;
                a[p].t = 0;
            }
            if (a[p].x > 683)
            {
                a[p].vx *= (-1);
                //    if (a[p].vx < 0)
                //      a[p].ax *= (-1);
                a[p].vx1 = a[p].vx;
                a[p].vy1 = a[p].vy;
                a[p].x1 = a[p].x;
                a[p].y1 = a[p].y;
                a[p].t = 0;
            }
            if (a[p].y > 440)
            {

                a[p].vy *= (-1);
                a[p].vy1 = a[p].vy;
                a[p].vx1 = a[p].vx;
                a[p].x1 = a[p].x;
                a[p].y1 = a[p].y;
                a[p].t = 0;
                //    cout << "a[i].vx=" << a[i].vx << "a[i].vy=" << a[i].vy << endl;
            }
            if (a[p].y < 80)
            {
                a[p].vy *= (-1);
                a[p].vy1 = a[p].vy;
                a[p].vx1 = a[p].vx;
                a[p].x1 = a[p].x;
                a[p].y1 = a[p].y;
                a[p].t = 0;
            }

            if (iran[p].x < 67)
            {
                iran[p].vx *= (-1);
                iran[p].vx1 = iran[p].vx;
                iran[p].x1 = iran[p].x;
                iran[p].vy1 = iran[p].vy;
                iran[p].y1 = iran[p].y;
                iran[p].t = 0;
            }
            if (iran[p].x > 683)
            {
                iran[p].vx *= (-1);
                iran[p].vx1 = iran[p].vx;
                iran[p].vy1 = iran[p].vy;
                iran[p].x1 = iran[p].x;
                iran[p].y1 = iran[p].y;
                iran[p].t = 0;
            }
            if (iran[p].y > 440)
            {
                iran[p].vy *= (-1);
                iran[p].vy1 = iran[p].vy;
                iran[p].vx1 = iran[p].vx;
                iran[p].x1 = iran[p].x;
                iran[p].y1 = iran[p].y;
                iran[p].t = 0;
            }
            if (iran[p].y < 80)
            {
                iran[p].vy *= (-1);
                iran[p].vy1 = iran[p].vy;
                iran[p].vx1 = iran[p].vx;
                iran[p].x1 = iran[p].x;
                iran[p].y1 = iran[p].y;
                iran[p].t = 0;
            }
            double u;
            double t;
            if ((a[p].x - a[k].x) * (a[p].x - a[k].x) + (a[p].y - a[k].y) * (a[p].y - a[k].y) < 2500)
            {
                if (p != k)
                {
                    if (a[p].v == 0)
                    {
                        if (a[k].vx > 0)
                        {
                            if (a[k].x < a[p].x)
                            {
                                u = (a[p].y - a[k].y) / 50.0;
                                t = (a[p].x - a[k].x) / 50.0;
                                //cout << "k" << endl;
                                a[k].v = abs(a[k].vx) * u;
                                a[k].vx = a[k].v * u;
                                a[k].vy = (-1) * a[k].v * t;
                                a[k].x1 = a[k].x;
                                a[k].t = 0;
                                a[k].y1 = a[k].y;
                                a[k].vx1 = a[k].vx;
                                a[k].vy1 = a[k].vy;

                                a[p].v = abs(a[k].vx) * t;
                                a[p].vx = a[p].v * t;
                                a[p].vy = a[p].v * u;
                                a[p].x1 = a[p].x;
                                a[p].t = 0;
                                a[p].y1 = a[p].y;
                                a[p].vx1 = a[p].vx;
                                a[p].vy1 = a[p].vy;
                            }
                        }
                        else if (a[k].vx < 0)
                        {
                            if (a[k].x > a[p].x)
                            {
                                u = (a[p].y - a[k].y) / 50.0;
                                t = (a[p].x - a[k].x) / 50.0;
                                //cout << "k" << endl;
                                a[k].v = abs(a[k].vx) * u;
                                a[k].vx = a[k].v * u;
                                a[k].vy = (-1) * a[k].v * t;
                                a[k].x1 = a[k].x;
                                a[k].t = 0;
                                a[k].y1 = a[k].y;
                                a[k].vx1 = a[k].vx;
                                a[k].vy1 = a[k].vy;

                                a[p].v = abs(a[k].vx) * t;
                                a[p].vx = a[p].v * t;
                                a[p].vy = a[p].v * u;
                                a[p].x1 = a[p].x;
                                a[p].t = 0;
                                a[p].y1 = a[p].y;
                                a[p].vx1 = a[p].vx;
                                a[p].vy1 = a[p].vy;
                            }
                        }
                        if (a[k].vy > 0)
                        {
                            if (a[k].y < a[p].y)
                            {
                                u = (a[p].x - a[k].x) / (50.0);
                                t = (a[p].y - a[k].y) / (50.0);

                                a[k].v = abs(a[k].vy) * (u);
                                a[k].vx += (-1) * (a[k].v) * (t);
                                a[k].vy += u * (a[k].v);
                                a[k].x1 = a[k].x;
                                a[k].t = 0;
                                a[k].y1 = a[k].y;
                                a[k].vx1 = a[k].vx;
                                a[k].vy1 = +a[k].vy;

                                a[p].v = abs(a[k].vy) * t;
                                a[p].vx += a[p].v * t;
                                a[p].vy += a[p].v * u;
                                a[p].x1 = a[p].x;
                                a[p].t = 0;
                                a[p].y1 = a[p].y;
                                a[p].vx1 = a[p].vx;
                                a[p].vy1 = a[p].vy;
                            }
                        }
                        else if (a[k].vy < 0)
                        {
                            if (a[k].y > a[p].y)
                            {
                                u = (a[p].x - a[k].x) / (50.0);
                                t = (a[p].y - a[k].y) / (50.0);
                                a[k].v = abs(a[k].vy) * (u);
                                a[k].vx += (-1) * (a[k].v) * (t);
                                a[k].vy += u * (a[k].v);
                                a[k].x1 = a[k].x;
                                a[k].t = 0;
                                a[k].y1 = a[k].y;
                                a[k].vx1 = a[k].vx;
                                a[k].vy1 = a[k].vy;

                                a[p].v = abs(a[k].vy) * t;
                                a[p].vx += a[p].v * t;
                                a[p].vy += a[p].v * u;
                                a[p].x1 = a[p].x;
                                a[p].t = 0;
                                a[p].y1 = a[p].y;
                                a[p].vx1 = a[p].vx;
                                a[p].vy1 = a[p].vy;
                            }
                        }
                    }

                    if (a[k].v == 0)
                    {
                        if (a[p].vx > 0)
                        {
                            if (a[p].x < a[k].x)
                            {
                                u = (a[k].y - a[p].y) / 50.0;
                                t = (a[k].x - a[p].x) / 50.0;
                                // cout << "m1" << m1;
                                // cout << "n" << endl;
                                a[k].v = abs(a[p].vx) * t;
                                a[k].vx = a[k].v * t;
                                a[k].vy = a[k].v * u;
                                a[k].x1 = a[k].x;
                                a[k].t = 0;
                                a[k].y1 = a[k].y;
                                a[k].vx1 = a[k].vx;
                                a[k].vy1 = a[k].vy;

                                a[p].v = abs(a[p].vx) * u;
                                a[p].vx = a[p].v * u;
                                a[p].vy = (-1) * a[p].v * t;
                                a[p].x1 = a[p].x;
                                a[p].t = 0;
                                a[p].y1 = a[p].y;
                                a[p].vx1 = a[p].vx;
                                a[p].vy1 = a[p].vy;
                            }
                        }
                        else if (a[p].vx < 0)
                        {
                            if (a[p].x > a[k].x)
                            {
                                u = (a[k].y - a[p].y) / 50.0;
                                t = (a[k].x - a[p].x) / 50.0;
                                // cout << "m1" << m1;
                                // cout << "n" << endl;
                                a[k].v = abs(a[p].vx) * t;
                                a[k].vx = a[k].v * t;
                                a[k].vy = a[k].v * u;
                                a[k].x1 = a[k].x;
                                a[k].t = 0;
                                a[k].y1 = a[k].y;
                                a[k].vx1 = a[k].vx;
                                a[k].vy1 = a[k].vy;

                                a[p].v = abs(a[p].vx) * u;
                                a[p].vx = a[p].v * u;
                                a[p].vy = (-1) * a[p].v * t;
                                a[p].x1 = a[p].x;
                                a[p].t = 0;
                                a[p].y1 = a[p].y;
                                a[p].vx1 = a[p].vx;
                                a[p].vy1 = a[p].vy;
                            }
                        }
                        if (a[p].vy > 0)
                        {
                            if (a[p].y < a[k].y)
                            {
                                u = (a[k].x - a[p].x) / (50.0);
                                t = (a[k].y - a[p].y) / (50.0);
                                a[p].v = a[k].vy * u;
                                a[p].vx += (-1) * a[p].v * u;
                                a[p].vy += a[p].v * t;
                                a[p].x1 = a[p].x;
                                a[p].t = 0;
                                a[p].y1 = a[p].y;
                                a[p].vx1 = a[p].vx;
                                a[p].vy1 = a[p].vy;

                                a[k].v = a[p].vy * t;
                                a[k].vx += a[k].v * t;
                                a[k].vy += a[k].v * u;
                                a[k].x1 = a[k].x;
                                a[k].t = 0;
                                a[k].y1 = a[k].y;
                                a[k].vx1 = a[k].vx;
                                a[k].vy1 = a[k].vy;
                            }
                        }
                        else if (a[p].vy < 0)
                        {
                            if (a[p].y > a[k].y)
                            {
                                u = (a[k].x - a[p].x) / (50.0);
                                t = (a[k].y - a[p].y) / (50.0);
                                a[p].v = a[k].vy * u;
                                a[p].vx += (-1) * a[p].v * u;
                                a[p].vy += a[p].v * t;
                                a[p].x1 = a[p].x;
                                a[p].t = 0;
                                a[p].y1 = a[p].y;
                                a[p].vx1 = a[p].vx;
                                a[p].vy1 = a[p].vy;

                                a[k].v = a[p].vy * t;
                                a[k].vx += a[k].v * t;
                                a[k].vy += a[k].v * u;
                                a[k].x1 = a[k].x;
                                a[k].t = 0;
                                a[k].y1 = a[k].y;
                                a[k].vx1 = a[k].vx;
                                a[k].vy1 = a[k].vy;
                            }
                        }
                        a[k].v = sqrt(a[k].vx * a[k].vx + a[k].vy * a[k].vy);
                        a[p].v = sqrt(a[p].vx * a[p].vx + a[p].vy * a[p].vy);

                        //cout << "a[k].vx=" << a[k].vx << endl;
                        // cout << "a[k].vy=" << a[k].vy << endl;
                    }
                }
            }/*
            if ((a[p].x - iran[k].x) * (a[p].x - iran[k].x) + (a[p].y - iran[k].y) * (a[p].y - iran[k].y) < 2500)
            {
                if (p != k)
                {
                    if (a[p].v == 0)
                    {
                        u = (a[p].y - iran[k].y) / 50.0;
                        t = (a[p].x - iran[k].x) / 50.0;
                        a[p].v = iran[k].v * t;
                        iran[k].v = iran[k].v * u;
                        iran[k].vx = iran[k].v * u;
                        iran[k].vy = iran[k].v * t;
                        a[p].vx = a[p].v * t;
                        a[p].vy = a[p].v * u;
                    }
                    if (iran[k].v == 0)
                    {
                        u = (a[p].y - iran[k].y) / 50.0 * (-1);
                        t = (a[p].x - iran[k].x) / 50.0 * (-1);
                        // cout << "m1" << m1;
                        //  cout << "n" << endl;
                        iran[k].v = a[p].v * t;
                        a[p].v = a[p].v * u;
                        a[p].vx = a[p].v * u;
                        a[p].vy = a[p].v * t;
                        iran[k].vx = iran[k].v * t;
                        iran[k].vy = iran[k].v * u;
                        // cout << "a[k].vx=" << a[k].vx << endl;
                        //cout << "a[k].vy=" << a[k].vy << endl;));
                    }
                }
            }
            if ((a[p].x - ball[1].x) * (a[p].x - ball[1].x) + (a[p].y - ball[1].y) * (a[p].y - ball[1].y) < 1225)
            {
                if (p != k)
                {
                    if (a[p].v == 0)
                    {
                        u = (a[p].y - ball[1].y) / 35.0;
                        t = (a[p].x - ball[1].x) / 35.0;
                        a[p].v = ball[1].v * t;
                        ball[1].v = ball[1].v * u;
                        ball[1].vx = ball[1].v * u;
                        ball[1].vy = ball[1].v * t;
                        a[p].vx = a[p].v * t;
                        a[p].vy = a[p].v * u;
                    }
                    if (ball[1].v == 0)
                    {
                        u = (a[p].y - ball[1].y) / 35.0 * (-1);
                        t = (a[p].x - ball[1].x) / 35.0 * (-1);
                        // cout << "m1" << m1;
                        // cout << "n" << endl;
                        ball[1].v = a[p].v * t;
                        a[p].v = a[p].v * u;
                        a[p].vx = a[p].v * u;
                        a[p].vy = a[p].v * t;
                        ball[1].vx = ball[1].v * t;
                        ball[1].vy = ball[1].v * u;
                        //cout << "a[k].vx=" << a[k].vx << endl;
                        // cout << "a[k].vy=" << a[k].vy << endl;));
                    }
                }
            }
            if ((iran[p].x - ball[1].x) * (iran[p].x - ball[1].x) + (iran[p].y - ball[1].y) * (iran[p].y - ball[1].y) < 1225)
            {
                if (p != k)
                {
                    if (iran[p].v == 0)
                    {
                        u = (iran[p].y - ball[1].y) / 35.0;
                        t = (iran[p].x - ball[1].x) / 35.0;
                        iran[p].v = ball[1].v * t;
                        ball[1].v = ball[1].v * u;
                        ball[1].vx = ball[1].v * u;
                        ball[1].vy = ball[1].v * t;
                        iran[p].vx = iran[p].v * t;
                        iran[p].vy = iran[p].v * u;
                    }
                    if (ball[1].v == 0)
                    {
                        u = (iran[p].y - ball[1].y) / 35.0 * (-1);
                        t = (iran[p].x - ball[1].x) / 35.0 * (-1);
                        ball[1].v = iran[p].v * t;
                        iran[p].v = iran[p].v * u;
                        iran[p].vx = iran[p].v * u;
                        iran[p].vy = iran[p].v * t;
                        ball[1].vx = ball[1].v * t;
                        ball[1].vy = ball[1].v * u;
                    }
                }
            }*/
            if ((iran[p].x - iran[k].x) * (iran[p].x - iran[k].x) + (iran[p].y - iran[k].y) * (iran[p].y - iran[k].y) < 2500)
            {
                if (p != k)
                {
                    if (iran[p].v == 0)
                    {
                        if (iran[k].vx > 0)
                        {
                            if (iran[k].x < iran[p].x)
                            {
                                u = (iran[p].y - iran[k].y) / 50.0;
                                t = (iran[p].x - iran[k].x) / 50.0;
                                //cout << "k" << endl;
                                iran[k].v = abs(iran[k].vx) * u;
                                iran[k].vx = iran[k].v * u;
                                iran[k].vy = (-1) * iran[k].v * t;
                                iran[k].x1 = iran[k].x;
                                iran[k].t = 0;
                                iran[k].y1 = iran[k].y;
                                iran[k].vx1 = iran[k].vx;
                                iran[k].vy1 = iran[k].vy;

                                iran[p].v = abs(a[k].vx) * t;
                                iran[p].vx = iran[p].v * t;
                                iran[p].vy = iran[p].v * u;
                                iran[p].x1 = iran[p].x;
                                iran[p].t = 0;
                                iran[p].y1 = iran[p].y;
                                iran[p].vx1 = iran[p].vx;
                                iran[p].vy1 = iran[p].vy;
                            }
                        }
                        else if (iran[k].vx < 0)
                        {
                            if (iran[k].x > iran[p].x)
                            {
                                u = (iran[p].y - iran[k].y) / 50.0;
                                t = (iran[p].x - iran[k].x) / 50.0;
                                //cout << "k" << endl;
                                iran[k].v = abs(iran[k].vx) * u;
                                iran[k].vx = iran[k].v * u;
                                iran[k].vy = (-1) * iran[k].v * t;
                                iran[k].x1 = iran[k].x;
                                iran[k].t = 0;
                                iran[k].y1 = iran[k].y;
                                iran[k].vx1 = iran[k].vx;
                                iran[k].vy1 = iran[k].vy;

                                iran[p].v = abs(a[k].vx) * t;
                                iran[p].vx = iran[p].v * t;
                                iran[p].vy = iran[p].v * u;
                                iran[p].x1 = iran[p].x;
                                iran[p].t = 0;
                                iran[p].y1 = iran[p].y;
                                iran[p].vx1 = iran[p].vx;
                                iran[p].vy1 = iran[p].vy;
                            }
                        }
                        if (iran[k].vy > 0)
                        {
                            if (iran[k].y < iran[p].y)
                            {
                                u = (iran[p].x - iran[k].x) / (50.0);
                                t = (iran[p].y - iran[k].y) / (50.0);

                                iran[k].v = abs(iran[k].vy) * (u);
                                iran[k].vx += (-1) * (iran[k].v) * (t);
                                iran[k].vy += u * (iran[k].v);
                                iran[k].x1 = iran[k].x;
                                iran[k].t = 0;
                                iran[k].y1 = iran[k].y;
                                iran[k].vx1 = iran[k].vx;
                                iran[k].vy1 = iran[k].vy;

                                iran[p].v = abs(iran[k].vy) * t;
                                iran[p].vx += iran[p].v * t;
                                iran[p].vy += iran[p].v * u;
                                iran[p].x1 = iran[p].x;
                                iran[p].t = 0;
                                iran[p].y1 = iran[p].y;
                                iran[p].vx1 = iran[p].vx;
                                iran[p].vy1 = iran[p].vy;
                            }
                        }
                        else if (iran[k].vy < 0)
                        {
                            if (iran[k].y > iran[p].y)
                            {
                                u = (iran[p].x - iran[k].x) / (50.0);
                                t = (iran[p].y - iran[k].y) / (50.0);

                                iran[k].v = abs(iran[k].vy) * (u);
                                iran[k].vx += (-1) * (iran[k].v) * (t);
                                iran[k].vy += u * (iran[k].v);
                                iran[k].x1 = iran[k].x;
                                iran[k].t = 0;
                                iran[k].y1 = iran[k].y;
                                iran[k].vx1 = iran[k].vx;
                                iran[k].vy1 = iran[k].vy;

                                iran[p].v = abs(iran[k].vy) * t;
                                iran[p].vx += iran[p].v * t;
                                iran[p].vy += iran[p].v * u;
                                iran[p].x1 = iran[p].x;
                                iran[p].t = 0;
                                iran[p].y1 = iran[p].y;
                                iran[p].vx1 = iran[p].vx;
                                iran[p].vy1 = iran[p].vy;
                            }
                        }
                    }

                    if (iran[k].v == 0)
                    {
                        if (iran[p].vx > 0)
                        {
                            if (iran[p].x < iran[k].x)
                            {
                                u = (iran[k].y - iran[p].y) / 50.0;
                                t = (iran[k].x - iran[p].x) / 50.0;
                                // cout << "m1" << m1;
                                // cout << "n" << endl;
                                iran[k].v = abs(iran[p].vx) * t;
                                iran[k].vx = iran[k].v * t;
                                iran[k].vy = iran[k].v * u;
                                iran[k].x1 = iran[k].x;
                                iran[k].t = 0;
                                iran[k].y1 = iran[k].y;
                                iran[k].vx1 = iran[k].vx;
                                iran[k].vy1 = iran[k].vy;

                                iran[p].v = abs(iran[p].vx) * u;
                                iran[p].vx = iran[p].v * u;
                                iran[p].vy = (-1) * iran[p].v * t;
                                iran[p].x1 = iran[p].x;
                                iran[p].t = 0;
                                iran[p].y1 = iran[p].y;
                                iran[p].vx1 = iran[p].vx;
                                iran[p].vy1 = iran[p].vy;
                            }
                        }
                        else if (iran[p].vx < 0)
                        {
                            if (iran[p].x > iran[k].x)
                            {
                                u = (iran[k].y - iran[p].y) / 50.0;
                                t = (iran[k].x - iran[p].x) / 50.0;
                                // cout << "m1" << m1;
                                // cout << "n" << endl;
                                iran[k].v = abs(iran[p].vx) * t;
                                iran[k].vx = iran[k].v * t;
                                iran[k].vy = iran[k].v * u;
                                iran[k].x1 = iran[k].x;
                                iran[k].t = 0;
                                iran[k].y1 = iran[k].y;
                                iran[k].vx1 = iran[k].vx;
                                iran[k].vy1 = iran[k].vy;

                                iran[p].v = abs(iran[p].vx) * u;
                                iran[p].vx = iran[p].v * u;
                                iran[p].vy = (-1) * iran[p].v * t;
                                iran[p].x1 = iran[p].x;
                                iran[p].t = 0;
                                iran[p].y1 = iran[p].y;
                                iran[p].vx1 = iran[p].vx;
                                iran[p].vy1 = iran[p].vy;
                            }
                        }
                        if (iran[p].vy > 0)
                        {
                            if (iran[p].y < iran[k].y)
                            {
                                u = (iran[k].x - iran[p].x) / (50.0);
                                t = (iran[k].y - iran[p].y) / (50.0);
                                iran[p].v = iran[k].vy * u;
                                iran[p].vx += (-1) * iran[p].v * u;
                                iran[p].vy += iran[p].v * t;
                                iran[p].x1 = iran[p].x;
                                iran[p].t = 0;
                                iran[p].y1 = iran[p].y;
                                iran[p].vx1 = iran[p].vx;
                                iran[p].vy1 = iran[p].vy;

                                iran[k].v = iran[p].vy * t;
                                iran[k].vx += iran[k].v * t;
                                iran[k].vy += iran[k].v * u;
                                iran[k].x1 = iran[k].x;
                                iran[k].t = 0;
                                iran[k].y1 = iran[k].y;
                                iran[k].vx1 = iran[k].vx;
                                iran[k].vy1 = iran[k].vy;
                            }
                        }
                        else if (iran[p].vy < 0)
                        {
                            if (iran[p].y > iran[k].y)
                            {
                                u = (iran[k].x - iran[p].x) / (50.0);
                                t = (iran[k].y - iran[p].y) / (50.0);
                                iran[p].v = iran[k].vy * u;
                                iran[p].vx += (-1) * iran[p].v * u;
                                iran[p].vy += iran[p].v * t;
                                iran[p].x1 = iran[p].x;
                                iran[p].t = 0;
                                iran[p].y1 = iran[p].y;
                                iran[p].vx1 = iran[p].vx;
                                iran[p].vy1 = iran[p].vy;

                                iran[k].v = iran[p].vy * t;
                                iran[k].vx += iran[k].v * t;
                                iran[k].vy += iran[k].v * u;
                                iran[k].x1 = iran[k].x;
                                iran[k].t = 0;
                                iran[k].y1 = iran[k].y;
                                iran[k].vx1 = iran[k].vx;
                                iran[k].vy1 = iran[k].vy;
                            }
                        }
                        iran[k].v = sqrt(iran[k].vx * iran[k].vx + iran[k].vy * iran[k].vy);
                        iran[p].v = sqrt(iran[p].vx * iran[p].vx + iran[p].vy * iran[p].vy);

                        //cout << "a[k].vx=" << a[k].vx << endl;
                        // cout << "a[k].vy=" << a[k].vy << endl;
                    }
                }
          //  } 
           // }

            if (a[k].vx > 0)
            {
                a[k].ax = -(abs(a[k].ax));
            }
            else if (a[k].vx == 0)
            {
                a[k].ax = 0;
            }
            else
            {
                a[k].ax = (abs(a[k].ax));
            }

            if (a[k].vy > 0)
            {
                a[k].ay = -(abs(a[k].ay));
            }
            else if (a[k].vy == 0)
            {
                a[k].ay = 0;
            }
            else
            {
                a[k].ay = (abs(a[k].ay));
            }
            if (iran[k].vx > 0)
            {
                iran[k].ax = -(abs(iran[k].ax));
            }
            else if (iran[k].vx == 0)
            {
                iran[k].ax = 0;
            }
            else
            {
                iran[k].ax = (abs(iran[k].ax));
            }

            if (iran[k].vy > 0)
            {
                iran[k].ay = -(abs(iran[k].ay));
            }
            else if (iran[k].vy == 0)
            {
                iran[k].ay = 0;
            }
            else
            {
                iran[k].ay = (abs(iran[k].ay));
            }
        }
        }
    
    }
}

//void MoveIran(double m, int x, int y, gTexture1 a[5], gTexture1 iran[5], gTexture1 ball[1]);
void MoveA(double m, int x, int y, gTexture1 a[5], gTexture1 iran[5], gTexture1 ball[1])
{
    for (int i = 0; i < 5; i++)
    {
        a[i].vy = ((a[i].v) * SinDetermineA(m, a, x, y, i));
        a[i].vx = ((a[i].v) * CosDetermineA(m, a, x, y, i));
        a[i].ay = ((a[i].a) * SinDetermineA(m, a, x, y, i));
        a[i].ax = ((a[i].a) * CosDetermineA(m, a, x, y, i));
        a[i].t = 0;
    }
    for (int i = 0; i < 5; i++)
    {
        a[i].vy = ((a[i].v) * SinDetermineA(m, a, x, y, i));
        a[i].vx = ((a[i].v) * CosDetermineA(m, a, x, y, i));
        a[i].ay = ((a[i].a) * SinDetermineA(m, a, x, y, i));
        a[i].ax = ((a[i].a) * CosDetermineA(m, a, x, y, i));
        //   a[i].t = 0;
        //  cout <<"m="<<m<<endl;
        //   cout<<"m="<<m<<endl;
        //   cout << "i" << i << endl;
        //     cout << "a[i].vy=" << a[i].vy << "\ta[i].vx=" << a[i].vx /*<<"\t"<< a[i].ay<<"\t" << a[i].ax*/
         //   << endl;
            // cout << SinDetermineA(m, a, x, y, i) << "\t" << CosDetermineA(m, a, x, y, i) << endl;
            a[i].vx1 = a[i].vx;
            a[i].vy1 = a[i].vy;
            a[i].x1 = a[i].x;
            a[i].y1 = a[i].y;
            cout << "ghfjlkdsflsjkgjkjsdfk" << a[2].v << endl;
            //   cout<<"x1="<<x1<<endl;
            while ((abs(a[i].vx)) > 0.5 || abs(a[i].vy) > 0.5)
            //   while (((a[i].vx * a[i].vx) + (a[i].vy * a[i].vy)) >= 0. - 1)
            {
                // SDL_Delay(10);
                //      cout << "i=" << i << endl;
                //   cout << "a[g].x" << a[g].x << "a[g].y=" << a[g].y << endl;
                //     cout << "a[i].vx=" << a[i].vx << "a[i].vy=" << a[i].vy << endl
                //          << endl;
                for (int j = 0; j < 5; j++)
                {
                    if (((abs(a[j].vx)) > 0.5 || abs(a[j].vy) > 0.5))
                    {
                        //    cout << "a[i].ax=" << a[i].ax << "a[i].ay=" << a[i].ay << endl;
                        //     cout << "a[j].vx=" << a[j].vx << endl;
                        //   cout << "i=" << i << endl;
                        a[j].x = (((0.5) * (a[j].ax) * a[j].t * a[j].t) + (a[j].vx1 * a[j].t) + a[j].x1);
                        //   cout << ".a[i].x=" << a[i].x << endl;
                        //   cout << ".a[i].y=" << a[i].y <<"t="<<t<<"a[i].ay="<<a[i].ay<<"vy1="<<vy1<< endl;
                        a[j].y = (((0.5) * (a[j].ay) * a[j].t * a[j].t) + (a[j].vy1 * a[j].t) + a[j].y1);
                        //    cout << "a[j].vx=" << a[j].vx << endl;
                        a[j].vx = (a[j].ax * a[j].t) + a[j].vx1;
                        a[j].vy = (a[j].ay * a[j].t) + a[j].vy1;
                        //  cout << "a[i].vx=" << a[j].vx << endl;
                        showmap(a, iran, ball);
                        SDL_RenderPresent(gRenderer);
                        barkhord(iran, a, ball, j);

                        a[j].t += 0.001;
                        SDL_RenderClear(gRenderer);
                        /*  if (abs(a[j].vx) < 0.5)
                        break;
                    if (abs(a[j].vy) < 0.5)
                        break;
                    SDL_RenderClear(gRenderer);
                }*/
                    }
                }
              
        }
    }
    for (int i = 0; i < 5; i++)
        a[i].v = 0;
}
void MoveIran(double m, int x, int y, gTexture1 a[5], gTexture1 iran[5], gTexture1 ball[1])
{
    for (int i = 0; i < 5; i++)
    {
        iran[i].vy = ((iran[i].v) * SinDetermineIran(m, iran, x, y, i));
        iran[i].vx = ((iran[i].v) * CosDetermineIran(m, iran, x, y, i));
        iran[i].ay = ((iran[i].a) * SinDetermineIran(m, iran, x, y, i));
        iran[i].ax = ((iran[i].a) * CosDetermineIran(m, iran, x, y, i));
        iran[i].t = 0;
    }
    for (int i = 0; i < 5; i++)
    {

        //  m = (double(y) - iran[i].y - 25.0) / (double(x) - iran[i].x - 25.0);
        //  cout <<"m="<<m<<endl;

        //   cout<<"m="<<m<<endl;
        //   cout << "i" << i << endl;

        /*   cout << "i=" << i << "\t"
             << "mmmmmmmmmmmmmmm=" << m << endl;
        cout << "x=" << x << "y=" << y << endl;
        cout << "Cosdetermin" << CosDetermineIran(m, iran, x, y, i) << endl;
        cout << "sinjkfdks" << SinDetermineIran(m, iran, x, y, i) << endl;*/
        iran[i].vy = ((iran[i].v) * SinDetermineIran(m, iran, x, y, i));
        iran[i].vx = ((iran[i].v) * CosDetermineIran(m, iran, x, y, i));
        iran[i].ay = ((iran[i].a) * SinDetermineIran(m, iran, x, y, i));
        iran[i].ax = ((iran[i].a) * CosDetermineIran(m, iran, x, y, i));
        // cout << "a[i].vy=" << a[i].vy << "\ta[i].vx=" << a[i].vx /*<<"\t"<< a[i].ay<<"\t" << a[i].ax << endl;
        // cout << SinDetermineA(m, a, x, y, i) << "\t" << CosDetermineA(m, a, x, y, i) << endl;
        iran[i].vx1 = iran[i].vx;
        iran[i].vy1 = iran[i].vy;
        iran[i].x1 = iran[i].x;
        iran[i].y1 = iran[i].y;
        //   cout<<"x1="<<x1<<endl;

        while ((abs(iran[i].vx)) > 0.5 || abs(iran[i].vy) > 0.5)
        //   while (((a[i].vx * a[i].vx) + (a[i].vy
        //   while (((a[i].vx * a[i].vx) + (a[i].vy
        {
            for (int j = 0; j < 5; j++)
            //   while (((a[i].vx * a[i].vx) + (a[i].vy * a[i].vy)) >= 0. - 1)
            {
                if ((abs(iran[j].vx)) > 0.5 || abs(iran[j].vy) > 0.5)
                {
                    //     cout << "sin=" << SinDetermineIran(m, a, x, y, i) << endl;
                    //    cout << "cos=" << CosDetermineIran(m, a, x, y, i) << endl;
                    // cout << "a[i].ax=" << a[i].ax << "a[i].ay=" << a[i].ay << endl;
                    //        cout << "a[i].vx=" << iran[i].vx << endl;
                    //   cout << "i=" << i << endl;
                    iran[j].x = (((0.5) * (iran[j].ax) * iran[j].t * iran[j].t) + (iran[j].vx1 * iran[j].t) + iran[j].x1);
                    //   cout << ".a[i].x=" << a[i].x << endl;
                    //   cout << ".a[i].y=" << a[i].y <<"t="<<t<<"a[i].ay="<<a[i].ay<<"vy1="<<vy1<< endl;
                    iran[j].y = (((0.5) * (iran[j].ay) * iran[j].t * iran[j].t) + (iran[j].vy1 * iran[j].t) + iran[j].y1);
                    //   cout << "a[i].vx=" << iran[i].vx << endl;
                    iran[j].vx = (iran[j].ax * iran[j].t) + iran[j].vx1;
                    iran[j].vy = (iran[j].ay * iran[j].t) + iran[j].vy1;
                    cout << "a[i].vx=" << iran[j].vx << endl;
                    showmap(a, iran, ball);
                    SDL_RenderPresent(gRenderer);
                    barkhord(iran, a, ball, j);

                    iran[j].t += 0.001;
                    /*    if (abs(iran[i].vx) < 0.5)
                    break;
                if (abs(iran[i].vy) < 0.5)
                    break;*/
                    SDL_RenderClear(gRenderer);
                }
            }
        }
    }
    for (int i = 0; i < 5; i++)
        iran[i].v = 0;
}

int main()
{
    int r = 0;
    int x, y;
    bool flag = false;
    bool flag2 = true;
    int turn = 2;
    gTexture1 ball[1];
    gTexture1 a[5];
    gTexture1 iran[5];
    ball[0].gTextureball = NULL;
    ball[0].a = -4;
    for (int i = 0; i < 5; i++)
    {
        a[i].a = -6;
        iran[i].a = -6;
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
            double m = 0;
            while (!quit)
            {
                SDL_GetMouseState(&x, &y);
                //  cout << "x=" << x << "y=" << y << endl;
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

                        MoveIran((m), x, y, a, iran, ball);
                        int r = 0;
                        double z = 0;
                        if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP)
                        {
                            if (e.type == SDL_QUIT)
                            {
                                quit = true;
                            }
                            {
                                if (e.type == SDL_QUIT)
                                {
                                    quit = true;
                                }
                                SDL_GetMouseState(&x, &y);
                                {
                                    for (int i = 0; i < 5; i++)
                                    {
                                        if (((x - a[i].x - 25) * (x - a[i].x - 25)) + ((y - a[i].y - 25) * (y - a[i].y - 25)) < 625)
                                        {
                                            r = i;
                                            bool flag = false;
                                            if (e.type == SDL_MOUSEBUTTONDOWN)
                                            {
                                                flag = true;

                                                while (flag)
                                                {
                                                    for (int j = 0; j < 5; j++)
                                                    {
                                                        cout << "a[i].vx" << a[i].v << endl;
                                                    }
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
                        cout << "ghfjlkdsflsjkgjkjsdfk" << a[2].v << endl;
                        MoveA((m), x, y, a, iran, ball);
                        double z = 0;
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
                                                    //                                          m *= (-1);
                                                }

                                                if (flag == false)
                                                {
                                                    cout << "a[i].x=" << a[i].x << "a[i].y=" << a[i].y << endl;
                                                    cout << "x=" << x << "y=" << y << endl;
                                                    cout << "mmmmmmmmmmmmmmm22222222222=" << m << endl;
                                                    cout << "i=" << i << endl;
                                                    cout << "mainCosdetermin" << CosDetermineIran(m, iran, x, y, i) << endl;
                                                    cout << "mainsinjkfdks" << SinDetermineIran(m, iran, x, y, i) << endl;
                                                }
                                                drawlineiran(iran, m, z, i, x, y);
                                                SDL_RenderPresent(gRenderer);
                                                SDL_RenderClear(gRenderer);

                                                cout << "a[i].x=" << a[i].x << "a[i].y=" << a[i].y << endl;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    //      turn++;
                }
            }
        }
    }
    close(a, iran, ball);
    return 0;
}