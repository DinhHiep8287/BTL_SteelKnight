#include "Game.h"

Game* Game::_instance = nullptr;
level* _level = new level();
layer* layer1 = new layer(); 
Knight* player = new Knight(new All("KnightIdle", 200, 300, TextureManage::GetInstance()->textureWidth("KnightIdle") / 11, TextureManage::GetInstance()->textureHeight("KnightIdle")));
void Game::init()
{
    initSDL(window, renderer);
    layer1->load("LayerData1.txt", TextureManage::GetInstance()->load_texture("Map//mapMaterial//Tiles.png"));
    _level->loadLayerToLevel(layer1);
    TextureManage::GetInstance()->load("WhiteBackground", "Art//Background_0.png");
    TextureManage::GetInstance()->load("KnightIdle", "Art//Knight//idle.png");
    TextureManage::GetInstance()->load("KnightRun", "Art//Knight//Run.png");
    TextureManage::GetInstance()->load("KnightAttack", "Art//Knight//Attack.png");
    
}


void Game::quit()
{
    _isRunning = false;
}

void Game::update()
{
    float dt =  1;  
    player->updateObject(dt);
    player->O_tranform->vector.print(" player : ");
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