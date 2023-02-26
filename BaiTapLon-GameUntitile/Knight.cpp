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
    animationRun = new Animation(all->texture, all->flip, 0, 80, 10, 0);
    body = new Body();
}

void Knight::drawObject(SDL_Renderer* renderer , SDL_Texture* texture)
{
    animationRun->DrawAnimation(renderer, texture, O_tranform->vector.x, O_tranform->vector.y, O_width, O_height);
}

void Knight::updateObject()
{
    body->Update(1); body->setGra(0) ; 
    O_tranform->moveX(body->_position.x);
    O_tranform->moveY(body->_position.y);
    //cout << "ps : " << body->_position.x << " " << body->_position.y << endl;
    animationRun->UpdateAnimation();
    
}

void Knight::cleanObject(SDL_Texture* texture)
{
    SDL_DestroyTexture(texture);
}

