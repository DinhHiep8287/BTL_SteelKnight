#pragma once
#include "MainCharacter.h"
#include "Animation.h"
using namespace std;

class Knight : public MainCharacter
{
public :    Knight(All* all);
            Animation* animation;
            Body* body ;

      void drawObject(SDL_Renderer* renderer , Animation* animation );
      void updateObject(bool *isRunning , SDL_Renderer* renderer);
      void cleanObject(SDL_Texture* texture);
};

