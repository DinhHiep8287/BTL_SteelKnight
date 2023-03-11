#pragma once
#include "SDL.h"
class HitBox
{
public: SDL_Rect _hitBox; 
        SDL_Rect _clip;
        void setClip(int x, int y, int w, int h)
        {
            _clip.x = x;
            _clip.y = y;
            _clip.w = w;
            _clip.h = h;
        }
        void setHitBox(int x, int y, int w, int h)
        {
            _hitBox.x = x - _clip.x; 
            _hitBox.y = y - _clip.y; 
            _hitBox.w = w - _clip.w;
            _hitBox.h = h - _clip.h;
        }
        void printHitbox()
        {
            cout << "\n Hitbox :  x " << _hitBox.x << " " << _hitBox.x + _hitBox.w << "    y  " <<  _hitBox.y <<"  " << _hitBox.y + _hitBox.h <<  " )   ";
        }

};