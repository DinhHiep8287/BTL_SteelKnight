#include "Character.h"
using namespace std;
// tất cả các Object character là kế thừa từ class Object
// cứ pháp kế thừa :
// class DuocKeThua : accessMode(public,private,...) KeThua
// 1 Constructor có thể được ghi đè trong 1 class kế thừa bằng cứ pháp 
// DuocKeThua( type st , stNew ) : KeThua (st)
// Trong trường hợp này MainCharacter mình sẽ tạo 1 contructor được đè từ class Object
Knight::Knight(All* all ) : Object(all)
{
    int health = 100;
    animation = new Animation(all->id, all->flip, 0, 100, 10, 0);
    hitBox = new HitBox();
    hitBox->setClip(-125 , -100 , 250 , 225);
    hitBox->setHitBox(all->x , all->y , all->width, all->height );

    isGround = true; 
    IsJumping = false;
    body = new Body();
    // Đặt điểm tâm của player
    point->x = hitBox->_hitBox.x + hitBox->_hitBox.w / 2 ;
    point->y = (hitBox->_hitBox.y + hitBox->_hitBox.h / 2);
}

bool Knight::attackEnermy(Enermy* enermy, float dir)
{
    if (dir == 0) {
        if (CheckCollision(hitBox->_hitBox, enermy->hitBox->_hitBox) || CheckCollision(hitBox->_attackHitBoxRight, enermy->hitBox->_hitBox))
        {
            //cout << " va cham phai " << endl  ;
            return true;
        }
        else return false;
    }
    if (dir == 1) {
        if (CheckCollision(hitBox->_hitBox, enermy->hitBox->_hitBox) || CheckCollision(hitBox->_attackHitBoxLeft, enermy->hitBox->_hitBox))
        {
            //cout << " va cham trai " <<endl ;
            return true;
        }
        else return false;
    }
}

void Knight::drawObject( Animation* animation )
{
    animation->DrawAnimation( animation->id , O_tranform->vector.x , O_tranform->vector.y , O_width, O_height, animation->flip);
    //SDL_SetRenderDrawColor(Game::GetInstance()->renderer, 255, 255, 255, 255);
    //TextureManage::GetInstance()->drawHitbox(&hitBox->_hitBox, Game::GetInstance()->renderer);
    //TextureManage::GetInstance()->drawHitbox(&hitBox->_attackHitBoxLeft, Game::GetInstance()->renderer);
    //TextureManage::GetInstance()->drawHitbox(&hitBox->_attackHitBoxRight, Game::GetInstance()->renderer);
}
void Knight::updateObject(float dt , Enermy* enermy)
{
    int lastY = O_tranform->vector.y;
    // Animation khi nhận dame
    if (isTakeHit )
    {
        if (dir == 0) {
            animation->SetAnimation("KnightTakeHit", SDL_FLIP_NONE, 0, 10, 4, 0);
            O_width = TextureManage::GetInstance()->textureWidth("KnightTakeHit") / animation->frameCount;
            O_height = TextureManage::GetInstance()->textureHeight("KnightTakeHit");
        }
        if (dir == 1)
        {
            animation->SetAnimation("KnightTakeHit", SDL_FLIP_HORIZONTAL, 0, 10, 4, 0);
            O_width = TextureManage::GetInstance()->textureWidth("KnightTakeHit") / animation->frameCount;
            O_height = TextureManage::GetInstance()->textureHeight("KnightTakeHit");
        }
    }

    // Animation khi rơi
    if (isFalling && !IsJumping && !isAttacking && !isTakeHit)
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
    // Animation khi nhảy
    if (IsJumping && !isFalling && !isAttacking && !isTakeHit)
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
    if (dir == 0 && !IsJumping && !isFalling && !isAttacking && !isTakeHit) {
        animation->SetAnimation("KnightIdle", SDL_FLIP_NONE, 0, 80, 11, 0);
        O_width = TextureManage::GetInstance()->textureWidth("KnightIdle") / animation->frameCount;
        O_height = TextureManage::GetInstance()->textureHeight("KnightIdle");
    }
    if (dir == 1 && !IsJumping && !isFalling && !isAttacking && !isTakeHit)
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
    if (Input::getInstance()->getKeyDown(SDL_SCANCODE_A) && !isAttacking && !isTakeHit)
    {
        body->setForceX(-dt*30);
        if (!IsJumping && !isFalling) {
            animation->SetAnimation("KnightRun", SDL_FLIP_HORIZONTAL, 0, 100, 8, 0);
            O_width = TextureManage::GetInstance()->textureWidth("KnightRun") / animation->frameCount;
            O_height = TextureManage::GetInstance()->textureHeight("KnightRun");
        }
        dir = 1;
    }
    if (Input::getInstance()->getKeyDown(SDL_SCANCODE_D) && !isAttacking && !isTakeHit)
    {
        body->setForceX(dt*30);
        if (!IsJumping && !isFalling) {
            animation->SetAnimation("KnightRun", SDL_FLIP_NONE, 0, 100, 8, 0);
            O_width = TextureManage::GetInstance()->textureWidth("KnightRun") / animation->frameCount;
            O_height = TextureManage::GetInstance()->textureHeight("KnightRun");
        }
        dir = 0;
    }
    // Đánh

    if (Input::getInstance()->getKeyDown(SDL_SCANCODE_J) && isGround && !isTakeHit)
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
        if (_attackTime == 1 && attackEnermy(enermy, dir))
        {
            enermy->health -= 5;
            enermy->isTakeHit = true;
        }
        else enermy->isTakeHit = false;
    }
    else
    {
        _attackTime = attackTime;
        isAttacking = false;
    }
    
    
    // Nhảy
    if (Input::getInstance()->getKeyDown(SDL_SCANCODE_W) && isGround && CollisionUp(hitBox->_hitBox) == false && hitBox->_hitBox.y > 0 )
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
    body->setGra(dt*30);
    body->Update(dt);
    LastSafePos.x = O_tranform->vector.x; 
    O_tranform-> moveX(body->_position.x);
    // Va chạm x
    hitBox->setHitBox(O_tranform->vector.x, O_tranform->vector.y, O_width, O_height);

    if (CollisionMap(hitBox->_hitBox) || CheckCollision(hitBox->_hitBox , enermy->hitBox->_hitBox))
    {
        O_tranform->vector.x = LastSafePos.x;
    }

     //Va chạm y
    LastSafePos.y = O_tranform->vector.y;
    O_tranform->moveY(body->_position.y);
    hitBox->setHitBox(O_tranform->vector.x, O_tranform->vector.y, O_width, O_height);

    // Rơi xuống vực 
    if (CollisionMap(hitBox->_hitBox) && hitBox->_hitBox.y == 845)
    {
        health -= 100;
    }

    if (CollisionMap(hitBox->_hitBox) || CheckCollision(hitBox->_hitBox, enermy->hitBox->_hitBox))
    {
        IsJumping = false;
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
    //cout << body->_position.y << "  ";
    //if (body->_position.y != 0) isFalling = true;
    //else isFalling = false;
    //cout << health<< " " << isTakeHit << endl;
    //cout << _attackTime << endl;
    //attackEnermy(enermy, dir);

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
    // Kéo tâm của nhân vật xuống để khi render khi tọa độ của nhân vật ở dưới cùng map sẽ không bị lộ tile
    point->y = (hitBox->_hitBox.y + hitBox->_hitBox.h / 2) * 0.78 ;
}
void Knight::cleanObject(SDL_Texture* texture)
{
    SDL_DestroyTexture(texture);
}


bool Enermy::attackPlayer(Knight* player, int dir)
{
    //cout << AttackTime << " ";
    if (dir == 1) {
        if (CheckCollision(hitBox->_hitBox, player->hitBox->_hitBox) || CheckCollision(hitBox->_attackHitBoxRight, player->hitBox->_hitBox))
        {
            body->unSetForce();
            //AttackTime -= 1;
            /*if (AttackTime == 1)
            {
                player->health -= 5;
                AttackTime = ENERMYATTACKTIME;
            }
            else {
            }*/
            return true;
        }
        else return false;
    }
    if (dir == -1) {
        if (CheckCollision(hitBox->_hitBox, player->hitBox->_hitBox) || CheckCollision(hitBox->_attackHitBoxLeft, player->hitBox->_hitBox))
        {
            body->unSetForce();
            //AttackTime -= 1;
            //if (AttackTime == 1 )
            //{
            //    //cout << "dang tan cong " << endl;
            //    player->health -= 5;
            //    AttackTime = ENERMYATTACKTIME;
            //}
            //else
            //{
            //    //cout << " khong tan cong " << endl;
            //    //player->isTakeHit = false;
            //}
            return true;
        }
        else return false;
    }
}

void Enermy::updateEnermy(float dt , Knight* player , vector<string> MonsterData , vector<int> MonsterData1)
{
    //DEBUG
    //cout << attackPlayer(player, dir) << endl;;
    //cout << player->health << endl;
    //cout << player->isTakeHit << endl;
    //cout << health << endl;
    //cout << isTakeHit;
    //hitBox->printHitbox(" Enermy ");
    //player->hitBox->printHitbox(" player ");
    // Khi quái phát hiện nhân vật
    if ( abs(player->hitBox->_hitBox.y - hitBox->_hitBox.y) < 10)
    {
        if ( (player->hitBox->_hitBox.x + player->hitBox->_hitBox.w / 2 - hitBox->_hitBox.x + hitBox->_hitBox.w))
        {
            dir = -1;
        }
        if (player->hitBox->_hitBox.x + player->hitBox->_hitBox.w / 2 > hitBox->_hitBox.x + hitBox->_hitBox.w)
        {
            dir = 1;
        }
    }
    // Khi Quái bị tấn công

    if (dir == 1 && isTakeHit)
    {
        animation->SetAnimation(MonsterData[2], SDL_FLIP_NONE, 0, 30, MonsterData1[2], 0);
        O_width = TextureManage::GetInstance()->textureWidth(MonsterData[2]) / MonsterData1[2];
        O_height = TextureManage::GetInstance()->textureHeight(MonsterData[2]);
    }

    if (dir == -1 && isTakeHit)
    {
        animation->SetAnimation(MonsterData[2], SDL_FLIP_HORIZONTAL, 0, 30, MonsterData1[2], 0);
        O_width = TextureManage::GetInstance()->textureWidth(MonsterData[2]) / MonsterData1[2];
        O_height = TextureManage::GetInstance()->textureHeight(MonsterData[2]);
    }

    // Mặc định quái di chuyển trái phải
    if (dir == 1 && !attackPlayer(player,dir) && !isTakeHit ) {
        animation->SetAnimation(MonsterData[0], SDL_FLIP_NONE, 0, 100, MonsterData1[0], 0);
        O_width = TextureManage::GetInstance()->textureWidth(MonsterData[0]) / MonsterData1[0];
        O_height = TextureManage::GetInstance()->textureHeight(MonsterData[0]);
    }
    if (dir == -1 && !attackPlayer(player,dir) && !isTakeHit)
    {
        animation->SetAnimation(MonsterData[0], SDL_FLIP_HORIZONTAL, 0, 100, MonsterData1[0], 0);
        O_width = TextureManage::GetInstance()->textureWidth(MonsterData[0]) / MonsterData1[0];
        O_height = TextureManage::GetInstance()->textureHeight(MonsterData[0]);
    }

    // Khi quái tấn công player
    if (dir == 1 && attackPlayer(player, dir) && !isTakeHit) {
        isAttacking = true;
        animation->SetAnimation(MonsterData[1], SDL_FLIP_NONE, 0, 100, MonsterData1[1], 0);
        O_width = TextureManage::GetInstance()->textureWidth(MonsterData[1]) / MonsterData1[1];
        O_height = TextureManage::GetInstance()->textureHeight(MonsterData[1]);
    }
    if (dir == -1 && attackPlayer(player,dir) && !isTakeHit) {
        isAttacking = true;
        animation->SetAnimation(MonsterData[1], SDL_FLIP_HORIZONTAL, 0, 100, MonsterData1[1], 0);
        O_width = TextureManage::GetInstance()->textureWidth(MonsterData[1]) / MonsterData1[1];
        O_height = TextureManage::GetInstance()->textureHeight(MonsterData[1]);
    }
    if (isAttacking == true && AttackTime > 0)
    {
        AttackTime -= dt;
        if (AttackTime == 1)
        {
            player->health -= 5;
            player->isTakeHit = true;
        }
        else
        {
            player->isTakeHit = false;
        }
    }
    else
    {
        AttackTime = ENERMYATTACKTIME;
        isAttacking = false;
    }


    // Đặt độ rơi
    body->setGra(5);
    if(dir == 1 && !attackPlayer(player,dir) ) body->setForceX(1);
    if (dir == -1 && !attackPlayer(player,dir) ) body->setForceX(-1);
    body->Update(dt);
    LastSafePos.x = O_tranform->vector.x;
    O_tranform->moveX(body->_position.x);
    // Va chạm x
    hitBox->setHitBox(O_tranform->vector.x, O_tranform->vector.y, O_width, O_height,40);

    if (CollisionMap(hitBox->_hitBox))
    {
        O_tranform->vector.x = LastSafePos.x;
    }

    //Va chạm y
    LastSafePos.y = O_tranform->vector.y;
    O_tranform->moveY(body->_position.y);
    hitBox->setHitBox(O_tranform->vector.x, O_tranform->vector.y, O_width, O_height,40);
    if (CollisionMap(hitBox->_hitBox))
    {
        //cout << "vacham";
        O_tranform->vector.y = LastSafePos.y;
    }
    
    if (checkcollisionX(hitBox->_hitBox) )
    {
        dir = dir * -1;
    }
    if (checkEdge(hitBox->_hitBox) )
    {
        dir = dir * -1;
    }
    animation->UpdateAnimation();

    
}

void Enermy::drawEnermy(SDL_Renderer* ren, Animation* animation)
{
    animation->DrawAnimation(animation->id, O_tranform->vector.x, O_tranform->vector.y, O_width, O_height, animation->flip);
    /*TextureManage::GetInstance()->drawHitbox(&hitBox->_hitBox, ren);
    TextureManage::GetInstance()->drawHitbox(&hitBox->_attackHitBoxLeft, Game::GetInstance()->renderer);
    TextureManage::GetInstance()->drawHitbox(&hitBox->_attackHitBoxRight, Game::GetInstance()->renderer);*/
}

void Enermy::cleanEnermy(SDL_Texture* tex)
{
    SDL_DestroyTexture(tex);
}