#pragma once
#include "Object.h"

class Animation
{   
public: All* all; int row; int AnimationSpeed; int frameCount; int frame;
    
    Animation(All* _all, int _row, int _AnimationSpeed, int _frameCount, int _frame = 0 )
    {
        all = _all; row = _row; AnimationSpeed = _AnimationSpeed, frameCount = _frameCount, frame = _frame;
    }

    void UpdateAnimation()
    {
        frame = (SDL_GetTicks() / AnimationSpeed) % frameCount;
    }
    void DrawAnimation(SDL_Renderer* renderer, SDL_Texture* texture)
    {
        drawFrame(texture, renderer, all->x, all->y, all->width, all->height, row, frame );
    }
};

