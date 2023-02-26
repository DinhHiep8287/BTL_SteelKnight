#pragma once
#include "MainCharacter.h"
#include "Animation.h"
using namespace std;

class Knight : public MainCharacter
{
public :    Knight(All* all);
            Animation* animationRun;
            Body* body ;

      void drawObject(SDL_Renderer* renderer, SDL_Texture* texture);
      void updateObject();
      void cleanObject(SDL_Texture* texture);
};

