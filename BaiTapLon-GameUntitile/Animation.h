#pragma once
#include "SDL.h"
#include "TextureManage.h"
class Animation
{
public: string id;
      SDL_RendererFlip flip;
      int row;
      int AnimationSpeed;
      int frameCount;
      int frame;
      Animation(){}
      Animation(string _id, SDL_RendererFlip _flip, int _row, int _AnimationSpeed, int _frameCount, int _frame) {
          id = _id;
          flip = _flip;
          row = _row;
          AnimationSpeed = _AnimationSpeed;
          frameCount = _frameCount;
          frame = _frame;
      }
      void SetAnimation(string _id, SDL_RendererFlip _flip, int _row, int _AnimationSpeed, int _frameCount, int _frame)
      {
          id = _id;
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

      void DrawAnimation(string id, float x, float y, int width, int height, SDL_RendererFlip flip)
      {
            TextureManage::GetInstance()->drawFrame(id, x , y, width, height,row ,frame , flip);
      }
};
