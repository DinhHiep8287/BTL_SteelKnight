#include "Knight.h"
#include "Engine.h"
#include "Input.h"
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
    animation = new Animation(all->texture, all->flip, 0, 80, 10, 0);
    body = new Body();
}

void Knight::drawObject(SDL_Renderer* renderer , Animation* animation )
{
    animation->DrawAnimation(renderer, animation->texture , O_tranform->vector.x, O_tranform->vector.y, O_width, O_height , animation->flip);
}

void Knight::updateObject(bool *isRunning , SDL_Renderer* renderer)
{
    SDL_Texture* KnightIdie = loadTexture("Art//Knight//idle.png", renderer);
    SDL_Texture* KnightRun = loadTexture("Art//Knight//Run.png", renderer);
    animation->SetAnimation(KnightIdie, SDL_FLIP_NONE, 0, 80, 11, 0);
    O_width = textureWidth(KnightIdie) / animation->frameCount;
    O_height = textureHeight(KnightRun);
    body->unSetForce();
    if (Input::getInstance()->getKeyDown(SDL_SCANCODE_ESCAPE))
    {
        *isRunning = false;
    }
    if (Input::getInstance()->getKeyDown(SDL_SCANCODE_A))
    {
        body->setForceX(-5);
        animation->SetAnimation(KnightRun, SDL_FLIP_HORIZONTAL , 0, 80, 8, 0);
        O_width = textureWidth(KnightRun) / animation->frameCount;
        O_height = textureHeight(KnightRun);
        cout << "push a ";
    }
    if (Input::getInstance()->getKeyDown(SDL_SCANCODE_D))
    {
        body->setForceX(+5);
        animation->SetAnimation(KnightRun, SDL_FLIP_NONE , 0, 80, 8, 0);
        O_width = textureWidth(KnightRun) / animation->frameCount;
        O_height = textureHeight(KnightRun);
        cout << "push d";
    }

    body->Update(1); body->setGra(0) ; 
    O_tranform->moveX(body->_position.x);
    O_tranform->moveY(body->_position.y);
    //cout << "ps : " << body->_position.x << " " << body->_position.y << endl;
    animation->UpdateAnimation();

}

void Knight::cleanObject(SDL_Texture* texture)
{
    SDL_DestroyTexture(texture);
}

