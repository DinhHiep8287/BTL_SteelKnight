#include "Knight.h"
#include "Input.h"
#include "TextureManage.h"
using namespace std;
Knight::Knight(All* all) : MainCharacter(all)
{
    animation = new Animation(all->id, all->flip, 0, 100, 10, 0);
    body = new Body();
}

void Knight::drawObject( Animation* animation )
{
    animation->DrawAnimation( animation->id , O_tranform->vector.x, O_tranform->vector.y, O_width, O_height , animation->flip);
}
int dir = 0;
void Knight::updateObject(float dt)
{
    if (dir == 0) {
        animation->SetAnimation("KnightIdle", SDL_FLIP_NONE, 0, 80, 11, 0);
    }
    if (dir == 1)
    {
        animation->SetAnimation("KnightIdle", SDL_FLIP_HORIZONTAL, 0, 80, 11, 0);
    }
    O_width = TextureManage::GetInstance()->textureWidth("KnightIdle") / animation->frameCount;
    O_height = TextureManage::GetInstance()->textureHeight("KnightIdle");
    body->unSetForce();
    if (Input::getInstance()->getKeyDown(SDL_SCANCODE_ESCAPE))
    {
        Game::GetInstance()->quit();
    }
    if (Input::getInstance()->getKeyDown(SDL_SCANCODE_A))
    {
        body->setForceX(-5);
        animation->SetAnimation("KnightRun", SDL_FLIP_HORIZONTAL , 0, 100, 8, 0);
        O_width = TextureManage::GetInstance()->textureWidth("KnightRun") / animation->frameCount;
        O_height = TextureManage::GetInstance()->textureHeight("KnightRun");
        dir = 1;
    }
    if (Input::getInstance()->getKeyDown(SDL_SCANCODE_D))
    {
        body->setForceX(+5);
        animation->SetAnimation("KnightRun", SDL_FLIP_NONE , 0, 100, 8, 0);
        O_width = TextureManage::GetInstance()->textureWidth("KnightRun") / animation->frameCount;
        O_height = TextureManage::GetInstance()->textureHeight("KnightRun");
        dir = 0;
    }
    if (Input::getInstance()->getKeyDown(SDL_SCANCODE_J))
    {
        if (dir == 0)
        {
            animation->SetAnimation("KnightAttack", SDL_FLIP_NONE, 0, 100, 6, 0);
            O_width = TextureManage::GetInstance()->textureWidth("KnightAttack") / animation->frameCount;
            O_height = TextureManage::GetInstance()->textureHeight("KnightAttack");
        }
        if (dir == 1)
        {
            animation->SetAnimation("KnightAttack", SDL_FLIP_HORIZONTAL, 0, 100, 6, 0);
            O_width = TextureManage::GetInstance()->textureWidth("KnightAttack") / animation->frameCount;
            O_height = TextureManage::GetInstance()->textureHeight("KnightAttack");
        }
    }
    body->Update(dt); body->setGra(0) ; 
    O_tranform->moveX(body->_position.x);
    O_tranform->moveY(body->_position.y);
    //cout << "ps : " << body->_position.x << " " << body->_position.y << endl;
    animation->UpdateAnimation();
}

void Knight::cleanObject(SDL_Texture* texture)
{
    SDL_DestroyTexture(texture);
}

