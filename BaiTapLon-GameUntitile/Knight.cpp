#include "Knight.h"
#include "Input.h"
#include "TextureManage.h"
#include "Game.h"
using namespace std;

Knight::Knight(All* all ) : MainCharacter(all)
{
    animation = new Animation(all->id, all->flip, 0, 100, 10, 0);
    hitBox = new HitBox();
    hitBox->setClip(-100 , -80 , 200 , 190);
    hitBox->setHitBox(all->x , all->y , all->width, all->height);
    isGround = true; 
    IsJumping = false;
    body = new Body();
    // Đặt điểm tâm của player
    point->x = hitBox->_hitBox.x + hitBox->_hitBox.w / 2 ;
    point->y = hitBox->_hitBox.y + hitBox->_hitBox.h / 2;


}

void Knight::drawObject( Animation* animation )
{
    animation->DrawAnimation( animation->id , O_tranform->vector.x , O_tranform->vector.y , O_width, O_height, animation->flip);
    SDL_SetRenderDrawColor(Game::GetInstance()->renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(Game::GetInstance()->renderer, &hitBox->_hitBox);
}
void Knight::updateObject(float dt)
{
    //cout << body->_position.y << "  ";
    //if (body->_position.y != 0) isFalling = true;
    //else isFalling = false;

    int lastY = O_tranform->vector.y;
    if (isFalling && !IsJumping)
    {
        if (dir == 0) {
            animation->SetAnimation("KnightFall", SDL_FLIP_NONE, 0, 50, 4, 0);
            O_width = TextureManage::GetInstance()->textureWidth("KnightFall") / animation->frameCount;
            O_height = TextureManage::GetInstance()->textureHeight("KnightFall");
        }
        if (dir == 1)
        {
            animation->SetAnimation("KnightFall", SDL_FLIP_HORIZONTAL, 0, 50, 4, 0);
            O_width = TextureManage::GetInstance()->textureWidth("KnightFall") / animation->frameCount;
            O_height = TextureManage::GetInstance()->textureHeight("KnightFall");

        }
    }
    if (IsJumping && !isFalling)
    {
        if (dir == 0) {
            animation->SetAnimation("KnightJump", SDL_FLIP_NONE, 0, 50, 4, 0);
            O_width = TextureManage::GetInstance()->textureWidth("KnightJump") / animation->frameCount;
            O_height = TextureManage::GetInstance()->textureHeight("KnightJump");
        }
        if (dir == 1)
        {
            animation->SetAnimation("KnightJump",SDL_FLIP_HORIZONTAL, 0, 50, 4, 0);
            O_width = TextureManage::GetInstance()->textureWidth("KnightJump") / animation->frameCount;
            O_height = TextureManage::GetInstance()->textureHeight("KnightJump");

        }
    }
    // Animation khi đứng yên
    if (dir == 0 && !IsJumping && !isFalling && !isAttacking ) {
        animation->SetAnimation("KnightIdle", SDL_FLIP_NONE, 0, 80, 11, 0);
        O_width = TextureManage::GetInstance()->textureWidth("KnightIdle") / animation->frameCount;
        O_height = TextureManage::GetInstance()->textureHeight("KnightIdle");
    }
    if (dir == 1 && !IsJumping && !isFalling )
    {
        animation->SetAnimation("KnightIdle", SDL_FLIP_HORIZONTAL, 0, 80, 11, 0);
        O_width = TextureManage::GetInstance()->textureWidth("KnightIdle") / animation->frameCount;
        O_height = TextureManage::GetInstance()->textureHeight("KnightIdle");
    }

    // Khi ngừng di chuyển thì sẽ ngừng lực 
    body->unSetForce();
    // Di chuyển trái phải


    if (Input::getInstance()->getKeyDown(SDL_SCANCODE_ESCAPE))
    {
        Game::GetInstance()->quit();
    }
    if (Input::getInstance()->getKeyDown(SDL_SCANCODE_A) )
    {
        body->setForceX(-4);
        if (!IsJumping && !isFalling) {
            animation->SetAnimation("KnightRun", SDL_FLIP_HORIZONTAL, 0, 100, 8, 0);
            O_width = TextureManage::GetInstance()->textureWidth("KnightRun") / animation->frameCount;
            O_height = TextureManage::GetInstance()->textureHeight("KnightRun");
        }
        dir = 1;
    }
    if (Input::getInstance()->getKeyDown(SDL_SCANCODE_D))
    {
        body->setForceX(+4);
        if (!IsJumping && !isFalling) {
            animation->SetAnimation("KnightRun", SDL_FLIP_NONE, 0, 100, 8, 0);
            O_width = TextureManage::GetInstance()->textureWidth("KnightRun") / animation->frameCount;
            O_height = TextureManage::GetInstance()->textureHeight("KnightRun");
        }
        dir = 0;
    }
    // Đánh

    if (Input::getInstance()->getKeyDown(SDL_SCANCODE_J) && isGround)
    {
        isAttacking = true;
        body->unSetForce();
        if (dir == 0)
        {
          animation->SetAnimation("KnightAttack", SDL_FLIP_NONE, 0, 60, 6, 0);
            O_width = TextureManage::GetInstance()->textureWidth("KnightAttack") / animation->frameCount;
            O_height = TextureManage::GetInstance()->textureHeight("KnightAttack");
        }
        if (dir == 1)
        {
            animation->SetAnimation("KnightAttack", SDL_FLIP_HORIZONTAL, 0, 60, 6, 0);
            O_width = TextureManage::GetInstance()->textureWidth("KnightAttack") / animation->frameCount;
            O_height = TextureManage::GetInstance()->textureHeight("KnightAttack");
        }
        
    }
    if (isAttacking == true && _attackTime > 0)
    {
        _attackTime -= dt;
    }
    else
    {
        _attackTime = attackTime;
        isAttacking = false;
    }
    

    // Nhảy
    if (Input::getInstance()->getKeyDown(SDL_SCANCODE_W) && isGround == true)
    {
        IsJumping = true;
        isGround = false;
        body->setForceY(-jumpForce);
    }
    if (Input::getInstance()->getKeyDown(SDL_SCANCODE_W) && IsJumping == true && _jumpTime > 0)
    {
        isGround = false;
        _jumpTime -= dt;
        body->setForceY(-jumpForce);
    }
    else {
        
        IsJumping = false;
        _jumpTime = jumpTime; 
    }
    // Đặt độ rơi
    body->setGra(5);
    body->Update(dt);
    LastSafePos.x = O_tranform->vector.x; 
    O_tranform-> moveX(body->_position.x);
    // Va chạm x
    hitBox->setHitBox(O_tranform->vector.x, O_tranform->vector.y, O_width, O_height);

    if (CollisionMap(hitBox->_hitBox))
    {
        O_tranform->vector.x = LastSafePos.x;
    }

     //Va chạm y
    LastSafePos.y = O_tranform->vector.y;
    O_tranform->moveY(body->_position.y);
    hitBox->setHitBox(O_tranform->vector.x, O_tranform->vector.y, O_width, O_height);

    if (CollisionMap(hitBox->_hitBox) )
    {
        isGround = true;
        O_tranform->vector.y = LastSafePos.y;
    }
    else
    {
        isGround = false;
    }
    // DEBUG

    //O_tranform->vector.print(" ");
    //hitBox->printHitbox();
    //cout << "isJumping : " << IsJumping << "   isGround  : " << isGround << endl;
    //cout << "ps : " << body->_position.x << " " << body->_position.y << endl;
    //cout << "  Ground : " << isGround;
    //cout << "  Jump : " << IsJumping;
    //cout << "  Fall : " << isFalling << endl;
    //cout << hitBox->_hitBox.x << "   " << hitBox->_hitBox.y << endl;
    //cout << point->x << " " << point->y << endl;


    // Update chuyển động
    animation->UpdateAnimation();

    // Check xem có đang rơi hay không 
    if (O_tranform->vector.y > lastY)
    {
        isFalling = true;
    }
    else isFalling = false;

    //update Tâm 
    point->x = hitBox->_hitBox.x + hitBox->_hitBox.w / 2;
    point->y = hitBox->_hitBox.y + hitBox->_hitBox.h / 2;
}

void Knight::cleanObject(SDL_Texture* texture)
{
    SDL_DestroyTexture(texture);
}

