#pragma once
using namespace std;
#include "Vector2D.h"

// class Tranform -> những thay đổi của object

class Transform
{
public: Vector2D vector;
        
      Transform() { vector.x = 0; vector.y = 0; }
      Transform(float _x, float _y)
      {
          vector.x = _x;
          vector.y = _y;
      }

    inline void moveX(float stepX)
    {
        vector.x += stepX;
    }
    inline void moveY(float stepY)
    {
        vector.y += stepY;
    }

};

