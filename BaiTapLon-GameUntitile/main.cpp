using namespace std;
#include "Game.h"
SDL_Event e;
time_t t;
TextureManage* TextureManage::_instance = nullptr;
Input* Input::_intance = nullptr;
Game* Game::_instance = nullptr;
Camera* Camera::instance = nullptr;

int main(int argc, char* argv[])
{
    srand((unsigned)time(&t));
    // KHỞI TẠO
    Game::GetInstance()->init();
    // GAMELOOP
    while (Game::GetInstance()->isRunning())
    {
        Game::GetInstance()->event();
        Game::GetInstance()->update();
        Game::GetInstance()->render();
    }
    // THOÁT
    Game::GetInstance()->cleanSDL();

	return 0;
}