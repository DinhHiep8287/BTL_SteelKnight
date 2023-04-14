#pragma once
#include "Animation.h"
#include "Object.h"
#include "HitBox.h"
#include "TileLayer.hpp"
#include "Input.h"
#include "Game.h"
#include "Engine.h"
#include <vector>
using namespace std;
const float jumpTime = 8 ;
const float jumpForce = 34 ;
const float attackTime = 8;
const float DieTime = 45;
const float ENERMYATTACKTIME = 15;
const float RespawnTime = 1000;
class Enermy;
class Knight;
class FullEnermy;
class Knight : public Object
{
public:     int health = 100 ;
            Knight(All* all);
            Animation* animation;
            Body* body ;
            HitBox* hitBox;

            bool vaChamX = false;

            // dir  = 0 là sang phải , dir = 1 là sang trái .
            int dir = 0;
            bool isFalling = true;
            bool isAttacking = false;
            bool IsJumping = true ;
            bool isGround = false ;
            bool isTakeHit = false;
            bool isDead = false;
            float _jumpTime = jumpTime; 
            float _attackTime = attackTime;
            float _dieTime = 50;
            Vector2D LastSafePos ;
            int score = 0 ;
            int bonusScore = 0;
      bool attackEnermy(Enermy* enermy, float dir);
      Enermy* closestEnermy(FullEnermy* fullEnermy);
      void drawObject( Animation* animation );
      void updateObject(float dt , FullEnermy* fullEnermy, vector<vector<int>> layerData1 );
      void cleanObject(SDL_Texture* texture);

      
};

class Enermy : public Object
{
public:
    int health = 30;
    HitBox* hitBox;
    Animation* animation;
    Body* body;
    Vector2D LastSafePos;
    
    float AttackTime = ENERMYATTACKTIME;

    Enermy(All* all) : Object(all)
    {
        int heath = 20;
        body = new Body();
        animation = new Animation(all->id, all->flip, 0, 100, 4, 0);
        hitBox = new HitBox();
        hitBox->setClip(-120, -130, 230, 230);
        hitBox->setHitBox(all->x, all->y, all->width, all->height, 20);
    }
    bool attackPlayer(Knight* player , int dir );
    // dir = 1 là sang phải , dir = -1 là sang trái
    int dir = 1;
    bool isAttacking = false;
    bool isTakeHit = false;
    bool isDead = false;
    float _dieTime = DieTime;
    float _spawnTime = RespawnTime;
    bool chase = false;
    void drawEnermy(SDL_Renderer* ren, Animation* animation , Knight* player );
    void updateEnermy(float dt , Knight* player , vector<string> MonsterData , vector<int> MonsterData1  , vector<vector<int>> layerData1 , vector<Vector2D> spawnPoint);
    void cleanEnermy(SDL_Texture* tex);

};


class FullEnermy
{
public :vector<Enermy*> fullEnermy;

       void loadEnermy(Enermy* enermy)
       {
           fullEnermy.push_back(enermy);
       }

       void drawFullEnermy(SDL_Renderer* ren , Knight* player )
       {
           for (int i = 0; i < fullEnermy.size(); i++)
           {
               fullEnermy[i]->drawEnermy(ren, fullEnermy[i]->animation , player );
           }
       }

       void updateFullEnermy(float dt , Knight* player ,vector<vector<string> >MonsterData , vector<vector<int>> MonsterData1 , vector<vector<int>> layerData1 , vector<Vector2D> spawnPoint)
       {
           for (int i = 0; i < 2; i++)
           {
               fullEnermy[i]->updateEnermy(dt, player ,  MonsterData[0], MonsterData1[0] ,  layerData1 , spawnPoint);
           }
           for (int i = 2; i < 4; i++)
           {
               fullEnermy[i]->updateEnermy(dt, player, MonsterData[1], MonsterData1[1] ,  layerData1 , spawnPoint);
           }
           for (int i = 4; i < 7; i++)
           {
               fullEnermy[i]->updateEnermy(dt, player, MonsterData[2], MonsterData1[2] ,  layerData1 , spawnPoint);
           }
           for (int i = 7; i < 11; i++)
           {
               fullEnermy[i]->updateEnermy(dt, player, MonsterData[3], MonsterData1[3] , layerData1 , spawnPoint);
           }
       }
       void cleanFullEnermy();
};
