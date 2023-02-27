#include "Game.h"
#include "TextureManage.h" 
Game* Game::_instance = nullptr;

Knight* player = new Knight(new All("KnightIdle", 200, 200, TextureManage::GetInstance()->textureWidth("KnightIdle") / 11, TextureManage::GetInstance()->textureHeight("KnightIdle")));


void Game::init()
{
    initSDL(window, renderer);
    TextureManage::GetInstance()->load("WhiteBackground", "Art//WhiteBackground.png");
    TextureManage::GetInstance()->load("KnightIdle", "Art//Knight//idle.png");
    TextureManage::GetInstance()->load("KnightRun", "Art//Knight//Run.png");

}

void Game::quit()
{
    _isRunning = false;
}

void Game::update()
{
    float dt = Time::getIntance()->getDeltaTime();
    player->updateObject(dt);
    player->O_tranform->vector.print(" player : ");
    cout << "update...";
}
void Game::render()
{
    SDL_RenderCopy(renderer, TextureManage::GetInstance()->_textureMap["WhiteBackground"], NULL, NULL);
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