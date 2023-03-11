#include "Game.h"
level* _level = new level();
layer* layerCollision = new layer();
Knight* player = new Knight(new All("KnightIdle", 200, 100, TextureManage::GetInstance()->textureWidth("KnightIdle") / 11, TextureManage::GetInstance()->textureHeight("KnightIdle")));
void Game::init()
{
    // Khởi tạo Window + Renderer
    initSDL(window, renderer);
    // Load Layer1 <>
    layerCollision->load("LayerData1.txt", TextureManage::GetInstance()->load_texture("Map//mapMaterial//Tiles.png"));
    _level->loadLayerToLevel(layerCollision);

    // Load đồ họa
    TextureManage::GetInstance()->load("WhiteBackground", "Art//Background_0.png");
    TextureManage::GetInstance()->load("KnightIdle", "Art//Knight//idle.png");
    TextureManage::GetInstance()->load("KnightRun", "Art//Knight//Run.png");
    TextureManage::GetInstance()->load("KnightAttack", "Art//Knight//Attack.png");
    TextureManage::GetInstance()->load("KnightJump", "Art//Knight//Jump.png");
    TextureManage::GetInstance()->load("KnightFall", "Art//Knight//Fall.png");
    
    // Set Camera vào nhân vật
    //Camera::getInstance()->setPoint(player->point);
}

void Game::quit()
{
    _isRunning = false;
}

void Game::update()
{
    float dt =  1;  
    player->updateObject(dt);
   // player->O_tranform->vector.print(" player : ");

    //Camera::getInstance()->update(dt);
}
void Game::render()
{
    SDL_RenderCopy(renderer, TextureManage::GetInstance()->_textureMap["WhiteBackground"], NULL, NULL);
    _level->renderLevel(renderer);
    player->drawObject( player->animation );
    SDL_RenderPresent(renderer);
    
}
void Game::event()
{
    Input::getInstance()->listen();
}
void Game::cleanSDL()
{
    //SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}