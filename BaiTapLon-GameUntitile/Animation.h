#pragma once
#include "Engine.h"

class Animation
{   
public: SDL_Texture* texture ; 
      SDL_RendererFlip flip  ; 
      int row; 
      int AnimationSpeed; 
      int frameCount; 
      int frame;
    
    Animation(SDL_Texture* _texture, SDL_RendererFlip _flip, int _row, int _AnimationSpeed, int _frameCount, int _frame){
        texture = _texture;
        flip = _flip;
        row = _row;
        AnimationSpeed = _AnimationSpeed;
        frameCount = _frameCount;
        frame = _frame;
    }

    void UpdateAnimation()
    {
        frame = (SDL_GetTicks() / AnimationSpeed) % frameCount;
    }

    void DrawAnimation(SDL_Renderer* renderer, SDL_Texture* texture , float x , float y , int width , int height)
    {
        drawFrame(texture, renderer, x , y  , width , height, row, frame);
        //cout << "draw : " << x << " " << y << endl;
    }
};

