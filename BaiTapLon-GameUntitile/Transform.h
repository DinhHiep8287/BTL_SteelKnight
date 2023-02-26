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
#include "Vector2D.h"

// class Tranform -> những thay đổi của object

class Transform
{
public: Vector2D vector;
        
      Transform(){}
      Transform(int _x, int _y)
      {
          vector.x = _x;
          vector.y = _y;
      }

    void moveX(int stepX)
    {
        vector.x += stepX;
    }
    void moveY(int stepY)
    {
        vector.y += stepY;
    }

};

