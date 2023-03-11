#include "Engine.h"
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <iostream>
#include <string.h>
#include <ctime> 
#include <cstdlib> 
#include <random>
#include "Game.h"
#include <fstream>
using namespace std;
const int SCREEN_WIDTH = 32 * SIZE;
const int SCREEN_HEIGHT = 18 * SIZE;
const string WINDOW_TITLE = "UntiledGame";
void logSDLError(std::ostream& os,
    const std::string& msg, bool fatal)
{
    os << msg << " Error: " << SDL_GetError() << std::endl;
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}
void initSDL(SDL_Window*& window, SDL_Renderer*& renderer)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logSDLError(std::cout, "SDL_Init", true);
    window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP;
    if (window == nullptr) logSDLError(std::cout, "CreateWindow", true);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
        SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) logSDLError(std::cout, "CreateRenderer", true);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
SDL_Texture* GetAreaTextrue(SDL_Rect rect, SDL_Texture* source)
{
    SDL_Texture* result = SDL_CreateTexture(Game::GetInstance()->renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, rect.w, rect.h);
    SDL_SetRenderTarget(Game::GetInstance()->renderer, result);
    SDL_RenderCopy(Game::GetInstance()->renderer, source, &rect, NULL);
    SDL_SetRenderTarget(Game::GetInstance()->renderer, NULL);
    return result;
}
//bool CheckCollision(SDL_Rect a, SDL_Rect b)
//{
//    bool x_Collision = (a.x + a.w > b.x) || (b.x + b.w > a.x);
//    bool y_Collision = (a.y + a.h > b.y) || (b.y + b.h > a.y);
//    return (x_Collision && y_Collision);
//}
bool CollisionMap(SDL_Rect a)
{
    int tileSize = 32;
    const int X_Count = 32;
    const int Y_Count = 18;
    ifstream map ("LayerData1.txt");
    int check[Y_Count+1][X_Count+1];
    for (int i = 1 ; i <= Y_Count; i++)
    {
        for (int j = 1 ; j <= X_Count; j++)
        { 
            
            map >> check[i][j];
            //cout << check[i][j] << " ";
        }
        //cout << endl;
    }
    int leftTile = a.x / tileSize;
    int rightTile = (a.x + a.w) / tileSize;
    int topTile = a.y / tileSize;
    int botTile = (a.y + a.h) / tileSize;
    if (leftTile < 0) leftTile = 0;
    if (rightTile < 0) rightTile = 0;
    if (topTile < 0) topTile = 0;
    if (botTile < 0) botTile = 0;

    if (a.x <= 0 || a.y <= 0 || a.x + a.w >= SCREEN_WIDTH || a.y + a.h >= SCREEN_HEIGHT)
    {
        return true;
    }

    for (int i = leftTile; i <= rightTile; i++)
    {
        for (int j = topTile; j <= botTile; j++)
        {
            if (check[j][i] > 0)
            {
                //cout << "vacham " << leftTile << " " << rightTile << " " << topTile << " " << botTile << " ";
                return true;
            }
        }
    }

    return false;
}

bool checkcollision(SDL_Rect a, SDL_Rect b)
{
    bool x_collision = (a.x + a.w > b.x) || (b.x + b.w > a.x);
    bool y_collision = (a.y + a.h > b.y) || (b.y + b.h > a.y);
    return (x_collision && y_collision);
}