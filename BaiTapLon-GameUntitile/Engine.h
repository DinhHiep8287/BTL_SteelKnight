#pragma once
#include <SDL.h>
#include <iostream>
#include "Game.h"
#include <fstream>
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
SDL_Texture* GetAreaTextrue(SDL_Rect rect, SDL_Texture* source);
// Return True if Collision and Renturn False if NotCollision
bool CollisionMap(SDL_Rect a, vector<vector<int>> check);
bool CollisionUp(SDL_Rect a, vector<vector<int>> check);
bool checkcollisionX(SDL_Rect a, vector<vector<int>> check);
bool checkEdge(SDL_Rect a);
// Return True if Collision and Renturn False if NotCollision
bool CheckCollision(SDL_Rect a, SDL_Rect b); 


