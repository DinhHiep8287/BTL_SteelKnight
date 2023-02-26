#pragma once
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

void logSDLError(std::ostream& os,
    const std::string& msg, bool fatal = false);

void initSDL(SDL_Window*& window, SDL_Renderer*& renderer);

void quitSDL(SDL_Window* window , SDL_Renderer* renderer);

void waitUntilKeyPressed();
SDL_Texture* loadTexture(std::string path, SDL_Renderer* renderer);
float textureWidth(SDL_Texture* texture);
float textureHeight(SDL_Texture* texture);
void draw(SDL_Texture* texture, SDL_Renderer* renderer, float x, float y, float width, float height, SDL_RendererFlip = SDL_FLIP_NONE);
void drawFrame(SDL_Texture* texture, SDL_Renderer* renderer, float x, float y, float width, float height, int row, int frame, SDL_RendererFlip flip = SDL_FLIP_NONE);

