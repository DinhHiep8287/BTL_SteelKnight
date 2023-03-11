#pragma once
#include "MainCharacter.h"
#include "Animation.h"
#include "HitBox.h"
#include "TileLayer.hpp"
using namespace std;
const float jumpTime = 20 ;
const float jumpForce = 14;
const float attackTime = 1;
class Knight : public MainCharacter
{
public :    Knight(All* all );
            Animation* animation;
            Body* body ;
            HitBox* hitBox;



            int dir = 0;
            bool isFalling = true;
            bool isAttacking = false;
            bool IsJumping = true ;
            bool isGround = false ; 
            float _jumpTime = jumpTime; 
            float _attackTime = attackTime;
            Vector2D LastSafePos ;

      void drawObject( Animation* animation );
      void updateObject(float dt);
      void cleanObject(SDL_Texture* texture);

      
};

