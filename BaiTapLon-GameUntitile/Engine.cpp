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
using namespace std;
const int SIZE = 25;
const int SCREEN_WIDTH = 1250; //32 * SIZE;
const int SCREEN_HEIGHT = 732; //16 * SIZE;
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

SDL_Texture* loadTexture(std::string path, SDL_Renderer* renderer)
{
    SDL_Texture* newTexture = NULL;
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }
    else
    {
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if (newTexture == NULL)
        {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }
        SDL_FreeSurface(loadedSurface);
    }

    return newTexture;
}




void draw(SDL_Texture* texture, SDL_Renderer* renderer, float x, float y, float width , float height, SDL_RendererFlip flip)
{
    SDL_Rect srcrect = { 0 , 0 , width , height };
    SDL_Rect dstrect = { x , y , width , height };
    SDL_RenderCopyEx(renderer, texture, &srcrect, &dstrect, 0, NULL, flip);
}
// Vẽ từng khung hình của một Sprite 
void drawFrame(SDL_Texture* texture, SDL_Renderer* renderer, float x, float y, float width, float height, int row , int frame , SDL_RendererFlip flip )
{
    // Tọa độ của 1 source frame sẽ được xác định bởi x = Chiều Dài 1 frame * thứ tự frame ; y = Chiều cao 1 frame * thứ tự cột
    SDL_Rect srcrect = { width*frame , height*row , width , height };
    SDL_Rect dstrect = { x , y , width , height };
    SDL_RenderCopyEx(renderer, texture, &srcrect, &dstrect, 0, NULL, flip);
}