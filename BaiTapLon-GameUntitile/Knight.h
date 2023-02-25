#pragma once
#include "MainCharacter.h"

using namespace std;

class Knight : public MainCharacter
{
public :    Knight(All* all);
      int _row = 0 , _AnimationSpeed = 1000;
      int _frameCount = 10 , _frame;

      void drawObject(SDL_Renderer* renderer, SDL_Texture* texture);
      void updateObject();
      void cleanObject(SDL_Texture* texture);
};

