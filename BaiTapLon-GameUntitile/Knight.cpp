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
    int _row , _AnimationSpeed  ;
    int _frameCount  , _frame ;
}



void Knight::drawObject(SDL_Renderer* renderer , SDL_Texture* texture)
{
    drawFrame(texture, renderer, O_tranform->vector.x, O_tranform->vector.y, O_width, O_height ,_row , _frame);
}

void Knight::updateObject()
{
    _frame = (SDL_GetTicks() / _AnimationSpeed) % _frameCount;
}

void Knight::cleanObject(SDL_Texture* texture)
{
    SDL_DestroyTexture(texture);
}

