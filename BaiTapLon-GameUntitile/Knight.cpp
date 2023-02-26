#include "Knight.h"
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


Knight::Knight(All* all) : MainCharacter(all)
{
    animationRun = new Animation(all, 0 , 50, 10, 0);
}

void Knight::drawObject(SDL_Renderer* renderer , SDL_Texture* texture)
{
    animationRun->DrawAnimation(renderer, texture);
}

void Knight::updateObject()
{
    animationRun->UpdateAnimation();
}

void Knight::cleanObject(SDL_Texture* texture)
{
    SDL_DestroyTexture(texture);
}

