using namespace std;
#include "Game.h"
#include "Engine.h"
const int SCREEN_WIDTH = 32 * SIZE;
const int SCREEN_HEIGHT = 18 * SIZE;
SDL_Event e;
time_t t;


int main(int argc, char* argv[])
{

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