#pragma once
#include "SDL.h"
class HitBox
{
public: SDL_Rect _hitBox; 
        SDL_Rect _clip;
        SDL_Rect _attackHitBoxLeft;
        SDL_Rect _attackHitBoxRight;
        void setClip(int x, int y, int w, int h)
        {
            _clip.x = x;
            _clip.y = y;
            _clip.w = w;
            _clip.h = h;
        }
        void setHitBox(int x, int y, int w, int h , int AttackWidth = 80)
        {
            _hitBox.x = x - _clip.x; 
            _hitBox.y = y - _clip.y; 
            _hitBox.w = w - _clip.w;
            _hitBox.h = h - _clip.h;

            _attackHitBoxLeft.x = _hitBox.x - AttackWidth;
            _attackHitBoxLeft.y = _hitBox.y;
            _attackHitBoxLeft.w = AttackWidth;
            _attackHitBoxLeft.h = _hitBox.h;

            _attackHitBoxRight.x = _hitBox.x + _hitBox.w;
            _attackHitBoxRight.y = _hitBox.y;
            _attackHitBoxRight.w = AttackWidth;
            _attackHitBoxRight.h = _hitBox.h;
        }
        
        void printHitbox(string target)
        {
            cout << target << " Hitbox x : " << _hitBox.x << " " << _hitBox.x + _hitBox.w << " , y : " << _hitBox.y << "  " << _hitBox.y + _hitBox.h << " )   " << endl;
        }

};