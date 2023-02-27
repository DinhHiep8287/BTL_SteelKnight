#pragma once
#include "MainCharacter.h"
#include "Animation.h"
using namespace std;

class Knight : public MainCharacter
{
public :    Knight(All* all);
            Animation* animation;
            Body* body ;

      void drawObject( Animation* animation );
      void updateObject(float dt);
      void cleanObject(SDL_Texture* texture);
};

